


#include "STM32f10x.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dmd.h"
#include "dmd_cnfg.h"
//#include "arial15.h"
#include "STM32f10x_gpio.h"
#include "STM32f10x_rcc.h"
#include "arial16.h"
//#include "dma.h"

void DisplayScanner();
Dmd prv_dmd;
DmdHandle InitDmdModule()
{
	DmdHandle newdmd;
	Dmd * dmd = &prv_dmd;
	dmd->DisplaysHigh = DISPLAY_HIGH;
	dmd->DisplaysWide = DISPLAY_WIDE;
	dmd->DisplaysTotal = dmd->DisplaysHigh * dmd->DisplaysWide;
	newdmd = dmd;
	dmd->screen_height = 16 * DISPLAY_HIGH;
	dmd->screen_length = 32 * DISPLAY_WIDE;
	dmd->byte_counter = 0;
	dmd->bit_counter = 0;

	dmd->Font = arial16;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef config;
	config.GPIO_Mode = GPIO_Mode_Out_PP;
	config.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	config.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &config);



	dmd->port = (uint16_t *) GPIOA->ODR;
	dmd->bChars = 0;
	dmd->connector_address_a_pin 	= InitPin(CONNECTOR1_A_PORT, CONNECTOR1_A_PIN, OUTPUT);
	dmd->connector_address_b_pin 	= InitPin(CONNECTOR1_B_PORT, CONNECTOR1_B_PIN, OUTPUT);
	dmd->connector_oe_pin 			= InitPin(CONNECTOR1_OE_PORT, CONNECTOR1_OE_PIN, OUTPUT);
	dmd->connector_strobe_pin 		= InitPin(CONNECTOR1_STROBE_PORT, CONNECTOR1_STROBE_PIN, OUTPUT);
	dmd->connector_sck_pin 			= InitPin(CONNECTOR1_SCK_PORT, CONNECTOR1_SCK_PIN, OUTPUT);
	ClearScreen(newdmd);
	FlushScreen(newdmd);
//	printf("Dmd Initialisation finished.\r\n");
	return newdmd;

}




void ClearScreen(DmdHandle dmd)
{
	Dmd * _dmd = (Dmd *) dmd;
	for (int i = 0; i < 4; ++i) {
		memset((void *)_dmd->screen[i], 0xFF, 512);
	}

}

void FlushScreen(DmdHandle dmd)
{
	Dmd * _dmd = (Dmd *) dmd;
	for(int i = 0; i< 4; i++)
	{
		memcpy((void *)_dmd->prvScreen[i], (void *)_dmd->screen[i], 512);
	}


}



void writePixel( DmdHandle handle, unsigned int x, unsigned int y, char bGraphicsMode, char pixel_value )
{
	Dmd * _dmd = (Dmd *) handle;
	if (x >= (DMD_PIXELS_ACROSS*_dmd->DisplaysWide) || y >= DMD_PIXELS_DOWN * _dmd->DisplaysHigh)
		return;
	uint32_t array_index = 0;
	uint32_t array_number = 0;
	uint8_t bit_position = 0;

	//x = x -(32 * DISPLAY_WIDE-1);

	array_number = y%4;
	bit_position = (y/16);
	y = y%16;
	y = 15- y;
	array_index = (x/8) * 32 + (y/4) * 8 + x % 8;




	switch(bGraphicsMode)
	{
	case GRAPHICS_NORMAL:
		if (pixel_value == 0) {
			_dmd->screen[array_number][array_index] |= (1 << bit_position);
		}
		else {
			_dmd->screen[array_number][array_index] &= ~ (1 << bit_position);
		}
		break;

	case GRAPHICS_INVERSE:
		if (pixel_value == 1) {
			_dmd->screen[array_number][array_index] |= (1 << bit_position);
		}
		else {
			_dmd->screen[array_number][array_index] &= ~ (1 << bit_position);
		}
		break;
	default:
		break;
	}
}







