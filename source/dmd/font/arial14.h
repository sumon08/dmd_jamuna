

/*
 *
 * arial14
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : arial14.h
 * Date                : 11.05.2017
 * Font size in bytes  : 7788
 * Font width          : 10
 * Font height         : 14
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>

#ifndef ARIAL14_H
#define ARIAL14_H

#define ARIAL14_WIDTH 10
#define ARIAL14_HEIGHT 14

static const uint8_t arial14[] = {
	0x1C, 0x4A, // size
	0x0A, // width
	0x0E, // height
	0x20, // first char
	0x60, // char count

	// char widths
	0x00, 0x02, 0x05, 0x06, 0x05, 0x09, 0x08, 0x02, 0x03, 0x03,
	0x04, 0x06, 0x02, 0x04, 0x02, 0x03, 0x05, 0x04, 0x05, 0x05,
	0x06, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0x02, 0x06, 0x06,
	0x06, 0x06, 0x0B, 0x08, 0x07, 0x08, 0x07, 0x06, 0x06, 0x08,
	0x07, 0x02, 0x05, 0x07, 0x06, 0x09, 0x07, 0x08, 0x06, 0x08,
	0x08, 0x07, 0x06, 0x07, 0x07, 0x0B, 0x07, 0x08, 0x06, 0x03,
	0x03, 0x03, 0x06, 0x06, 0x03, 0x05, 0x06, 0x05, 0x06, 0x05,
	0x03, 0x06, 0x06, 0x02, 0x02, 0x05, 0x02, 0x08, 0x06, 0x06,
	0x06, 0x06, 0x04, 0x05, 0x03, 0x06, 0x05, 0x09, 0x06, 0x05,
	0x05, 0x03, 0x02, 0x04, 0x07, 0x02,

	// font data
	0xFE, 0xFE, 0x18, 0x18, // 33
	0x1E, 0x1E, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
	0x98, 0xF8, 0x9E, 0x98, 0xF8, 0x9E, 0x1C, 0x04, 0x04, 0x1C, 0x04, 0x04, // 35
	0x3C, 0x72, 0xFF, 0x66, 0xCC, 0x0C, 0x18, 0x3C, 0x10, 0x0C, // 36
	0x1C, 0x22, 0x22, 0x1C, 0xC0, 0xB8, 0x46, 0x40, 0x80, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x0C, 0x10, 0x10, 0x0C, // 37
	0x80, 0xCC, 0x7E, 0x76, 0xDE, 0x8C, 0xC0, 0x00, 0x0C, 0x1C, 0x18, 0x18, 0x1C, 0x0C, 0x1C, 0x08, // 38
	0x1E, 0x1E, 0x00, 0x00, // 39
	0xF0, 0xFC, 0x06, 0x1C, 0x7C, 0xC0, // 40
	0x06, 0xFC, 0xF0, 0xC0, 0x7C, 0x1C, // 41
	0x38, 0x0E, 0x38, 0x04, 0x00, 0x00, 0x00, 0x00, // 42
	0x60, 0x60, 0xFC, 0xFC, 0x60, 0x60, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, // 43
	0x00, 0x00, 0x58, 0x38, // 44
	0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, // 45
	0x00, 0x00, 0x18, 0x18, // 46
	0xC0, 0xFE, 0x3E, 0x1C, 0x1C, 0x00, // 47
	0xF8, 0xFE, 0x06, 0xFE, 0xF8, 0x0C, 0x1C, 0x18, 0x1C, 0x04, // 48
	0x08, 0x0C, 0xFE, 0xFE, 0x00, 0x00, 0x1C, 0x1C, // 49
	0x0C, 0x8E, 0xC6, 0x7E, 0x3C, 0x1C, 0x1C, 0x18, 0x18, 0x18, // 50
	0x0C, 0x0E, 0x66, 0xFE, 0x9C, 0x0C, 0x1C, 0x18, 0x1C, 0x0C, // 51
	0xE0, 0xF0, 0x9C, 0xFE, 0xFE, 0x80, 0x04, 0x04, 0x04, 0x1C, 0x1C, 0x04, // 52
	0x3E, 0x3E, 0x36, 0xF6, 0xE6, 0x0C, 0x1C, 0x18, 0x1C, 0x0C, // 53
	0xFC, 0xFE, 0x66, 0xEE, 0xCC, 0x0C, 0x1C, 0x18, 0x1C, 0x0C, // 54
	0x06, 0x86, 0xE6, 0xFE, 0x1E, 0x00, 0x1C, 0x1C, 0x00, 0x00, // 55
	0x9C, 0xFE, 0x66, 0xFE, 0x9C, 0x0C, 0x1C, 0x18, 0x1C, 0x0C, // 56
	0x3C, 0x7E, 0x66, 0xFE, 0xFC, 0x0C, 0x1C, 0x18, 0x1C, 0x0C, // 57
	0x30, 0x30, 0x18, 0x18, // 58
	0x30, 0x30, 0x58, 0x38, // 59
	0xE0, 0xE0, 0xB0, 0xB0, 0xB0, 0x18, 0x00, 0x00, 0x04, 0x04, 0x04, 0x0C, // 60
	0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, // 61
	0x18, 0xB0, 0xB0, 0xB0, 0xE0, 0xE0, 0x0C, 0x04, 0x04, 0x04, 0x00, 0x00, // 62
	0x0C, 0x0E, 0xC6, 0xE6, 0x3E, 0x1C, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, // 63
	0xE0, 0x38, 0xCC, 0xEC, 0x76, 0x36, 0xB6, 0xF6, 0x6C, 0x1C, 0xF0, 0x1C, 0x30, 0x6C, 0xDC, 0xD8, 0xD8, 0xDC, 0xDC, 0xD8, 0x6C, 0x20, // 64
	0x00, 0xE0, 0xF8, 0x9E, 0x9E, 0xF8, 0xE0, 0x00, 0x1C, 0x1C, 0x04, 0x04, 0x04, 0x04, 0x1C, 0x1C, // 65
	0xFE, 0xFE, 0x66, 0x66, 0x66, 0xFE, 0x9C, 0x1C, 0x1C, 0x18, 0x18, 0x18, 0x1C, 0x0C, // 66
	0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0x9C, 0x98, 0x04, 0x0C, 0x1C, 0x18, 0x18, 0x1C, 0x0C, 0x04, // 67
	0xFE, 0xFE, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x1C, 0x1C, 0x18, 0x18, 0x1C, 0x0C, 0x04, // 68
	0xFE, 0xFE, 0x66, 0x66, 0x66, 0x66, 0x1C, 0x1C, 0x18, 0x18, 0x18, 0x18, // 69
	0xFE, 0xFE, 0x66, 0x66, 0x66, 0x06, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, // 70
	0xF8, 0xFC, 0x0E, 0x06, 0xC6, 0xCE, 0xDC, 0xD8, 0x04, 0x0C, 0x1C, 0x18, 0x18, 0x18, 0x1C, 0x0C, // 71
	0xFE, 0xFE, 0x60, 0x60, 0x60, 0xFE, 0xFE, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x1C, // 72
	0xFE, 0xFE, 0x1C, 0x1C, // 73
	0x80, 0x80, 0x00, 0xFE, 0xFE, 0x0C, 0x1C, 0x18, 0x1C, 0x0C, // 74
	0xFE, 0xFE, 0x60, 0x70, 0xFC, 0x8E, 0x02, 0x1C, 0x1C, 0x00, 0x00, 0x04, 0x1C, 0x18, // 75
	0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x18, 0x18, 0x18, 0x18, // 76
	0xFE, 0xFE, 0x1E, 0xF8, 0x00, 0xF0, 0x1E, 0xFE, 0xFE, 0x1C, 0x1C, 0x00, 0x0C, 0x18, 0x0C, 0x00, 0x1C, 0x1C, // 77
	0xFE, 0xFE, 0x3C, 0xF0, 0x80, 0xFE, 0xFE, 0x1C, 0x1C, 0x00, 0x00, 0x0C, 0x1C, 0x1C, // 78
	0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x04, 0x0C, 0x1C, 0x18, 0x18, 0x1C, 0x0C, 0x04, // 79
	0xFE, 0xFE, 0x66, 0x66, 0x7E, 0x3C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, // 80
	0xF8, 0xFC, 0x0E, 0x06, 0x86, 0x0E, 0xFC, 0xF8, 0x04, 0x0C, 0x1C, 0x18, 0x18, 0x1C, 0x0C, 0x14, // 81
	0xFE, 0xFE, 0x66, 0x66, 0xE6, 0xBE, 0x3C, 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x04, 0x0C, 0x18, 0x00, // 82
	0x3C, 0x7E, 0x66, 0x66, 0x66, 0xEE, 0xCC, 0x0C, 0x1C, 0x18, 0x18, 0x18, 0x1C, 0x0C, // 83
	0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, // 84
	0xFE, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x0C, 0x1C, 0x18, 0x18, 0x18, 0x1C, 0x0C, // 85
	0x0E, 0xFE, 0xF8, 0x00, 0xF8, 0xFE, 0x0E, 0x00, 0x04, 0x1C, 0x1C, 0x1C, 0x04, 0x00, // 86
	0x06, 0xFE, 0xF8, 0x80, 0x78, 0x06, 0xF8, 0x00, 0xF8, 0xFE, 0x06, 0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, // 87
	0x02, 0x0E, 0xFC, 0xF0, 0xFC, 0x0E, 0x02, 0x10, 0x1C, 0x0C, 0x00, 0x0C, 0x1C, 0x10, // 88
	0x02, 0x0E, 0x3C, 0xF0, 0xF0, 0x3C, 0x0E, 0x02, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x00, // 89
	0x06, 0x86, 0xE6, 0x76, 0x1E, 0x0E, 0x1C, 0x1C, 0x18, 0x18, 0x18, 0x18, // 90
	0xFE, 0xFE, 0x06, 0xFC, 0xFC, 0xC0, // 91
	0x3E, 0xFE, 0xC0, 0x00, 0x1C, 0x1C, // 92
	0x06, 0xFE, 0xFE, 0xC0, 0xFC, 0xFC, // 93
	0x20, 0x38, 0x1E, 0x06, 0x1E, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 95
	0x02, 0x06, 0x04, 0x00, 0x00, 0x00, // 96
	0x20, 0xB0, 0x90, 0xF0, 0xE0, 0x0C, 0x1C, 0x10, 0x1C, 0x1C, // 97
	0xFE, 0xFE, 0x20, 0x30, 0xF0, 0xE0, 0x1C, 0x1C, 0x08, 0x18, 0x1C, 0x0C, // 98
	0xE0, 0xF0, 0x30, 0x70, 0x60, 0x0C, 0x1C, 0x18, 0x1C, 0x0C, // 99
	0xE0, 0xF0, 0x30, 0x20, 0xFE, 0xFE, 0x0C, 0x1C, 0x18, 0x08, 0x1C, 0x1C, // 100
	0xE0, 0xF0, 0xB0, 0xF0, 0xE0, 0x0C, 0x1C, 0x10, 0x18, 0x08, // 101
	0xFC, 0xFE, 0x36, 0x1C, 0x1C, 0x00, // 102
	0xE0, 0xF0, 0x30, 0x20, 0xF0, 0xF0, 0x6C, 0xFC, 0xD8, 0xC8, 0xFC, 0x7C, // 103
	0xFE, 0xFE, 0x20, 0x30, 0xF0, 0xE0, 0x1C, 0x1C, 0x00, 0x00, 0x1C, 0x1C, // 104
	0xF6, 0xF6, 0x1C, 0x1C, // 105
	0xF6, 0xF6, 0xFC, 0x7C, // 106
	0xFE, 0xFE, 0xE0, 0xF0, 0x90, 0x1C, 0x1C, 0x00, 0x1C, 0x1C, // 107
	0xFE, 0xFE, 0x1C, 0x1C, // 108
	0xF0, 0xF0, 0x30, 0xF0, 0xE0, 0x30, 0xF0, 0xE0, 0x1C, 0x1C, 0x00, 0x1C, 0x1C, 0x00, 0x1C, 0x1C, // 109
	0xF0, 0xF0, 0x20, 0x30, 0xF0, 0xE0, 0x1C, 0x1C, 0x00, 0x00, 0x1C, 0x1C, // 110
	0xE0, 0xF0, 0x30, 0x30, 0xF0, 0xE0, 0x0C, 0x1C, 0x18, 0x18, 0x1C, 0x0C, // 111
	0xF0, 0xF0, 0x20, 0x30, 0xF0, 0xE0, 0xFC, 0xFC, 0x08, 0x18, 0x1C, 0x0C, // 112
	0xE0, 0xF0, 0x30, 0x20, 0xF0, 0xF0, 0x0C, 0x1C, 0x18, 0x08, 0xFC, 0xFC, // 113
	0xF0, 0xF0, 0x20, 0x30, 0x1C, 0x1C, 0x00, 0x00, // 114
	0xE0, 0xF0, 0x90, 0xB0, 0xA0, 0x08, 0x18, 0x10, 0x1C, 0x0C, // 115
	0xFC, 0xFE, 0x30, 0x0C, 0x1C, 0x18, // 116
	0xF0, 0xF0, 0x00, 0x00, 0xF0, 0xF0, 0x0C, 0x1C, 0x18, 0x08, 0x1C, 0x1C, // 117
	0x70, 0xF0, 0x00, 0xF0, 0x70, 0x00, 0x1C, 0x18, 0x1C, 0x00, // 118
	0x70, 0xF0, 0x00, 0xF0, 0x70, 0xF0, 0x00, 0xF0, 0x70, 0x00, 0x1C, 0x18, 0x1C, 0x00, 0x1C, 0x18, 0x1C, 0x00, // 119
	0x10, 0x70, 0xE0, 0xE0, 0x70, 0x10, 0x10, 0x1C, 0x0C, 0x0C, 0x1C, 0x10, // 120
	0x70, 0xF0, 0x00, 0xF0, 0x70, 0xC0, 0xDC, 0x78, 0x1C, 0x00, // 121
	0x30, 0xB0, 0xF0, 0xF0, 0x30, 0x18, 0x1C, 0x1C, 0x18, 0x18, // 122
	0xFC, 0x3E, 0x06, 0x7C, 0xFC, 0xC0, // 123
	0xFE, 0xFE, 0xFC, 0xFC, // 124
	0x06, 0x3E, 0xFC, 0xC0, 0xC0, 0xFC, 0x7C, 0x00, // 125
	0xC0, 0x60, 0x60, 0xE0, 0xC0, 0xC0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
	0xFC, 0xFC, 0x1C, 0x1C // 127

};

#endif
