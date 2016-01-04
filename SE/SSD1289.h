/* -----------------------------------------------------------------------------

SSD1289 based display driver

Copyright (C) 2013  Fabio Angeletti - fabio.angeletti89@gmail.com

Part of this code is an adaptation from souce code provided by
		WaveShare - http://www.waveshare.net

Part of this code is an adaptation from souce code provided by
		Michael Margolis - https://code.google.com/p/glcd-arduino/

I'm not the owner of the whole code

------------------------------------------------------------------------------*/

#ifndef __SSD1289_H 
#define __SSD1289_H

/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include "stm32f4xx.h"
#include "AsciiLib.h"
#include "stm32f4xx_gpio.h"

/* Private define ------------------------------------------------------------*/

//#define DISP_HOR_RESOLUTION				320
//#define DISP_VER_RESOLUTION				240

//#define DISP_ORIENTATION					0
#define DISP_ORIENTATION					90
//#define DISP_ORIENTATION					180
//#define DISP_ORIENTATION					270

/* Private define ------------------------------------------------------------*/

#if  ( DISP_ORIENTATION == 90 ) || ( DISP_ORIENTATION == 270 )

#define  MAX_X  320
#define  MAX_Y  240   

#elif  ( DISP_ORIENTATION == 0 ) || ( DISP_ORIENTATION == 180 )

#define  MAX_X  240
#define  MAX_Y  320   

#endif

/* PORTs and PINs definitions ------------------------------------------------*/
#define SSD1289_CTRL_PORT			GPIOD
#define SSD1289_DATA_PORT			GPIOE
#define SSD1289_BACKLIGHT_PORT		GPIOA

#define SSD1289_CS_PIN				GPIO_Pin_14
#define SSD1289_RS_PIN				GPIO_Pin_15
#define SSD1289_nWR_PIN				GPIO_Pin_12
#define SSD1289_nRD_PIN				GPIO_Pin_13
#define SSD1289_RESET_PIN			GPIO_Pin_11
#define SSD1289_BACKLIGHT_PIN		GPIO_Pin_0


#define Set_Cs        			GPIO_SetBits(SSD1289_CTRL_PORT, SSD1289_CS_PIN)
#define Clr_Cs        			GPIO_ResetBits(SSD1289_CTRL_PORT, SSD1289_CS_PIN)

#define Set_Rs        			GPIO_SetBits(SSD1289_CTRL_PORT, SSD1289_RS_PIN)
#define Clr_Rs        			GPIO_ResetBits(SSD1289_CTRL_PORT, SSD1289_RS_PIN)

#define Set_nWr       			GPIO_SetBits(SSD1289_CTRL_PORT, SSD1289_nWR_PIN)
#define Clr_nWr       			GPIO_ResetBits(SSD1289_CTRL_PORT, SSD1289_nWR_PIN)

#define Set_nRd       			GPIO_SetBits(SSD1289_CTRL_PORT, SSD1289_nRD_PIN)
#define Clr_nRd       			GPIO_ResetBits(SSD1289_CTRL_PORT, SSD1289_nRD_PIN)

#define Set_Reset       		GPIO_SetBits(SSD1289_CTRL_PORT, SSD1289_RESET_PIN)
#define Clr_Reset       		GPIO_ResetBits(SSD1289_CTRL_PORT, SSD1289_RESET_PIN)

#define Set_Backlight       	GPIO_SetBits(SSD1289_BACKLIGHT_PORT, SSD1289_BACKLIGHT_PIN)
#define Clr_Backlight       	GPIO_ResetBits(SSD1289_BACKLIGHT_PORT, SSD1289_BACKLIGHT_PIN)

/* 16bit RGB565 colors */
#define White          0xFFFF
#define Black          0x0000
#define Grey           0xF7DE
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

	// macro to convert RGB color in 565RGB format
#define RGB565CONVERT(red, green, blue) (int) (((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3))

/* Function prototypes -------------------------------------------------------*/
	// controller initialization
void 		SSD1289_Init(void);
	// fills screen with chosen color
void 		SSD1289_Clear(uint16_t Color);	

void        SSD1289_ClearLine(uint16_t Xpos, uint16_t Ypos, uint16_t Color);

	// return the color of requested point
uint16_t 	SSD1289_GetPoint(uint16_t Xpos, uint16_t Ypos);
	// places a point with selected color
void 		SSD1289_SetPoint(uint16_t Xpos, uint16_t Ypos, uint16_t point);

	// writes a character with background using default font
void 		SSD1289_PutChar(uint16_t Xpos, uint16_t Ypos, uint8_t ASCI, uint16_t charColor, uint16_t bkColor);
	// writes a character without background using default font
void 		SSD1289_CleanPutChar( uint16_t Xpos, uint16_t Ypos, uint8_t ASCI, uint16_t charColor);
	// writes a string with background using default font
void 		SSD1289_Text(uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t Color, uint16_t bkColor);
	// writes a string without background using default font
void 		SSD1289_CleanText(uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t Color);

	// draws a picture saved as 16bit array
void 		SSD1289_DrawPicture(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t *pic);
	// draws a picture saved as 2x8bit array
void 		SSD1289_DrawPicture8bit(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t *pic);

	// writes a character with background using selected font
void 		SSD1289_PutCharFont(uint16_t Xpos, uint16_t Ypos, uint8_t ASCI, uint16_t charColor, uint16_t bkColor, uint16_t FONTx);
	// writes a character without background using selected font
void 		SSD1289_CleanPutCharFont( uint16_t Xpos, uint16_t Ypos, uint8_t ASCI, uint16_t charColor, uint16_t FONTx);
	// writes a string with background using selected font
void 		SSD1289_TextFont(uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t Color, uint16_t bkColor, uint16_t FONTx);
	// writes a string without background using selected font
void 		SSD1289_CleanTextFont(uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t Color, uint16_t FONTx);

	// draws a line starting at x0,y0 and ending at x1,y1 with selected color
void 		SSD1289_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 , uint16_t color );
	// draws a circle with center x0,y0 radius r and selected color
void 		SSD1289_DrawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
	// draws a filled circle with center x0,y0 radius r and selected color
void 		SSD1289_FillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
	// draws a rectangle starting at x,y with width w and height h with selected color
void 		SSD1289_DrawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
	// draws a filled rectangle starting at x,y with width w and height h with selected color
void 		SSD1289_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
	// draws a triangle with coordinates x0,y0 x1,y1 x2,y2 with selected color
void 		SSD1289_DrawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
	// draws a crosshair at Xpos,Ypos with 2 selected colors
void 		SSD1289_DrawCross(uint16_t Xpos, uint16_t Ypos, uint16_t in_color, uint16_t out_color);
	// backlight ON/OFF
void		SSD1289_Backlight(uint32_t val);


	// controller specific functions - should not be used outside
__inline void SSD1289_WriteIndex(uint16_t index);
__inline void SSD1289_WriteData(uint16_t data);
__inline uint16_t SSD1289_ReadData(void);
__inline uint16_t SSD1289_ReadReg(uint16_t SSD1289_Reg);
__inline void SSD1289_WriteReg(uint16_t SSD1289_Reg,uint16_t SSD1289_RegValue);
//static void SSD1289_SetCursor( uint16_t Xpos, uint16_t Ypos );

#endif 