void DisplayScanner()
{
	Dmd * dmd = (Dmd *) &prv_dmd;
//	for (int i = 0; i < 512; i++) {
//		//SetPinState(dmd->connector_strobe_pin, LOW);
//		SetPinState(dmd->connector_sck_pin, LOW);
//		GPIOA->ODR = dmd->prvScreen[dmd->bChars][i];
//		//__NOP();
//		//__NOP();
//		SetPinState(dmd->connector_sck_pin, HIGH);
//		//GPIOA->ODR = 0;
//		//__NOP();
//		//__NOP();
//	}



//	SetPinState(dmd->connector_oe_pin, LOW);

	SetPinState(dmd->connector_strobe_pin,HIGH );




	switch(dmd->bChars)
	{
		case 0:
			dmd->bChars = 1;
			SetPinState(dmd->connector_address_a_pin, LOW);
			SetPinState(dmd->connector_address_b_pin, LOW);

			break;
		case 1:
			SetPinState(dmd->connector_address_a_pin, HIGH);
			SetPinState(dmd->connector_address_b_pin, LOW);

			dmd->bChars = 2;
			break;
		case 2:
			SetPinState(dmd->connector_address_a_pin, LOW);
			SetPinState(dmd->connector_address_b_pin, HIGH);
			dmd->bChars = 3;
			break;
		case 3:
			dmd->bChars = 0;
			SetPinState(dmd->connector_address_a_pin, HIGH);
			SetPinState(dmd->connector_address_b_pin, HIGH);
			break;
		default:
			break;
	}

//	SetPinState(dmd->connector_oe_pin, HIGH);
	SetPinState(dmd->connector_strobe_pin, LOW);
}


uint32_t GetBaseAddress()
{
	return (uint32_t)prv_dmd.prvScreen[prv_dmd.bChars];
}

//void TIM2_IRQHandler(void)
//{
//  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//  {
//    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//    DisplayScanner();
//  }
//}


void drawString(DmdHandle handle, int bX, int bY, const char* bChars, char length,
		     char bGraphicsMode)
{
	if (handle==0)
	{
		return;
	}


	Dmd * dmd= (Dmd * ) handle;
//	if (bX >= (DMD_PIXELS_ACROSS*dmd->DisplaysWide) || bY >= DMD_PIXELS_DOWN * dmd->DisplaysHigh)
//	return;
    uint8_t height = *(dmd->Font + FONT_HEIGHT);
    if (bY+height<0) return;

    int strWidth = 0;
	//drawLine(handle,bX -1 , bY, bX -1 , bY + height, GRAPHICS_INVERSE);

    for (int i = 0; i < length; i++) {
        int charWide = drawChar(handle, bX+strWidth, bY, bChars[i], bGraphicsMode);
	    if (charWide > 0) {
	        strWidth += charWide ;
	        //drawLine(handle,bX + strWidth , bY, bX + strWidth , bY + height, GRAPHICS_NORMAL);
            strWidth++;
        } else if (charWide < 0) {
            return;
        }
        //if ((bX + strWidth) >= DMD_PIXELS_ACROSS * dmd->DisplaysWide || bY >= DMD_PIXELS_DOWN * dmd->DisplaysHigh) return;
    }
}


/*--------------------------------------------------------------------------------------
 Draw or clear a line from x1,y1 to x2,y2
--------------------------------------------------------------------------------------*/
void drawLine(DmdHandle handle, int x1, int y1, int x2, int y2, char bGraphicsMode)
{
	if (handle==0)
	{
		return;
	}

    int dy = y2 - y1;
    int dx = x2 - x1;
    int stepx, stepy;

    if (dy < 0) {
	    dy = -dy;
	    stepy = -1;
    } else {
	    stepy = 1;
    }
    if (dx < 0) {
	    dx = -dx;
	    stepx = -1;
    } else {
	    stepx = 1;
    }
    dy <<= 1;			// dy is now 2*dy
    dx <<= 1;			// dx is now 2*dx

    writePixel(handle, x1, y1, bGraphicsMode, TRUE);
    if (dx > dy) {
	    int fraction = dy - (dx >> 1);	// same as 2*dy - dx
	    while (x1 != x2) {
	        if (fraction >= 0) {
		        y1 += stepy;
		        fraction -= dx;	// same as fraction -= 2*dx
	        }
	        x1 += stepx;
	        fraction += dy;	// same as fraction -= 2*dy
	        writePixel(handle, x1, y1, bGraphicsMode, TRUE);
	    }
    } else {
	    int fraction = dx - (dy >> 1);
	    while (y1 != y2) {
	        if (fraction >= 0) {
		        x1 += stepx;
		        fraction -= dy;
	        }
	        y1 += stepy;
	        fraction += dx;
	        writePixel(handle, x1, y1, bGraphicsMode, TRUE);
	    }
    }
}

