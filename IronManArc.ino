/**************************************************************************

 **************************************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>   // https://github.com/adafruit/Adafruit_SSD1306
#include "Adafruit_NeoPixel.h"  // https://github.com/adafruit/Adafruit_NeoPixel
#include "StartupLogo.h"
#include "NTPClient.h"  // https://github.com/arduino-libraries/NTPClient
#include <WiFi.h>
#include "Animations.h"
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Arc Configuration
#include "ArcConfigMenu.h"

//////////////////////
// Task handles
TaskHandle_t TaskOLEDHandle;
TaskHandle_t TaskSerialHandle;
TaskHandle_t TaskLEDHandle;
SemaphoreHandle_t xMutex;

// Comment following line if you want to use enhanced version with WS2812 RGB LEDS
// for Arc middle light
//#define USE_BASIC_LEDS

// Uncomment the following if you want to use clock with 12h format instead of 24h
#define USE_12_HOURS_FORMAT

//////////////////////

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_RING_PIN 17
// How many NeoPixels are attached to the Arduino?
#define LED_RING_NB_LEDS 35

// LED Ring color
#define LED_RING_RED 51     //51
#define LED_RING_GREEN 226  //219
#define LED_RING_BLUE 254   //255

// When setting up the NeoPixel library, we tell it how many pixels,
Adafruit_NeoPixel ledRing(LED_RING_NB_LEDS, LED_RING_PIN, NEO_GRB + NEO_KHZ800);

// Animations Object
Animations animations(ledRing);

// if we have to use BASIC BLUE LEDs
#ifdef USE_BASIC_LEDS

// Blue standard LEDs
#define BLUE_LED_1_PIN 25
#define BLUE_LED_2_PIN 26

#else  // Use WS2812 RGB LEDs

#define CENTER_LEDS_PIN 27
#define CENTER_LEDS_NB_LEDS 2
Adafruit_NeoPixel centerLeds(CENTER_LEDS_NB_LEDS, CENTER_LEDS_PIN, NEO_GRB + NEO_KHZ800);

#endif

#define LED_NORMAL_BRIGHTNESS 60  // Adjust it 0 to 255
#define LED_FLASH_BRIGHTNESS 250  // Adjust it 0 to 255


#define TOUCH_SENSOR_PIN 23


// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// ==============================================================================

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOOP_DELAY_MS 200
#define CHANGE_FONT_TOUCH_TIME_MS 600

#define LOGO_HEIGHT 32
#define LOGO_WIDTH 128

// Digits et :
#define DIGIT_WIDTH 29
#define COLON_WIDTH 12

// Animation constants
#define ANIMATION_DELAY 10000
#define BREATHE_ANIMATION_DELAY 20

int previousSeconds;
int touchDuration;
bool colonDisplayed;
bool newHourFlashDone;
bool togglingFont;
unsigned long lastAnimationTime = 0;

// Configuration menu
ArcConfigMenu configMenu;

void setup() {
  Serial.begin(115200);

  // INITIALIZE NeoPixel pixels object and power off LEDs
  ledRing.begin();
  ledRing.clear();
  ledRing.show();

  createTasks();

// --- BASIC LEDS
#ifdef USE_BASIC_LEDS
  pinMode(BLUE_LED_1_PIN, OUTPUT);
  pinMode(BLUE_LED_2_PIN, OUTPUT);
  digitalWrite(BLUE_LED_1_PIN, LOW);
  digitalWrite(BLUE_LED_2_PIN, LOW);
#else
  // Init and power off center
  centerLeds.begin();
  centerLeds.clear();
  centerLeds.show();
#endif

  // Init
  colonDisplayed = true;
  newHourFlashDone = false;
  touchDuration = 0;

  // Init configuration menu
  configMenu.begin(allFonts, timezoneList);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // Logo display
  displayStartupLogo();

  // If configuration is not valid
  if (!configMenu.isConfigFormatValid()) {
    displayTextOnOLED("Invalid config\nUse Serial port\nhttps://t.ly/HvUdV");
  } else  // Configuration is valid
  {
    WiFi.disconnect();

    if (configMenu.getWifiType() == WIFI_TYPE__HOME) {
      // Connection on Wifi network
      WiFi.begin(configMenu.getWifiSSID(), configMenu.getWifiPassword());
    } else  // Enterprise
    {
      WiFi.begin(configMenu.getWifiSSID(), WPA2_AUTH_PEAP, configMenu.getWifiUsername(), configMenu.getWifiUsername(), configMenu.getWifiPassword());  // without CERTIFICATE, RADIUS server EXCEPTION "for old devices" required
    }

    int nbMsLeftToTry = 3000;
    const int nbMsBetweenChecks = 500;
    togglingFont = false;

    // We try to connect for a nbMsLeftToTry milliseconds
    while ((WiFi.status() != WL_CONNECTED) && (nbMsLeftToTry > 0)) {
      delay(nbMsBetweenChecks);
      nbMsLeftToTry -= nbMsBetweenChecks;
    }

    // If we were able to connect on Wifi138
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("WiFi connected");
      Serial.print("IP address set: ");
      Serial.println(WiFi.localIP());  //print LAN IP

      timeClient.begin();


      ledRing.setBrightness(LED_NORMAL_BRIGHTNESS);

      for (int i = 0; i < LED_RING_NB_LEDS; i++) {
        ledRing.setPixelColor(i, ledRing.Color(LED_RING_RED, LED_RING_GREEN, LED_RING_BLUE));
        ledRing.show();
        delay(50);
      }

      ledRingFlashCuckoo();  // white flash

// --- BASIC LEDS
#ifdef USE_BASIC_LEDS
        // switch ON the blue leds
      digitalWrite(BLUE_LED_1_PIN, HIGH);
      digitalWrite(BLUE_LED_2_PIN, HIGH);

#else  // --- WS2812

      for (int i = 0; i < CENTER_LEDS_NB_LEDS; i++) {
        centerLeds.setPixelColor(i, centerLeds.Color(LED_RING_RED, LED_RING_GREEN, LED_RING_BLUE));
      }
      centerLeds.show();

#endif  // ---

      // Touch to toggle font
      pinMode(TOUCH_SENSOR_PIN, INPUT);
    } else {
      displayTextOnOLED("Wifi connect error\nUse Serial port\nhttps://t.ly/HvUdV");
    }
  }
}

void loop() {
  //short retCode = configMenu.handleInput(&WiFi);

  // If wifi is connected
  // if(WiFi.status() == WL_CONNECTED)
  // {
  // // Update the time
  // timeClient.update();

  // ledNormalLight();

  // updateUI();

  //checkForFontToggle();

  //delay(LOOP_DELAY_MS);
  //}
}

// Returns hour in correct range (12h or 24h)
int get12Or24Hour(int hour) {
#ifdef USE_12_HOURS_FORMAT
  int modResult = hour % 12;
  return (modResult == 0) ? 12 : modResult;
#else
  return hour;
#endif
}

// Update clock display on OLED
// Returns true|false to tell if it's a new hour
bool updateOLEDClockDisplay() {
  char timeStr[5];
  // Get time in current defined timezone
  time_t currentTime = configMenu.getTimezoneInfos().timezone.toLocal(timeClient.getEpochTime());

  int nextCharOffset = 0;  // offset for next character to draw
  int curOffset;           // x Offset to draw bitmaps
  char curChar;            // current character to draw

  // For colon anim between hours and minutes
  if(second(currentTime) != previousSeconds)
  {
    previousSeconds = second(currentTime);
    if(configMenu.doesColonHaveToBlink())
    {
      colonDisplayed = !colonDisplayed;
    }
    else
    {
      // We do this in case of option is changed while colon is hidden, to make it appears again and stay
      colonDisplayed = true;
    }
  }
  // defining string to display
  sprintf(timeStr, "%.2d%s%.2d", get12Or24Hour(hour(currentTime)), ((colonDisplayed) ? ":" : " "), minute(currentTime));

  //Displaying time
  display.clearDisplay();

  // Looping through characters composing time to display
  for(int i = 0; i < 5; i++)
  {
    curChar = timeStr[i];
    curOffset = nextCharOffset;

    // If we have to display char between hours and minutes
    if(curChar == ':' || curChar == ' ')
    {
      nextCharOffset += COLON_WIDTH;
      display.drawBitmap(curOffset, 0, configMenu.getFontInfos().colonOrNot[(curChar == ' ') ? withoutColon : withColon], COLON_WIDTH, SCREEN_HEIGHT, 1);
    }
    else  // we have to display a digit
    {
      nextCharOffset += DIGIT_WIDTH;
      // Displaying digit by pointing on it in 'all digits bitmap array' by it index (corresponding to the number we have to display. number 0 => index 0 in array)
      //display.drawBitmap(curOffset, 0, allAvengerDigits[String(timeStr[i]).toInt()], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
      display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[String(timeStr[i]).toInt()], DIGIT_WIDTH, SCREEN_HEIGHT, 1);

    }
  }

  display.display();

  return minute(currentTime) == 0;
}

/*
  Displays startup logo
*/
void displayStartupLogo() {
  display.clearDisplay();

  display.drawBitmap(
    (display.width() - LOGO_WIDTH) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    starkIndustriesLogo, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(2000);
}


/*
  Displays given text on OLED screen
*/
void displayTextOnOLED(String text) {
  //display.clearDisplay();
  // display.setTextSize(1);               // Normal 1:1 pixel scale
  // display.setTextColor(SSD1306_WHITE);  // Draw white text
  // display.setCursor(0, 0);              // Start at top-left corner
  // for (int i = 0; i < text.length(); i++)
  // {
  //   display.write(char(text[i]));
  // }
  // display.display();  // Show initial text
}


void ledNormalLight() {

  ledRing.clear();
  ledRing.setBrightness(LED_NORMAL_BRIGHTNESS);
  for (int i = 0; i < LED_RING_NB_LEDS; i++) {
    ledRing.setPixelColor(i, ledRing.Color(LED_RING_RED, LED_RING_GREEN, LED_RING_BLUE));
  }

// --- WS2812 Center LEDS
#ifndef USE_BASIC_LEDS
  centerLeds.clear();
  centerLeds.setBrightness(LED_NORMAL_BRIGHTNESS);
  for (int i = 0; i < CENTER_LEDS_NB_LEDS; i++) {
    centerLeds.setPixelColor(i, centerLeds.Color(LED_RING_RED, LED_RING_GREEN, LED_RING_BLUE));
  }
  centerLeds.show();
#endif

  ledRing.show();
}

/*
  LEDs flashes white to do a Cuckoo!
*/
void ledRingFlashCuckoo() {
  // Set full brighness and almost white
  ledRing.setBrightness(LED_FLASH_BRIGHTNESS);
  for (int i = 0; i < LED_RING_NB_LEDS; i++) {
    ledRing.setPixelColor(i, ledRing.Color(250, 250, 250));
  }

// --- WS2812 Center LEDS
#ifndef USE_BASIC_LEDS
  for (int i = 0; i < CENTER_LEDS_NB_LEDS; i++) {
    centerLeds.setPixelColor(i, centerLeds.Color(250, 250, 250));
  }
  centerLeds.show();
#endif

  ledRing.show();

  // Fade out LEDs brightness to almost shutdown them
  for (int i = LED_FLASH_BRIGHTNESS; i > 10; i--) {
    ledRing.setBrightness(i);
    ledRing.show();

// --- WS2812 Center LEDS
#ifndef USE_BASIC_LEDS
    centerLeds.setBrightness(i);
    centerLeds.show();
#endif

    delay(7);
  }
  // Display normal brightness again
  ledNormalLight();
}

void createTasks() {
  xTaskCreate(TaskOLED, "TaskOLED", 8192, NULL, 1, &TaskOLEDHandle);
  xTaskCreate(TaskSerial, "TaskSerial", 8192, NULL, 1, &TaskSerialHandle);
  xTaskCreate(TaskLED, "TaskLED", 8192, NULL, 1, &TaskLEDHandle);
  xMutex = xSemaphoreCreateMutex();
  if (xMutex == NULL) {
    Serial.println(F("Mutex creation failed"));
    for (;;)
      ;  // Don't proceed if there's an error
  }
}

// void updateUI()
// {
//   updateClockDisplay();
//   playAnimation();
//   //OLEDCharacterTest();
// }
void playAnimation() {
  if (millis() - lastAnimationTime >= ANIMATION_DELAY) {
    ledRingFlashCuckoo();
    animations.spinColorWheel(10, 25);  // Spin the color wheel 10 times at 50ms per frame
    animations.breatheAnimation(20, ledRing.Color(LED_RING_RED, LED_RING_GREEN, LED_RING_BLUE));
    //displayString("BIG DADDY T", 1000, 60);
    lastAnimationTime = millis();
  }
}

void updateLeds() {
  playAnimation();
  if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
  //displayString("BIG DADDY T", 1000, 60);
  //displayStartupLogo();
  }
}

