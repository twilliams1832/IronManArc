#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <Adafruit_NeoPixel.h>

class Animations {
public:
    Animations(Adafruit_NeoPixel &ledRing) : ledRing(ledRing)  {}

    void spinColorWheel(int spins, int speed) {
        int totalPixels = ledRing.numPixels();
        for (int i = 0; i < totalPixels * spins; i++) {
            for (int j = 0; j < totalPixels; j++) {
                ledRing.setPixelColor(j, wheel(((j * 256 / totalPixels) + i) & 255));
            }
            ledRing.show();
            delay(speed);
        }
    }

    void breatheAnimation(int speed, uint32_t color) {
      int numPixels = ledRing.numPixels();
        for (int i = 0; i < 256; i++) {
            float brightness = (exp(sin(i / 128.0 * M_PI)) - 0.36787944) * 108.0;
            ledRing.setBrightness(brightness);
            for (int j = 0; j < numPixels; j++) {
                ledRing.setPixelColor(j, color);
            }
            ledRing.show();
            delay(speed);
        }
        for (int i = 255; i >= 0; i--) {
            float brightness = (exp(sin(i / 128.0 * M_PI)) - 0.36787944) * 108.0;
            ledRing.setBrightness(brightness);
            for (int j = 0; j < numPixels; j++) {
                ledRing.setPixelColor(j, color);
            }
            ledRing.show();
            delay(speed);
        }
    }

private:
    Adafruit_NeoPixel &ledRing;

    uint32_t wheel(byte WheelPos) {
        WheelPos = 255 - WheelPos;
        if (WheelPos < 85) {
            return ledRing.Color(255 - WheelPos * 3, 0, WheelPos * 3);
        } else if (WheelPos < 170) {
            WheelPos -= 85;
            return ledRing.Color(0, WheelPos * 3, 255 - WheelPos * 3);
        } else {
            WheelPos -= 170;
            return ledRing.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
        }
    }
};

#endif