/*--------------------------------------------------------------------------------------
 Draw or clear a circle of radius r at x,y centre
--------------------------------------------------------------------------------------*/
void drawCircle(DmdHandle handle, int xCenter, int yCenter, int radius,
		     char bGraphicsMode)
{
	if (handle==0)
	{
		return;
	}

    int x = 0;
    int y = radius;
    int p = (5 - radius * 4) / 4;

    drawCircleSub(handle, xCenter, yCenter, x, y, bGraphicsMode);
    while (x < y) {
	    x++;
	    if (p < 0) {
	        p += 2 * x + 1;
	    } else {
	        y--;
	        p += 2 * (x - y) + 1;
	    }
	    drawCircleSub(handle, xCenter, yCenter, x, y, bGraphicsMode);
    }
}

void drawCircleSub(DmdHandle handle, int cx, int cy, int x, int y, char bGraphicsMode)
{
	if (handle==0)
	{
		return;
	}

    if (x == 0) {
	    writePixel(handle, cx, cy + y, bGraphicsMode, TRUE);
	    writePixel(handle, cx, cy - y, bGraphicsMode, TRUE);
	    writePixel(handle, cx + y, cy, bGraphicsMode, TRUE);
	    writePixel(handle, cx - y, cy, bGraphicsMode, TRUE);
    } else if (x == y) {
	    writePixel(handle, cx + x, cy + y, bGraphicsMode, TRUE);
	    writePixel(handle, cx - x, cy + y, bGraphicsMode, TRUE);
	    writePixel(handle, cx + x, cy - y, bGraphicsMode, TRUE);
	    writePixel(handle, cx - x, cy - y, bGraphicsMode, TRUE);
    } else if (x < y) {
	    writePixel(handle, cx + x, cy + y, bGraphicsMode, TRUE);
	    writePixel(handle, cx - x, cy + y, bGraphicsMode, TRUE);
	    writePixel(handle, cx + x, cy - y, bGraphicsMode, TRUE);
	    writePixel(handle, cx - x, cy - y, bGraphicsMode, TRUE);
	    writePixel(handle, cx + y, cy + x, bGraphicsMode, TRUE);
	    writePixel(handle, cx - y, cy + x, bGraphicsMode, TRUE);
	    writePixel(handle, cx + y, cy - x, bGraphicsMode, TRUE);
	    writePixel(handle, cx - y, cy - x, bGraphicsMode, TRUE);
    }
}

/*--------------------------------------------------------------------------------------
 Draw or clear a box(rectangle) with a single pixel border
--------------------------------------------------------------------------------------*/
void drawBox(DmdHandle handle, int x1, int y1, int x2, int y2, char bGraphicsMode)
{
	if (handle==0)
	{
		return;
	}

    drawLine(handle, x1, y1, x2, y1, bGraphicsMode);
    drawLine(handle, x2, y1, x2, y2, bGraphicsMode);
    drawLine(handle, x2, y2, x1, y2, bGraphicsMode);
    drawLine(handle, x1, y2, x1, y1, bGraphicsMode);
}

/*--------------------------------------------------------------------------------------
 Draw or clear a filled box(rectangle) with a single pixel border
--------------------------------------------------------------------------------------*/
void drawFilledBox(DmdHandle handle, int x1, int y1, int x2, int y2,
			char bGraphicsMode)
{
	if (handle==0)
	{
		return;
	}

    for (int b = x1; b <= x2; b++) {
	    drawLine(handle, b, y1, b, y2, bGraphicsMode);
    }
}



void selectFont(DmdHandle handle, const uint8_t* font)
{
	if (handle==0)
	{
		return;
	}
	Dmd * dmd = (Dmd *)handle;
    dmd->Font = font;
}