void TaskLED(void *pvParameters) {
  (void)pvParameters;
  for (;;) {
    playAnimation();
    vTaskDelay(200 / portTICK_PERIOD_MS);  // Delay for 200 milliseconds
  }
}

void updateClockDisplay() {
  bool isNewHour = updateOLEDClockDisplay(); // Check if it's a new hour
  if (isNewHour && !newHourFlashDone) {
      newHourFlashDone = true;
      ledRingFlashCuckoo(); // Play the cuckoo animation
  }
  if (!isNewHour && newHourFlashDone) {
      newHourFlashDone = false;
  }
}

void updateOLED()
{
    if (WiFi.status() == WL_CONNECTED) {
      timeClient.update();
    }
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
       //updateClockDisplay();
       xSemaphoreGive(xMutex);
    }
}

void TaskOLED(void *pvParameters) {
  (void)pvParameters;
  for (;;) {
    //updateOLEDClockDisplay();
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
  }
}

void TaskSerial(void *pvParameters) {
  (void)pvParameters;
  for (;;) {
    short retCode = configMenu.handleInput(&WiFi);
    vTaskDelay(5000 / portTICK_PERIOD_MS);  // Delay for 1 second
  }
}

void checkForFontToggle() {
  // If toggle font has been requested and we're not currently toggling font..
  if (digitalRead(TOUCH_SENSOR_PIN) == HIGH && !togglingFont) {
    // If touch sensor is touched for CHANGE_FONT_TOUCH_TIME_MS time
    if (touchDuration >= CHANGE_FONT_TOUCH_TIME_MS) {
      togglingFont = true;
      configMenu.toggleFont();
      touchDuration = 0;
    } else  // Not touch long enough
    {
      touchDuration += LOOP_DELAY_MS;
    }
  }
  // toggle font touch sensor has been released
  if (digitalRead(TOUCH_SENSOR_PIN) == LOW) {
    togglingFont = false;
    touchDuration = 0;
  }
}

