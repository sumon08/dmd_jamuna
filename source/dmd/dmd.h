




#ifndef DMD_H
#define DMD_H

#include <stdint.h>
#include "dmd_cnfg.h"
#include "gpio.h"


#define SHIFTER_WIDE 		8
#define PIXELS_HEIGHT 		16
#define PIXELS_WIDE			32

#define SCANNER_TIMING 		30

#define RAM_FOOTPRINT_MODULE 	((16*32)/8)
#define ARRAY_LENGTH_MODULE 	RAM_FOOTPRINT_MODULE/4

#define DOT_ACROSS_WIDE 		(32*DISPLAY_WIDE)
#define DOT_ACROSS_HIGH			(16*DISPLAY_HIGH)


#define MAXIMUM_X_AXIS_INDEX	(DOT_ACROSS_WIDE - 1)
#define MAXIMUM_Y_AXIS_INDEX	(DOT_ACROSS_HIGH - 1)


//display screen (and subscreen) sizing
#define DMD_PIXELS_ACROSS         32      //pixels across x axis (base 2 size expected)
#define DMD_PIXELS_DOWN           16      //pixels down y axis
#define DMD_BITSPERPIXEL           1      //1 bit per pixel, use more bits to allow for pwm screen brightness control
#define DMD_RAM_SIZE_charS        ((DMD_PIXELS_ACROSS*DMD_BITSPERPIXEL/8)*DMD_PIXELS_DOWN)
                                  // (32x * 1 / 8) = 4 chars, * 16y = 64 chars per screen here.
//lookup table for DMD::writePixel to make the pixel indexing routine faster


// Font Indices
#define FONT_LENGTH             0
#define FONT_FIXED_WIDTH        2
#define FONT_HEIGHT             3
#define FONT_FIRST_CHAR         4
#define FONT_CHAR_COUNT         5
#define FONT_WIDTH_TABLE        6


#define TRUE 1
#define FALSE 0


#define GRAPHICS_NORMAL    0
#define GRAPHICS_INVERSE   1
#define GRAPHICS_TOGGLE    2
#define GRAPHICS_OR        3
#define GRAPHICS_NOR       4







typedef void * DmdHandle;

typedef struct
{
	uint8_t prvScreen[4][512];
	uint8_t screen[4][512];
	uint32_t DisplaysWide;
	uint32_t DisplaysHigh;
	uint32_t DisplaysTotal;
	uint32_t bChars;
	//Pointer to current font
	const uint8_t* Font;

	uint32_t screen_height;
	uint32_t screen_length;

	uint32_t byte_counter;
	uint32_t bit_counter;


	uint16_t * port;
	PinHandle connector_oe_pin;
	PinHandle connector_address_a_pin;
	PinHandle connector_address_b_pin;
	PinHandle connector_strobe_pin;
	PinHandle connector_sck_pin;
}Dmd;


DmdHandle InitDmdModule();
void DrawPattern(DmdHandle dmd, const void * pattern, uint32_t x, uint32_t y);
void ClearScreen(DmdHandle dmd);
void FlushScreen(DmdHandle dmd);
int StringWidth(char * str);
//Set or clear a pixel at the x and y location (0,0 is the top left corner)
void writePixel( DmdHandle handle, unsigned int x, unsigned int y, char bGraphicsMode, char pixel_value );

//Draw a string
void drawString( DmdHandle handle, int bX, int bY, const char* bChars, char length, char bGraphicsMode);

//Select a text font
void selectFont(DmdHandle handle, const uint8_t* font);

//Draw a single character
int drawChar(DmdHandle handle, const int bX, const int bY, const char letter, char bGraphicsMode);

//Find the width of a character
int charWidth(DmdHandle handle, const char letter);

//Draw or clear a line from x1,y1 to x2,y2
void drawLine( DmdHandle handle, int x1, int y1, int x2, int y2, char bGraphicsMode );

//Draw or clear a circle of radius r at x,y centre
void drawCircle( DmdHandle handle, int xCenter, int yCenter, int radius, char bGraphicsMode );

//Draw or clear a box(rectangle) with a single pixel border
void drawBox( DmdHandle handle, int x1, int y1, int x2, int y2, char bGraphicsMode );

//Draw or clear a filled box(rectangle) with a single pixel border
void drawFilledBox( DmdHandle handle, int x1, int y1, int x2, int y2, char bGraphicsMode );
void drawCircleSub( DmdHandle handle, int cx, int cy, int x, int y, char bGraphicsMode );

uint32_t GetBaseAddress();

#endif //DMD_H