int drawChar(DmdHandle handle, const int bX, const int bY, const char letter, char bGraphicsMode)
{
	if (handle==0)
	{
		return 0;
	}
	Dmd * dmd = (Dmd *)handle;
    char c = letter;
    uint8_t height = *(dmd->Font + FONT_HEIGHT);
    if (c == ' ') {
	    int charWide = charWidth(handle,' ');
	    drawFilledBox(handle, bX, bY, bX + charWide, bY + height, GRAPHICS_INVERSE);
	    return charWide;
    }
    uint8_t width = 0;
    uint8_t chars = (height + 7) / 8;

    uint8_t firstChar = *(dmd->Font + FONT_FIRST_CHAR);
    uint8_t charCount = *(dmd->Font + FONT_CHAR_COUNT);

    uint16_t index = 0;

    if (c < firstChar || c >= (firstChar + charCount)) return 0;
    c -= firstChar;

    if (*(dmd->Font + FONT_LENGTH) == 0
	    && *(dmd->Font + FONT_LENGTH + 1) == 0) {
	    // zero length is flag indicating fixed width font (array does not contain width data entries)
	    width = *(dmd->Font + FONT_FIXED_WIDTH);
	    index = c * chars * width + FONT_WIDTH_TABLE;
    } else {
	    // variable width font, read width data, to get the index
	    for (uint8_t i = 0; i < c; i++) {
	        index += *(dmd->Font + FONT_WIDTH_TABLE + i);
	    }
	    index = index * chars + charCount + FONT_WIDTH_TABLE;
	    width = *(dmd->Font + FONT_WIDTH_TABLE + c);
    }
    if (bX < -width || bY < -height) return width;

    // last but not least, draw the character
    for (uint8_t j = 0; j < width; j++) { // Width
	    for (uint8_t i = chars - 1; i < 254; i--) { // Vertical chars
	        uint8_t data = *(dmd->Font + index + j + (i * width));
		    int offset = (i * 8);
		    if ((i == chars - 1) && chars > 1) {
		        offset = height - 8;
            }
	        for (uint8_t k = 0; k < 8; k++) { // Vertical bits
		        if ((offset+k >= i*8) && (offset+k <= height)) {
		            if (data & (1 << k)) {
			            writePixel(handle, bX + j, bY + offset + k, bGraphicsMode, TRUE);
		            } else {
			            writePixel(handle, bX + j, bY + offset + k, bGraphicsMode, FALSE);
		            }
		        }
	        }
	    }
    }
    return width;
}

int charWidth(DmdHandle handle, const char letter)
{
	if (handle==0)
	{
		return 0;
	}
	Dmd * dmd = (Dmd *)handle;
    char c = letter;
    // Space is often not included in font so use width of 'n'
    if (c == ' ') c = 'e';
    uint8_t width = 0;

    uint8_t firstChar = *(dmd->Font + FONT_FIRST_CHAR);
    uint8_t charCount = *(dmd->Font + FONT_CHAR_COUNT);

    //uint16_t index = 0;

    if (c < firstChar || c >= (firstChar + charCount)) {
	    return 0;
    }
    c -= firstChar;

    if (*(dmd->Font + FONT_LENGTH) == 0
	&& *(dmd->Font + FONT_LENGTH + 1) == 0) {
	    // zero length is flag indicating fixed width font (array does not contain width data entries)
	    width = *(dmd->Font + FONT_FIXED_WIDTH);
    } else {
	    // variable width font, read width data
	    width = *(dmd->Font + FONT_WIDTH_TABLE + c);
    }
    return width;
}


int StringWidth(char * str)
{
	int length = 0;

	while(*str != 0)
	{
		length += charWidth(&prv_dmd, *str);
		str++;
		length++;
	}
	return length;
}