void scrollTextOnOLED(String text, int speed) {
  Serial.println("Scrolling text on OLED");

  int textWidth = text.length() * 6;  // Assuming each character is 6 pixels wide
  int displayWidth = 128;             // Width of your OLED display

  for (int position = displayWidth; position >= -textWidth; position--) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(position, 0);

    for (int i = 0; i < text.length(); i++) {
      display.write(char(text[i]));
    }

    display.display();
    delay(speed);
  }

  Serial.println("Finished scrolling");
}

void OLEDCharacterTest() {
  displayString("BIG DADDY T", 3, 50);
  //displayCharacter();
}

void displayCharacter() {
  display.clearDisplay();
  display.drawBitmap(0, 0, configMenu.getFontInfos().allDigits[21], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
  display.display();
}

void displayString(const char *str, int pause, int speed) {
  int nextCharOffset = 0;
  int curOffset;
  char curChar;

  display.clearDisplay();

  // // Display the string initially
  // for(int i = 0; str[i] != '\0'; i++) {
  //   curChar = str[i];

  //   curOffset = nextCharOffset;

  //   if(curChar >= '0' && curChar <= '9') {
  //     nextCharOffset += DIGIT_WIDTH; // Adjust according to bitmap width
  //     display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[curChar - '0'], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
  //   } else if(curChar >= 'A' && curChar <= 'J') {
  //     nextCharOffset += DIGIT_WIDTH; // Adjust according to bitmap width
  //     display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[curChar - 'A' + 10], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
  //   } else if(curChar == 'T') {
  //     nextCharOffset += DIGIT_WIDTH; // Adjust according to bitmap width
  //     display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[curChar - 'T' + 20], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
  //   }
  //   else if(curChar == 'Y') {
  //     nextCharOffset += DIGIT_WIDTH; // Adjust according to bitmap width
  //     display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[22], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
  //   } else if(curChar == ' ') {
  //     nextCharOffset += DIGIT_WIDTH; // Adjust according to space width
  //     display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[21], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
  //   }
  // }

  // display.display();

  // // Pause for the specified amount of time
  // delay(pause * 1000);

  // Scroll the string
  int totalLength = strlen(str) * DIGIT_WIDTH;

  Serial.print("String length: ");
  Serial.println(totalLength);

  for (int offset = 0; offset < totalLength + SCREEN_WIDTH; offset += 14) {
    display.clearDisplay();
    nextCharOffset = SCREEN_WIDTH - offset;  // Initial offset for scrolling

    for (int i = 0; str[i] != '\0'; i++) {
      curChar = str[i];
      curOffset = nextCharOffset;

      if (curChar >= '0' && curChar <= '9') {
        nextCharOffset += DIGIT_WIDTH;                     // Adjust according to bitmap width
        if (curOffset >= 0 && curOffset < SCREEN_WIDTH) {  // Only draw if within screen bounds
          display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[curChar - '0'], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
        }
      } else if (curChar >= 'A' && curChar <= 'J') {
        nextCharOffset += DIGIT_WIDTH;                     // Adjust according to bitmap width
        if (curOffset >= 0 && curOffset < SCREEN_WIDTH) {  // Only draw if within screen bounds
          display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[curChar - 'A' + 10], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
        }
      } else if (curChar == 'T') {
        nextCharOffset += DIGIT_WIDTH;                     // Adjust according to bitmap width
        if (curOffset >= 0 && curOffset < SCREEN_WIDTH) {  // Only draw if within screen bounds
          display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[curChar - 'T' + 20], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
        }
      } else if (curChar == 'Y') {
        nextCharOffset += DIGIT_WIDTH;                     // Adjust according to bitmap width
        if (curOffset >= 0 && curOffset < SCREEN_WIDTH) {  // Only draw if within screen bounds
          display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[22], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
        }
      } else if (curChar == ' ') {
        nextCharOffset += DIGIT_WIDTH;                     // Adjust according to space width
        if (curOffset >= 0 && curOffset < SCREEN_WIDTH) {  // Only draw if within screen bounds
          display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[21], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
        }
      }
    }

    display.display();
    delay(speed);  // Delay to control scroll speed
  }
}