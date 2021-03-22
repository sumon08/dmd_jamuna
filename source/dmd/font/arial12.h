

/*
 *
 * new Font
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : arial12
 * Date                : 11.05.2017
 * Font size in bytes  : 5742
 * Font width          : 10
 * Font height         : 12
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

#ifndef NEW_FONT_H
#define NEW_FONT_H

#define NEW_FONT_WIDTH 10
#define NEW_FONT_HEIGHT 12

static const uint8_t arial12[] = {
		 0x12, 0x2A, // size
		    0x0A, // width
		    0x0C, // height
		    0x20, // first char
		    0x60, // char count

		    // char widths
		    0x00, 0x01, 0x03, 0x05, 0x05, 0x07, 0x05, 0x01, 0x02, 0x02,
		    0x03, 0x05, 0x02, 0x02, 0x01, 0x03, 0x04, 0x03, 0x04, 0x04,
		    0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01, 0x02, 0x04, 0x04,
		    0x04, 0x04, 0x08, 0x05, 0x05, 0x06, 0x05, 0x05, 0x04, 0x06,
		    0x05, 0x01, 0x04, 0x05, 0x04, 0x07, 0x06, 0x06, 0x05, 0x06,
		    0x06, 0x05, 0x05, 0x06, 0x05, 0x07, 0x06, 0x05, 0x05, 0x02,
		    0x03, 0x02, 0x03, 0x05, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04,
		    0x02, 0x04, 0x04, 0x01, 0x01, 0x04, 0x01, 0x07, 0x04, 0x04,
		    0x04, 0x04, 0x03, 0x04, 0x02, 0x04, 0x05, 0x07, 0x05, 0x05,
		    0x04, 0x02, 0x01, 0x03, 0x05, 0x03,

		    // font data
		    0x7E, 0x10, // 33
		    0x0E, 0x00, 0x0E, 0x00, 0x00, 0x00, // 34
		    0xF8, 0x4E, 0xF8, 0x4E, 0x48, 0x10, 0x00, 0x10, 0x00, 0x00, // 35
		    0x8C, 0x12, 0xFF, 0x12, 0xE4, 0x00, 0x10, 0x30, 0x10, 0x00, // 36
		    0x0C, 0x12, 0x8C, 0x70, 0xCC, 0x22, 0xC0, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, // 37
		    0xE0, 0x2C, 0x32, 0xCC, 0xE0, 0x00, 0x10, 0x10, 0x00, 0x10, // 38
		    0x0E, 0x00, // 39
		    0xFC, 0x02, 0x30, 0x40, // 40
		    0x02, 0xFC, 0x40, 0x30, // 41
		    0x14, 0x0E, 0x14, 0x00, 0x00, 0x00, // 42
		    0x20, 0x20, 0xF8, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
		    0x00, 0x00, 0x40, 0x30, // 44
		    0x40, 0x40, 0x00, 0x00, // 45
		    0x00, 0x10, // 46
		    0xC0, 0x30, 0x0E, 0x10, 0x00, 0x00, // 47
		    0xFC, 0x02, 0x02, 0xFC, 0x00, 0x10, 0x10, 0x00, // 48
		    0x08, 0x04, 0xFE, 0x00, 0x00, 0x10, // 49
		    0x84, 0x42, 0x22, 0x1C, 0x10, 0x10, 0x10, 0x10, // 50
		    0x84, 0x12, 0x12, 0xEC, 0x00, 0x10, 0x10, 0x00, // 51
		    0x60, 0x58, 0x44, 0xFE, 0x40, 0x00, 0x00, 0x00, 0x10, 0x00, // 52
		    0x98, 0x16, 0x12, 0xE2, 0x00, 0x10, 0x10, 0x00, // 53
		    0xFC, 0x22, 0x12, 0xE4, 0x00, 0x10, 0x10, 0x00, // 54
		    0x02, 0xC2, 0x3A, 0x06, 0x00, 0x10, 0x00, 0x00, // 55
		    0xEC, 0x12, 0x12, 0xEC, 0x00, 0x10, 0x10, 0x00, // 56
		    0x9C, 0x22, 0x12, 0xFC, 0x00, 0x10, 0x10, 0x00, // 57
		    0x08, 0x10, // 58
		    0x00, 0x08, 0x40, 0x30, // 59
		    0x20, 0x50, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00, // 60
		    0x50, 0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00, // 61
		    0x88, 0x50, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, // 62
		    0x04, 0x62, 0x12, 0x0C, 0x00, 0x10, 0x00, 0x00, // 63
		    0xF0, 0x08, 0xF4, 0x0A, 0x0A, 0xF2, 0x0C, 0xF8, 0x10, 0x20, 0x40, 0x90, 0x90, 0x90, 0x50, 0x20, // 64
		    0xFC, 0x42, 0x42, 0x42, 0xFC, 0x10, 0x00, 0x00, 0x00, 0x10, // 65
		    0xFE, 0x12, 0x12, 0x12, 0xEC, 0x10, 0x10, 0x10, 0x10, 0x00, // 66
		    0xFC, 0x02, 0x02, 0x02, 0x02, 0xCC, 0x00, 0x10, 0x10, 0x10, 0x10, 0x00, // 67
		    0xFE, 0x02, 0x02, 0x02, 0xFC, 0x10, 0x10, 0x10, 0x10, 0x00, // 68
		    0xFE, 0x12, 0x12, 0x12, 0x12, 0x10, 0x10, 0x10, 0x10, 0x10, // 69
		    0xFE, 0x12, 0x12, 0x02, 0x10, 0x00, 0x00, 0x00, // 70
		    0x78, 0x84, 0x02, 0x22, 0x22, 0xEC, 0x00, 0x00, 0x10, 0x10, 0x10, 0x00, // 71
		    0xFE, 0x10, 0x10, 0x10, 0xFE, 0x10, 0x00, 0x00, 0x00, 0x10, // 72
		    0xFE, 0x10, // 73
		    0xC0, 0x00, 0x00, 0xFE, 0x00, 0x10, 0x10, 0x00, // 74
		    0xFE, 0x10, 0x38, 0xC4, 0x02, 0x10, 0x00, 0x00, 0x00, 0x10, // 75
		    0xFE, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, // 76
		    0xFE, 0x0C, 0xF0, 0x00, 0xF0, 0x0C, 0xFE, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, // 77
		    0xFE, 0x04, 0x18, 0x60, 0x80, 0xFE, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, // 78
		    0x78, 0x84, 0x02, 0x02, 0x84, 0x78, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, // 79
		    0xFE, 0x22, 0x22, 0x22, 0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, // 80
		    0xFC, 0x02, 0x02, 0x42, 0x82, 0x7C, 0x00, 0x10, 0x10, 0x10, 0x00, 0x10, // 81
		    0xFE, 0x12, 0x32, 0x52, 0x8C, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, // 82
		    0xCC, 0x12, 0x12, 0x12, 0xE4, 0x00, 0x10, 0x10, 0x10, 0x00, // 83
		    0x02, 0x02, 0xFE, 0x02, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, // 84
		    0xFE, 0x80, 0x00, 0x00, 0x80, 0xFE, 0x00, 0x10, 0x10, 0x10, 0x10, 0x00, // 85
		    0x1E, 0xE0, 0x00, 0xE0, 0x1E, 0x00, 0x00, 0x10, 0x00, 0x00, // 86
		    0xFE, 0x00, 0xFC, 0x02, 0xFC, 0x00, 0xFE, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, // 87
		    0x02, 0xCC, 0x30, 0x30, 0xCC, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, // 88
		    0x02, 0x0C, 0xF0, 0x0C, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, // 89
		    0x82, 0x42, 0x32, 0x0A, 0x06, 0x10, 0x10, 0x10, 0x10, 0x10, // 90
		    0xFE, 0x02, 0x70, 0x40, // 91
		    0x06, 0x78, 0x80, 0x00, 0x00, 0x10, // 92
		    0x02, 0xFE, 0x40, 0x70, // 93
		    0x1C, 0x02, 0x1C, 0x00, 0x00, 0x00, // 94
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, // 95
		    0x02, 0x04, 0x00, 0x00, // 96
		    0xC8, 0x28, 0x28, 0xF0, 0x00, 0x10, 0x10, 0x10, // 97
		    0xFE, 0x10, 0x10, 0xE0, 0x10, 0x10, 0x10, 0x00, // 98
		    0xF0, 0x08, 0x08, 0x90, 0x00, 0x10, 0x10, 0x00, // 99
		    0xE0, 0x10, 0x10, 0xFE, 0x00, 0x10, 0x10, 0x10, // 100
		    0xF0, 0x28, 0x28, 0xB0, 0x00, 0x10, 0x10, 0x00, // 101
		    0xFE, 0x0A, 0x10, 0x00, // 102
		    0xF0, 0x08, 0x08, 0xF8, 0x40, 0x50, 0x50, 0x30, // 103
		    0xFE, 0x10, 0x10, 0xE0, 0x10, 0x00, 0x00, 0x10, // 104
		    0xFA, 0x10, // 105
		    0xFA, 0x70, // 106
		    0xFE, 0x20, 0x50, 0x88, 0x10, 0x00, 0x00, 0x10, // 107
		    0xFE, 0x10, // 108
		    0xF8, 0x10, 0x08, 0xF0, 0x10, 0x08, 0xF0, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, // 109
		    0xF8, 0x10, 0x08, 0xF0, 0x10, 0x00, 0x00, 0x10, // 110
		    0xF0, 0x08, 0x08, 0xF0, 0x00, 0x10, 0x10, 0x00, // 111
		    0xF8, 0x88, 0x88, 0x70, 0x70, 0x00, 0x00, 0x00, // 112
		    0x70, 0x88, 0x88, 0xF8, 0x00, 0x00, 0x00, 0x70, // 113
		    0xF8, 0x10, 0x08, 0x10, 0x00, 0x00, // 114
		    0x90, 0x28, 0x48, 0x90, 0x00, 0x10, 0x10, 0x00, // 115
		    0xFE, 0x08, 0x00, 0x10, // 116
		    0xF8, 0x00, 0x00, 0xF8, 0x00, 0x10, 0x10, 0x00, // 117
		    0x18, 0xE0, 0x00, 0xE0, 0x18, 0x00, 0x00, 0x10, 0x00, 0x00, // 118
		    0xF8, 0x00, 0xF0, 0x08, 0xF0, 0x00, 0xF8, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, // 119
		    0x08, 0x90, 0x60, 0x90, 0x08, 0x10, 0x00, 0x00, 0x00, 0x10, // 120
		    0x08, 0x70, 0x80, 0x70, 0x08, 0x00, 0x40, 0x30, 0x00, 0x00, // 121
		    0x88, 0x48, 0x28, 0x18, 0x10, 0x10, 0x10, 0x10, // 122
		    0xDC, 0x02, 0x30, 0x40, // 123
		    0xFE, 0x70, // 124
		    0x02, 0xDC, 0x20, 0x40, 0x30, 0x00, // 125
		    0x20, 0x10, 0x30, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
		    0xFC, 0x04, 0xFC, 0x10, 0x10, 0x10 // 127
};

#endif