//static char * storage = NULL;
//
//char * ReadLine(char * str)
//{
//	if (str == NULL) {
//		if (storage ==NULL) {
//			return NULL;
//		}
//		str = storage;
//	}
//	else {
//		storage = str;
//	}
//	char * temp = storage;
//	int length = 0;
//	if (str == NULL) {
//		return NULL;
//	}
//
//	while(1)
//	{
//		if (*str == '\r' || *str == '\n' || *str == 0) {
//			if (length != 0) {
//				*str = 0;
//				storage = str+1;
//				return temp;
//			}
//			else {
//				temp++;
//				str++;
//				continue;
//			}
//		}
//		str++;
//		length++;
//	}
//	return NULL;
//}
//
//
//
//typedef enum
//{
//	OBJECT_LINE,
//	OBJECT_RECTANGAL,
//	OBJECT_CIRCLE,
//	OBJECT_TEXT,
//	OBJECT_DOT
//}ObjectPrimitive;
//
//
//
//typedef struct
//{
//	int x;
//	int y;
//}Point;
//
//typedef struct
//{
//	Point location;
//	int length;
//	int thickness;
//}Line;
//
//#define NORMAL 		0
//#define ITALIC 		1
//#define BOLD 		2
//#define UNDERLINE 	4
//
//typedef struct
//{
//	char * name;
//	int style;
//	int size;
//}Font;
//
//typedef enum
//{
//	HORIZONTAL,
//	VERTICAL
//}Alignment;
//
//typedef struct
//{
//	Point location;
//	Font font;
//	Alignment alignment;
//	char * string;
//}Text;
//
//
//typedef struct
//{
//	Point center;
//	int radius;
//}Circle;
//
//typedef struct
//{
//	Point center;
//	int xRadius;
//	int yRadius;
//}Ellipse;
//
//
//
//typedef struct
//{
//	void * object;
//	ObjectPrimitive object_type;
//}Object;
//
//
//void SetAttribute(Object * obj, char * attr_name, char * attr_value)
//{
//	switch (obj->object_type) {
//		case OBJECT_LINE:
//
//			break;
//		case OBJECT_CIRCLE:
//
//			break;
//		case OBJECT_DOT:
//
//			break;
//		case OBJECT_RECTANGAL:
//
//			break;
//		case OBJECT_TEXT:
//
//			break;
//		default:
//			break;
//	}
//}
//
//
//#include "yxml.h"
//
//char xml_buffer[4*1024];
//
//
//void ProcesXml(char * layout_xml)
//{
//	char temp[100];
//	int temp_index = 0;
//	yxml_ret_t ret;
//	yxml_t xml;
//	memset(&xml, 0, sizeof(yxml_t));
//	memset(xml_buffer, 0, sizeof(xml_buffer));
//	yxml_init(&xml, xml_buffer, sizeof(xml_buffer));
//	//render your layout here.
//	if (layout_xml == NULL) {
//		return;
//	}
//
//	char * str = layout_xml;
//
//	while(*str != 0)
//	{
//		ret = yxml_parse(&xml,*str);
//
//		switch(ret)
//		{
//		case YXML_ATTREND:
//			printf("Attribute: <%s : %s>\r\n", xml.attr, temp);
//			//printf("ATTREND return.\r\n");
//			break;
//		case YXML_ATTRSTART:
//			temp_index = 0;
//			memset(temp, 0, 100);
//			//printf("ATTRSTART return.\r\n");
//			break;
//		case YXML_ATTRVAL:
//			temp[temp_index++] = *str;
//			//printf("ATTRVAL return.\r\n");
//			break;
//		case YXML_CONTENT:
//			//printf("CONTENT return.\r\n");
//			break;
//		case YXML_ECLOSE:
//			printf("ECLOSE return.\r\n");
//			return;
//			break;
//		case YXML_EEOF:
//			printf("EEOF return.\r\n");
//			return;
//			break;
//		case YXML_ELEMEND:
//			printf("Element Closed.\r\n");
//			//printf("ELEMEND return.\r\n");
//			break;
//		case YXML_ELEMSTART:
//			printf("Element Opened: <%s>\r\n",xml.elem);
//			//printf("ELEMSTART return.\r\n");
//			break;
//		case YXML_EREF:
//			printf("EREF return.\r\n");
//			return;
//			break;
//		case YXML_ESTACK:
//			printf("ESTACK return.\r\n");
//			return;
//			break;
//		case YXML_ESYN:
//			printf("ESYN return.\r\n");
//			return;
//			break;
//		case YXML_OK:
//
//			//printf("OK return.\r\n");
//			break;
//		case YXML_PICONTENT:
//			printf("PICONTENT return.\r\n");
//			break;
//		case YXML_PIEND:
//			printf("PIEND return.\r\n");
//			break;
//		case YXML_PISTART:
//			printf("PISTART return.\r\n");
//			break;
//		default:
//			printf("Unknown type return.\r\n");
//			break;
//		}
//
//		str++;
//	}
//}
//
//
//void RemoveHtmlTag(char * str)
//{
//	char * formatted_str = str;
//	char * lookup_str = str;
//
//	while(*lookup_str != 0)
//	{
//		if (*lookup_str == '%') {
//			if (lookup_str[1] == '2' && lookup_str[2] == '0') {
//				*formatted_str = ' ';
//				formatted_str++;
//			}
//			lookup_str+=2;
//		}
//		else {
//			*formatted_str = *lookup_str;
//			formatted_str++;
//		}
//
//
//		lookup_str++;
//	}
//	*formatted_str = 0;
//}
//
//int CorrectAlignment(char * str, int fpos, int lpos)
//{
//	int length = StringWidth(str);
//	printf("Length of current line: %d pixels\r\n", length);
//
//	if (length <= lpos - fpos) {
//		fpos = fpos + (((lpos - fpos)-length) /2);
//		printf("Text will be drawn at %d x index.\r\n", fpos);
//		return fpos;
//
//	}
//	else {
//		printf("Content out of TextBox.\r\n");
//	}
//	return fpos;
//}
//
//uint32_t RenderLayout(char * layout_xml)
//{
//	ClearScreen(&prv_dmd);
//	char * line_list[20];
//	RemoveHtmlTag(layout_xml);
//	if (SplitString(layout_xml, '*', line_list) == 11) {
//		drawLine(&prv_dmd, 0, 0, MAX_X_INDEX, 0, GRAPHICS_NORMAL);
//		drawLine(&prv_dmd, MAX_X_INDEX, 0, MAX_X_INDEX, 176, GRAPHICS_NORMAL);
//
//		int line_no = 0;
//
//		printf("Content on %dst line: <%s>\r\n",line_no+1, line_list[line_no]);
//		drawString(&prv_dmd, CorrectAlignment(line_list[line_no], 0, MAX_X_INDEX)+ LEFT_MARGIN,16*line_no + TOP_MARGIN, line_list[line_no], strlen(line_list[line_no]), GRAPHICS_NORMAL);
//
//
//		line_no = 1;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dnd line: <%s>\r\n",line_no+1, line_list[line_no]);
//		drawString(&prv_dmd, CorrectAlignment(line_list[line_no], 0, MAX_X_INDEX)+ LEFT_MARGIN,16*line_no + TOP_MARGIN, line_list[line_no], strlen(line_list[line_no]), GRAPHICS_NORMAL);
//
//		line_no = 2;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %drd line: <%s>\r\n",line_no+1, line_list[line_no]);
//		drawString(&prv_dmd, CorrectAlignment(line_list[line_no], 0, MAX_X_INDEX)+ LEFT_MARGIN,16*line_no + TOP_MARGIN, line_list[line_no], strlen(line_list[line_no]), GRAPHICS_NORMAL);
//
//		char * field_list[5];
//
//		line_no = 3;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		if (SplitString(line_list[line_no], ',', field_list) == 3) {
//			drawString(&prv_dmd, CorrectAlignment(field_list[0], 0, SECOND_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[0], strlen(field_list[0]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,SECOND_COLUMN_POSITION,16*line_no,SECOND_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[1], SECOND_COLUMN_POSITION, THIRD_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[1], strlen(field_list[1]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,THIRD_COLUMN_POSITION,16*line_no,THIRD_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[2], THIRD_COLUMN_POSITION, MAX_X_INDEX) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[2], strlen(field_list[2]), GRAPHICS_NORMAL);
//		}
//		else {
//			return 0;
//		}
//
//		line_no = 4;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		drawString(&prv_dmd, CorrectAlignment(line_list[line_no], 0, MAX_X_INDEX)+ LEFT_MARGIN,16*4 + TOP_MARGIN, line_list[line_no], strlen(line_list[line_no]), GRAPHICS_NORMAL);
//
//		line_no = 5;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		if (SplitString(line_list[line_no], ',', field_list) == 3) {
//			drawString(&prv_dmd, CorrectAlignment(field_list[0], 0, SECOND_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[0], strlen(field_list[0]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,SECOND_COLUMN_POSITION,16*line_no,SECOND_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[1], SECOND_COLUMN_POSITION, THIRD_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[1], strlen(field_list[1]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,THIRD_COLUMN_POSITION,16*line_no,THIRD_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[2], THIRD_COLUMN_POSITION, MAX_X_INDEX) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[2], strlen(field_list[2]), GRAPHICS_NORMAL);
//		}
//		else {
//			return 0;
//		}
//
//		line_no = 6;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		if (SplitString(line_list[line_no], ',', field_list) == 3) {
//			drawString(&prv_dmd, CorrectAlignment(field_list[0], 0, SECOND_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[0], strlen(field_list[0]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,SECOND_COLUMN_POSITION,16*line_no,SECOND_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[1], SECOND_COLUMN_POSITION, THIRD_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[1], strlen(field_list[1]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,THIRD_COLUMN_POSITION,16*line_no,THIRD_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[2], THIRD_COLUMN_POSITION, MAX_X_INDEX) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[2], strlen(field_list[2]), GRAPHICS_NORMAL);
//		}
//		else {
//			return 0;
//		}
//
//		line_no = 7;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		if (SplitString(line_list[line_no], ',', field_list) == 3) {
//			drawString(&prv_dmd, CorrectAlignment(field_list[0], 0, SECOND_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[0], strlen(field_list[0]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,SECOND_COLUMN_POSITION,16*line_no,SECOND_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[1], SECOND_COLUMN_POSITION, THIRD_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[1], strlen(field_list[1]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,THIRD_COLUMN_POSITION,16*line_no,THIRD_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[2], THIRD_COLUMN_POSITION, MAX_X_INDEX) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[2], strlen(field_list[2]), GRAPHICS_NORMAL);
//		}
//		else {
//			return 0;
//		}
//
//		line_no = 8;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		if (SplitString(line_list[line_no], ',', field_list) == 3) {
//			drawString(&prv_dmd, CorrectAlignment(field_list[0], 0, SECOND_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[0], strlen(field_list[0]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,SECOND_COLUMN_POSITION,16*line_no,SECOND_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[1], SECOND_COLUMN_POSITION, THIRD_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[1], strlen(field_list[1]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,THIRD_COLUMN_POSITION,16*line_no,THIRD_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[2], THIRD_COLUMN_POSITION, MAX_X_INDEX) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[2], strlen(field_list[2]), GRAPHICS_NORMAL);
//		}
//		else {
//			return 0;
//		}
//
//		line_no = 9;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		if (SplitString(line_list[line_no], ',', field_list) == 3) {
//			drawString(&prv_dmd, CorrectAlignment(field_list[0], 0, SECOND_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[0], strlen(field_list[0]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,SECOND_COLUMN_POSITION,16*line_no,SECOND_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[1], SECOND_COLUMN_POSITION, THIRD_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[1], strlen(field_list[1]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,THIRD_COLUMN_POSITION,16*line_no,THIRD_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[2], THIRD_COLUMN_POSITION, MAX_X_INDEX) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[2], strlen(field_list[2]), GRAPHICS_NORMAL);
//		}
//		else {
//			return 0;
//		}
//
//		line_no = 10;
//		drawLine(&prv_dmd,0,16*line_no,MAX_X_INDEX,16*line_no, GRAPHICS_NORMAL);
//		printf("Content on %dth line: <%s>\r\n",line_no+1, line_list[line_no]);
//		if (SplitString(line_list[line_no], ',', field_list) == 3) {
//			drawString(&prv_dmd, CorrectAlignment(field_list[0], 0, SECOND_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[0], strlen(field_list[0]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,SECOND_COLUMN_POSITION,16*line_no,SECOND_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[1], SECOND_COLUMN_POSITION, THIRD_COLUMN_POSITION) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[1], strlen(field_list[1]), GRAPHICS_NORMAL);
//			drawLine(&prv_dmd,THIRD_COLUMN_POSITION,16*line_no,THIRD_COLUMN_POSITION,16*(line_no+1), GRAPHICS_NORMAL);
//			drawString(&prv_dmd, CorrectAlignment(field_list[2], THIRD_COLUMN_POSITION, MAX_X_INDEX) + LEFT_MARGIN,16*line_no + TOP_MARGIN, field_list[2], strlen(field_list[2]), GRAPHICS_NORMAL);
//		}
//		else {
//			return 0;
//		}
//
//		drawLine(&prv_dmd, 0, 176, MAXIMUM_X_AXIS_INDEX, 176, GRAPHICS_NORMAL);
//		drawLine(&prv_dmd, 0, 0, 0, 176, GRAPHICS_NORMAL);
//
//
//		FlushScreen(&prv_dmd);
//		return 1;
//	}
//	return 0;
//}
