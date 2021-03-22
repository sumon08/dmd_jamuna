

/*
 *
 * arial_black15
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : arial_black15.h
 * Date                : 11.05.2017
 * Font size in bytes  : 10827
 * Font width          : 10
 * Font height         : 15
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


#ifndef ARIAL_BLACK15_H
#define ARIAL_BLACK15_H

#define ARIAL_BLACK15_WIDTH 10
#define ARIAL_BLACK15_HEIGHT 15

static const uint8_t arial_black15[] = {
    0x2A, 0x4B, // size
    0x0A, // width
    0x0F, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x03, 0x07, 0x09, 0x09, 0x0D, 0x0B, 0x03, 0x05, 0x05, 
    0x06, 0x08, 0x03, 0x05, 0x03, 0x04, 0x07, 0x06, 0x07, 0x07, 
    0x09, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x07, 0x07, 
    0x07, 0x08, 0x0B, 0x0B, 0x09, 0x09, 0x09, 0x08, 0x07, 0x0A, 
    0x0A, 0x03, 0x08, 0x0B, 0x07, 0x0B, 0x0A, 0x0A, 0x08, 0x0A, 
    0x0A, 0x08, 0x09, 0x0A, 0x0B, 0x0F, 0x0B, 0x0B, 0x08, 0x05, 
    0x04, 0x05, 0x08, 0x08, 0x03, 0x08, 0x08, 0x08, 0x08, 0x08, 
    0x06, 0x08, 0x08, 0x03, 0x04, 0x09, 0x03, 0x0D, 0x08, 0x08, 
    0x08, 0x08, 0x06, 0x07, 0x06, 0x08, 0x09, 0x0D, 0x09, 0x09, 
    0x06, 0x05, 0x02, 0x05, 0x08, 0x08, 
    
    // font data
    0xFE, 0xFE, 0xFE, 0x1C, 0x1C, 0x1C, // 33
    0x1E, 0x1E, 0x1E, 0x00, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0x30, 0x30, 0xF0, 0xFE, 0x3E, 0x30, 0xF0, 0xFE, 0x3E, 0x06, 0x1E, 0x1E, 0x06, 0x06, 0x1E, 0x1E, 0x06, 0x06, // 35
    0x38, 0x7C, 0xFE, 0xE6, 0xFF, 0xE6, 0xCE, 0xCC, 0x8C, 0x04, 0x0C, 0x1C, 0x18, 0x3E, 0x18, 0x1E, 0x0E, 0x06, // 36
    0x3C, 0x7E, 0x42, 0x42, 0x7E, 0xBC, 0x40, 0xB0, 0xCC, 0x42, 0x40, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x10, 0x0C, 0x02, 0x00, 0x0E, 0x1E, 0x10, 0x10, 0x1E, 0x0E, // 37
    0x00, 0x80, 0xDC, 0xFE, 0xFE, 0xE6, 0xBE, 0x3E, 0x9C, 0x80, 0x80, 0x0E, 0x1E, 0x1E, 0x18, 0x18, 0x1A, 0x1E, 0x0E, 0x0E, 0x1E, 0x1C, // 38
    0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, // 39
    0xE0, 0xF8, 0xFC, 0x0E, 0x02, 0x0E, 0x3E, 0x7E, 0xE0, 0x80, // 40
    0x02, 0x0E, 0xFC, 0xF8, 0xE0, 0x80, 0xE0, 0x7E, 0x3E, 0x0E, // 41
    0x08, 0x68, 0x3E, 0x3E, 0x68, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0xC0, 0xC0, 0xC0, 0xF8, 0xF8, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x0E, 0x0E, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0x00, 0xDC, 0x7C, 0x3C, // 44
    0x80, 0x80, 0x80, 0x80, 0x80, 0x02, 0x02, 0x02, 0x02, 0x02, // 45
    0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, // 46
    0x00, 0xC0, 0x38, 0x06, 0x18, 0x06, 0x00, 0x00, // 47
    0xF8, 0xFC, 0xFE, 0x06, 0xFE, 0xFC, 0xF8, 0x06, 0x0E, 0x1E, 0x18, 0x1E, 0x0E, 0x06, // 48
    0x30, 0x30, 0x18, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x1E, // 49
    0x1C, 0x1E, 0x1E, 0xC6, 0xFE, 0xFC, 0x38, 0x18, 0x1C, 0x1E, 0x1E, 0x1A, 0x18, 0x18, // 50
    0x0C, 0x0E, 0x0E, 0x66, 0xFE, 0xFC, 0x98, 0x0C, 0x1C, 0x1C, 0x18, 0x1E, 0x0E, 0x06, // 51
    0x80, 0xC0, 0x70, 0x38, 0x1C, 0xFE, 0xFE, 0xFE, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x1E, 0x1E, 0x06, // 52
    0x70, 0x7E, 0x7E, 0x36, 0xF6, 0xE6, 0xC6, 0x0C, 0x1C, 0x1C, 0x18, 0x1E, 0x0E, 0x06, // 53
    0xF8, 0xFC, 0xFE, 0x46, 0xEE, 0xEE, 0xCC, 0x06, 0x0E, 0x1E, 0x18, 0x1E, 0x1E, 0x06, // 54
    0x06, 0x06, 0xC6, 0xF6, 0xFE, 0x1E, 0x06, 0x00, 0x1C, 0x1E, 0x1E, 0x00, 0x00, 0x00, // 55
    0x9C, 0xFE, 0xFE, 0x66, 0xFE, 0xFE, 0x9C, 0x0E, 0x1E, 0x1E, 0x18, 0x1E, 0x1E, 0x0E, // 56
    0x7C, 0xFE, 0xFE, 0x46, 0xFE, 0xFC, 0xF8, 0x0C, 0x1C, 0x1C, 0x18, 0x1E, 0x0E, 0x06, // 57
    0x70, 0x70, 0x70, 0x1C, 0x1C, 0x1C, // 58
    0x70, 0x70, 0x70, 0xDC, 0x7C, 0x3C, // 59
    0x40, 0xE0, 0xE0, 0xB0, 0xB8, 0x18, 0x0C, 0x00, 0x00, 0x00, 0x02, 0x06, 0x06, 0x0C, // 60
    0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, // 61
    0x0C, 0x18, 0xB8, 0xB0, 0xE0, 0xE0, 0x40, 0x0C, 0x06, 0x06, 0x02, 0x00, 0x00, 0x00, // 62
    0x18, 0x1C, 0x9E, 0xC6, 0xE6, 0xFE, 0x7C, 0x38, 0x00, 0x00, 0x1A, 0x1A, 0x1A, 0x00, 0x00, 0x00, // 63
    0xF0, 0x08, 0xE4, 0xF2, 0x1A, 0x0A, 0xF2, 0xFA, 0x3C, 0x0C, 0xF0, 0x06, 0x08, 0x16, 0x2E, 0x28, 0x28, 0x2E, 0x2E, 0x28, 0x14, 0x02, // 64
    0x00, 0x80, 0xF0, 0xFE, 0x7E, 0x0E, 0x7E, 0xFE, 0xF0, 0x80, 0x00, 0x18, 0x1E, 0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x1E, 0x18, // 65
    0xFE, 0xFE, 0xFE, 0x66, 0x66, 0x66, 0xFE, 0xFE, 0x9C, 0x1E, 0x1E, 0x1E, 0x18, 0x18, 0x18, 0x1E, 0x1E, 0x0E, // 66
    0xF0, 0xFC, 0xFE, 0x0E, 0x06, 0x0E, 0x1E, 0x1C, 0x08, 0x02, 0x0E, 0x1E, 0x1C, 0x18, 0x1C, 0x1E, 0x0E, 0x04, // 67
    0xFE, 0xFE, 0xFE, 0x06, 0x06, 0x0E, 0xFE, 0xFC, 0xF0, 0x1E, 0x1E, 0x1E, 0x18, 0x18, 0x1C, 0x1E, 0x0E, 0x02, // 68
    0xFE, 0xFE, 0xFE, 0x66, 0x66, 0x66, 0x66, 0x06, 0x1E, 0x1E, 0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, // 69
    0xFE, 0xFE, 0xFE, 0x66, 0x66, 0x66, 0x06, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, // 70
    0xF0, 0xFC, 0xFC, 0x0E, 0x06, 0xC6, 0xCE, 0xDE, 0xDC, 0xC8, 0x02, 0x0E, 0x0E, 0x1C, 0x18, 0x18, 0x18, 0x1E, 0x0E, 0x0E, // 71
    0xFE, 0xFE, 0xFE, 0x60, 0x60, 0x60, 0x60, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x1E, // 72
    0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, // 73
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0x06, 0x0E, 0x1E, 0x18, 0x18, 0x1E, 0x0E, 0x06, // 74
    0xFE, 0xFE, 0xFE, 0x60, 0x30, 0xF8, 0xFC, 0xCE, 0x06, 0x02, 0x00, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x06, 0x0E, 0x1E, 0x18, 0x10, // 75
    0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x18, 0x18, 0x18, 0x18, // 76
    0xFE, 0xFE, 0xFE, 0x3E, 0xF0, 0x00, 0xF0, 0x3E, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0x00, 0x0E, 0x1C, 0x0E, 0x00, 0x1E, 0x1E, 0x1E, // 77
    0xFE, 0xFE, 0xFE, 0x3C, 0xF8, 0xE0, 0x80, 0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x06, 0x0E, 0x1E, 0x1E, 0x1E, // 78
    0xF0, 0xFC, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0xFC, 0xFC, 0xF0, 0x02, 0x0E, 0x0E, 0x1C, 0x18, 0x18, 0x1C, 0x0E, 0x0E, 0x02, // 79
    0xFE, 0xFE, 0xFE, 0xC6, 0xC6, 0xFE, 0xFE, 0x7C, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xF0, 0xFC, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0xFC, 0xFC, 0xF0, 0x02, 0x0E, 0x0E, 0x1C, 0x18, 0x1E, 0x1C, 0x1E, 0x1E, 0x32, // 81
    0xFE, 0xFE, 0xFE, 0x66, 0x66, 0xE6, 0xFE, 0xBE, 0x1C, 0x00, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x02, 0x0E, 0x1E, 0x1C, 0x10, // 82
    0x3C, 0x7C, 0x7E, 0xE6, 0xE6, 0xEE, 0xCE, 0x8C, 0x06, 0x0E, 0x1E, 0x18, 0x18, 0x1E, 0x0E, 0x06, // 83
    0x06, 0x06, 0x06, 0xFE, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, // 84
    0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0x06, 0x0E, 0x1E, 0x1C, 0x18, 0x18, 0x1C, 0x1E, 0x0E, 0x06, // 85
    0x02, 0x1E, 0xFE, 0xF8, 0xC0, 0x00, 0xC0, 0xF8, 0xFE, 0x1E, 0x02, 0x00, 0x00, 0x00, 0x0E, 0x1E, 0x1C, 0x1E, 0x0E, 0x00, 0x00, 0x00, // 86
    0x06, 0xFE, 0xFE, 0xF0, 0xC0, 0xF8, 0xFE, 0x1E, 0xFE, 0xF8, 0xC0, 0xF0, 0xFE, 0xFE, 0x06, 0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x0E, 0x00, 0x00, 0x00, 0x0E, 0x1E, 0x1E, 0x1E, 0x00, 0x00, // 87
    0x02, 0x06, 0x1E, 0xFC, 0xF8, 0xF0, 0xF8, 0xFC, 0x1E, 0x06, 0x02, 0x10, 0x1C, 0x1E, 0x0E, 0x06, 0x00, 0x06, 0x0E, 0x1E, 0x1C, 0x10, // 88
    0x02, 0x06, 0x1E, 0x7C, 0xF8, 0xE0, 0xF8, 0x7C, 0x1E, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, // 89
    0x00, 0x06, 0xC6, 0xE6, 0xF6, 0x3E, 0x1E, 0x0E, 0x1C, 0x1E, 0x1E, 0x1A, 0x18, 0x18, 0x18, 0x18, // 90
    0xFE, 0xFE, 0xFE, 0x06, 0x06, 0xFE, 0xFE, 0xFE, 0xC0, 0xC0, // 91
    0x06, 0x78, 0x80, 0x00, 0x00, 0x00, 0x06, 0x18, // 92
    0x06, 0x06, 0xFE, 0xFE, 0xFE, 0xC0, 0xC0, 0xFE, 0xFE, 0xFE, // 93
    0x40, 0x70, 0x7C, 0x1E, 0x1E, 0x7C, 0x70, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 95
    0x02, 0x06, 0x04, 0x00, 0x00, 0x00, // 96
    0x60, 0x70, 0x70, 0xB0, 0xB0, 0xF0, 0xF0, 0xE0, 0x0C, 0x1E, 0x1E, 0x1A, 0x0A, 0x1E, 0x1E, 0x1E, // 97
    0xFE, 0xFE, 0xFE, 0x20, 0x30, 0xF0, 0xE0, 0xC0, 0x1E, 0x1E, 0x1E, 0x08, 0x18, 0x1E, 0x0E, 0x06, // 98
    0xC0, 0xE0, 0xF0, 0x30, 0x30, 0x70, 0x60, 0x40, 0x06, 0x0E, 0x1E, 0x18, 0x18, 0x1C, 0x0C, 0x04, // 99
    0xC0, 0xE0, 0xF0, 0x30, 0x20, 0xFE, 0xFE, 0xFE, 0x06, 0x0E, 0x1E, 0x18, 0x08, 0x1E, 0x1E, 0x1E, // 100
    0xC0, 0xE0, 0xF0, 0xB0, 0xB0, 0xF0, 0xE0, 0xC0, 0x06, 0x0E, 0x1E, 0x1A, 0x1A, 0x1A, 0x1A, 0x0A, // 101
    0x30, 0xFC, 0xFE, 0xFE, 0x36, 0x06, 0x00, 0x1E, 0x1E, 0x1E, 0x00, 0x00, // 102
    0xC0, 0xE0, 0xF0, 0x30, 0x20, 0xF0, 0xF0, 0xF0, 0x46, 0xCE, 0xDE, 0xD8, 0xC8, 0xFE, 0x7E, 0x7E, // 103
    0xFE, 0xFE, 0xFE, 0x20, 0x30, 0xF0, 0xF0, 0xE0, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x1E, 0x1E, 0x1E, // 104
    0xF6, 0xF6, 0xF6, 0x1E, 0x1E, 0x1E, // 105
    0x00, 0xF6, 0xF6, 0xF6, 0xC0, 0xFE, 0xFE, 0x7E, // 106
    0xFE, 0xFE, 0xFE, 0xC0, 0xE0, 0xF0, 0x30, 0x10, 0x00, 0x1E, 0x1E, 0x1E, 0x02, 0x02, 0x0E, 0x1E, 0x1C, 0x10, // 107
    0xFE, 0xFE, 0xFE, 0x1E, 0x1E, 0x1E, // 108
    0xF0, 0xF0, 0xF0, 0x20, 0x30, 0xF0, 0xF0, 0xE0, 0x20, 0x30, 0xF0, 0xF0, 0xE0, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x1E, 0x1E, 0x1E, // 109
    0xF0, 0xF0, 0xF0, 0x20, 0x30, 0xF0, 0xF0, 0xE0, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x1E, 0x1E, 0x1E, // 110
    0xC0, 0xE0, 0xF0, 0x30, 0x30, 0xF0, 0xE0, 0xC0, 0x06, 0x0E, 0x1E, 0x18, 0x18, 0x1E, 0x0E, 0x06, // 111
    0xF0, 0xF0, 0xF0, 0x20, 0x30, 0xF0, 0xE0, 0xC0, 0xFE, 0xFE, 0xFE, 0x08, 0x18, 0x1E, 0x0E, 0x06, // 112
    0xC0, 0xE0, 0xF0, 0x30, 0x20, 0xF0, 0xF0, 0xF0, 0x06, 0x0E, 0x1E, 0x18, 0x08, 0xFE, 0xFE, 0xFE, // 113
    0xF0, 0xF0, 0xF0, 0x20, 0x30, 0x10, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, // 114
    0xE0, 0xF0, 0xF0, 0x90, 0x90, 0xB0, 0x20, 0x08, 0x1A, 0x12, 0x12, 0x1E, 0x1E, 0x0E, // 115
    0x30, 0xFC, 0xFC, 0xFE, 0x30, 0x30, 0x00, 0x0E, 0x1E, 0x1E, 0x18, 0x18, // 116
    0xF0, 0xF0, 0xF0, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0x0E, 0x1E, 0x1E, 0x18, 0x08, 0x1E, 0x1E, 0x1E, // 117
    0x10, 0xF0, 0xF0, 0xC0, 0x00, 0xC0, 0xF0, 0xF0, 0x10, 0x00, 0x00, 0x06, 0x1E, 0x1C, 0x1E, 0x06, 0x00, 0x00, // 118
    0x30, 0xF0, 0xF0, 0xC0, 0x00, 0xF0, 0x70, 0xF0, 0x00, 0xC0, 0xF0, 0xF0, 0x30, 0x00, 0x02, 0x1E, 0x1E, 0x1E, 0x06, 0x00, 0x02, 0x1E, 0x1E, 0x1E, 0x02, 0x00, // 119
    0x10, 0x30, 0xF0, 0xE0, 0xC0, 0xE0, 0xF0, 0x30, 0x10, 0x10, 0x18, 0x1E, 0x0E, 0x02, 0x0E, 0x1E, 0x18, 0x10, // 120
    0x10, 0xF0, 0xF0, 0xC0, 0x00, 0xC0, 0xF0, 0xF0, 0x10, 0xC0, 0xC0, 0xCE, 0xFE, 0xFC, 0x3E, 0x0E, 0x00, 0x00, // 121
    0x30, 0x30, 0xB0, 0xF0, 0x70, 0x30, 0x18, 0x1E, 0x1E, 0x1A, 0x18, 0x18, // 122
    0x80, 0xFC, 0xFE, 0x7E, 0x06, 0x02, 0x7E, 0xFE, 0xFC, 0xC0, // 123
    0xFE, 0xFE, 0xFE, 0xFE, // 124
    0x06, 0x7E, 0xFE, 0xFC, 0x80, 0xC0, 0xFC, 0xFE, 0x7E, 0x02, // 125
    0xC0, 0x60, 0x60, 0x60, 0xC0, 0xC0, 0xC0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xF8, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xF8, 0x1E, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1E // 127
    
};

#endif
