/*
  Resources to display time.
  Theme: Crystal
*/

#ifndef CrystalDigits_h
#define CrystalDigits_h

#include "Arduino.h"

// 'digit_0', 29x32px
const unsigned char crystalDigit0 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0xff, 0xff, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};


// 'digit_1', 29x32px
const unsigned char crystalDigit1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'digit_2', 29x32px
const unsigned char crystalDigit2 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x03, 0xfd, 0xf8, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_3', 29x32px
const unsigned char crystalDigit3 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x7e, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7e, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_4', 29x32px
const unsigned char crystalDigit4 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x06, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'digit_5', 29x32px
const unsigned char crystalDigit5 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xf8, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0xfd, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_6', 29x32px
const unsigned char crystalDigit6 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xf8, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0xfd, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0xff, 0xff, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_7', 29x32px
const unsigned char crystalDigit7 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'digit_8', 29x32px
const unsigned char crystalDigit8 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0xff, 0xff, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_9', 29x32px
const unsigned char crystalDigit9 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};

// 'A', 27x32px
const unsigned char epd_bitmap_A [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x7f, 0xc0, 0x00, 0x00, 0x7b, 0xc0, 0x00, 
	0x00, 0xfb, 0xe0, 0x00, 0x00, 0xf1, 0xe0, 0x00, 0x00, 0xf1, 0xe0, 0x00, 0x01, 0xf1, 0xf0, 0x00, 
	0x01, 0xe0, 0xf0, 0x00, 0x01, 0xe0, 0xf8, 0x00, 0x03, 0xe0, 0xf8, 0x00, 0x03, 0xc0, 0x78, 0x00, 
	0x03, 0xc0, 0x7c, 0x00, 0x07, 0x80, 0x7c, 0x00, 0x07, 0x80, 0x3c, 0x00, 0x0f, 0x80, 0x3e, 0x00, 
	0x0f, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0x00, 0x1f, 0x00, 0x1f, 0x00, 
	0x1e, 0x00, 0x0f, 0x80, 0x3e, 0x00, 0x0f, 0x80, 0x3c, 0x00, 0x07, 0x80, 0x3c, 0x00, 0x07, 0xc0, 
	0x7c, 0x00, 0x07, 0xc0, 0x78, 0x00, 0x03, 0xc0, 0x78, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00
};
// 'B', 29x32px
const unsigned char epd_bitmap_B [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xfc, 0x00, 
	0x07, 0xff, 0xfc, 0x00, 0x07, 0x80, 0x7e, 0x00, 0x07, 0x80, 0x3e, 0x00, 0x07, 0x80, 0x1e, 0x00, 
	0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1e, 0x00, 0x07, 0x80, 0x3e, 0x00, 
	0x07, 0x80, 0x3e, 0x00, 0x07, 0x80, 0xfc, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xf0, 0x00, 
	0x07, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xfe, 0x00, 0x07, 0x80, 0x3f, 0x00, 0x07, 0x80, 0x1f, 0x80, 
	0x07, 0x80, 0x0f, 0x80, 0x07, 0x80, 0x0f, 0x80, 0x07, 0x80, 0x07, 0x80, 0x07, 0x80, 0x07, 0x80, 
	0x07, 0x80, 0x0f, 0x80, 0x07, 0x80, 0x0f, 0x80, 0x07, 0x80, 0x1f, 0x80, 0x07, 0x80, 0x3f, 0x00, 
	0x07, 0xff, 0xfe, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xc0, 0x00
};
// 'C', 29x32px
const unsigned char epd_bitmap_C [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x3f, 0xfc, 0x00, 
	0x00, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0x00, 0x03, 0xf0, 0x0f, 0x00, 0x07, 0xe0, 0x03, 0x00, 
	0x07, 0xc0, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 
	0x0f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 
	0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 
	0x1f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 
	0x07, 0xc0, 0x00, 0x00, 0x07, 0xe0, 0x07, 0x00, 0x03, 0xf8, 0x1f, 0x00, 0x01, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'D', 29x32px
const unsigned char epd_bitmap_D [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xf8, 0x00, 
	0x1f, 0xff, 0xfc, 0x00, 0x1e, 0x01, 0xfe, 0x00, 0x1e, 0x00, 0x7f, 0x00, 0x1e, 0x00, 0x1f, 0x00, 
	0x1e, 0x00, 0x0f, 0x80, 0x1e, 0x00, 0x0f, 0x80, 0x1e, 0x00, 0x07, 0xc0, 0x1e, 0x00, 0x07, 0xc0, 
	0x1e, 0x00, 0x07, 0xc0, 0x1e, 0x00, 0x03, 0xc0, 0x1e, 0x00, 0x03, 0xc0, 0x1e, 0x00, 0x03, 0xc0, 
	0x1e, 0x00, 0x03, 0xc0, 0x1e, 0x00, 0x03, 0xc0, 0x1e, 0x00, 0x03, 0xc0, 0x1e, 0x00, 0x07, 0xc0, 
	0x1e, 0x00, 0x07, 0xc0, 0x1e, 0x00, 0x07, 0xc0, 0x1e, 0x00, 0x07, 0xc0, 0x1e, 0x00, 0x0f, 0x80, 
	0x1e, 0x00, 0x0f, 0x80, 0x1e, 0x00, 0x1f, 0x00, 0x1e, 0x00, 0x7f, 0x00, 0x1e, 0x03, 0xfe, 0x00, 
	0x1f, 0xff, 0xfc, 0x00, 0x1f, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x0f, 0xfc, 0x00, 0x00
};
// 'E', 29x32px
const unsigned char epd_bitmap_E [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xfe, 0x00, 
	0x03, 0xff, 0xfc, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 
	0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 
	0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xf8, 0x00, 
	0x03, 0xff, 0xf8, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 
	0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 
	0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 
	0x03, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00
};
// 'F', 29x32px
const unsigned char epd_bitmap_F [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfc, 0x00, 
	0x01, 0xff, 0xfc, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 
	0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 
	0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 
	0x01, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 
	0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 
	0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 
	0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'G', 29x32px
const unsigned char epd_bitmap_G [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0xff, 0xff, 0xc0, 
	0x01, 0xff, 0xff, 0xe0, 0x03, 0xf8, 0x07, 0xe0, 0x07, 0xe0, 0x00, 0xe0, 0x07, 0xc0, 0x00, 0x00, 
	0x0f, 0x80, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 
	0x1e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x01, 0xff, 0xc0, 
	0x3e, 0x01, 0xff, 0xe0, 0x3e, 0x01, 0xff, 0xe0, 0x3e, 0x00, 0x03, 0xe0, 0x3e, 0x00, 0x03, 0xe0, 
	0x1e, 0x00, 0x03, 0xe0, 0x1f, 0x00, 0x03, 0xe0, 0x1f, 0x00, 0x03, 0xe0, 0x0f, 0x80, 0x03, 0xe0, 
	0x0f, 0xc0, 0x03, 0xe0, 0x07, 0xe0, 0x03, 0xe0, 0x07, 0xf0, 0x03, 0xe0, 0x03, 0xff, 0xbf, 0xe0, 
	0x01, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'H', 29x32px
const unsigned char epd_bitmap_H [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 
	0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 
	0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 
	0x1f, 0x00, 0x07, 0x80, 0x1f, 0x7f, 0xef, 0x80, 0x1f, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0x80, 
	0x1f, 0xff, 0xff, 0x80, 0x1f, 0x00, 0x0f, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 
	0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 
	0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 
	0x1f, 0x00, 0x07, 0x80, 0x1f, 0x00, 0x07, 0x80, 0x1e, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00
};
// 'I', 29x32px
const unsigned char epd_bitmap_I [] PROGMEM = {
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'J', 29x32px
const unsigned char epd_bitmap_J [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x61, 0xf0, 0x00, 0x00, 0x7f, 0xf0, 0x00, 
	0x00, 0x7f, 0xe0, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'T', 29x32px
const unsigned char epd_bitmap_T [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xc0, 
	0x0f, 0xff, 0xff, 0xc0, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'Y', 29x32px
const unsigned char epd_bitmap_Y [] PROGMEM = {
	0x0f, 0x00, 0x07, 0x80, 0x0f, 0x00, 0x07, 0x80, 0x0f, 0x80, 0x0f, 0x80, 0x0f, 0x80, 0x0f, 0x80, 
	0x07, 0xc0, 0x1f, 0x00, 0x07, 0xc0, 0x1f, 0x00, 0x03, 0xe0, 0x3e, 0x00, 0x03, 0xe0, 0x3e, 0x00, 
	0x01, 0xf0, 0x7c, 0x00, 0x01, 0xf0, 0x7c, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0xf8, 0xf8, 0x00, 
	0x00, 0x7c, 0xf0, 0x00, 0x00, 0x7d, 0xf0, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x3f, 0xe0, 0x00, 
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x07, 0x00, 0x00
};

// 'SPACE', 29x32px
const unsigned char epd_bitmap_SPACE [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Array with all digits
const unsigned char * allCrystalDigits [] = {
  crystalDigit0,
  crystalDigit1,
  crystalDigit2,
  crystalDigit3,
  crystalDigit4,
  crystalDigit5,
  crystalDigit6,
  crystalDigit7,
  crystalDigit8,
  crystalDigit9, 
  epd_bitmap_A,
	epd_bitmap_B,
	epd_bitmap_C,
	epd_bitmap_D,
	epd_bitmap_E,
	epd_bitmap_F,
	epd_bitmap_G,
	epd_bitmap_H,
	epd_bitmap_I,
	epd_bitmap_J,
	epd_bitmap_T,
  epd_bitmap_SPACE,
	epd_bitmap_Y
};

// 'digit_colon', 12x32px
const unsigned char crystalColon [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x06, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x06, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


// 'digit_no_colon', 12x32px
const unsigned char crystalNoColon [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char * crystalColonOrNot [] = {
  crystalNoColon,  // index 0 => bool(false) => pas de colon (:)
  crystalColon
};

#endif