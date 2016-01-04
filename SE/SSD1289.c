/* -----------------------------------------------------------------------------

SSD1289 based display driver

Copyright (C) 2013  Fabio Angeletti - fabio.angeletti89@gmail.com

Part of this code is an adaptation from souce code provided by
        WaveShare - http://www.waveshare.net

Part of this code is an adaptation from souce code provided by
        Michael Margolis - https://code.google.com/p/glcd-arduino/

I'm not the owner of the whole code

------------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "SSD1289.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
/* Functions -----------------------------------------------------------------*/
static void SSD1289_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Enable clocks */
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);  
	       
    /* configure DATA PORT  pins*/             
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(SSD1289_DATA_PORT, &GPIO_InitStructure);

    /* configure CONTROL PORT pins */
	GPIO_InitStructure.GPIO_Pin = SSD1289_RESET_PIN | SSD1289_nWR_PIN | SSD1289_nRD_PIN | SSD1289_CS_PIN | SSD1289_RS_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(SSD1289_CTRL_PORT, &GPIO_InitStructure);
	
    /* configure BACKLIGHT pin */
	GPIO_InitStructure.GPIO_Pin = SSD1289_BACKLIGHT_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(SSD1289_BACKLIGHT_PORT, &GPIO_InitStructure);
}

__inline void SSD1289_WriteIndex(uint16_t index)
{
	Clr_Rs;
	Set_nRd;
	
	GPIOE->ODR = index;	 /* GPIO_Write(GPIOE,index); */
	
	Clr_nWr;
	Set_nWr;
}

__inline void SSD1289_WriteData(uint16_t data)
{
	Set_Rs;
	
	GPIOE->ODR = data;	 /* GPIO_Write(GPIOE,data); */
	
	Clr_nWr;
	Set_nWr;
}

__inline uint16_t SSD1289_ReadData(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	uint16_t value;

	Set_Rs;
	Set_nWr;
	Clr_nRd;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_Init(SSD1289_DATA_PORT, &GPIO_InitStructure);

	value = GPIO_ReadInputData(SSD1289_DATA_PORT);
    value = GPIO_ReadInputData(SSD1289_DATA_PORT);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Init(SSD1289_DATA_PORT, &GPIO_InitStructure);

    Set_nRd;

    return value;
}

__inline void SSD1289_WriteReg(uint16_t SSD1289_Reg,uint16_t SSD1289_RegValue)
{ 
	/* Write 16-bit Index, then Write Reg */  
	Clr_Cs;
	SSD1289_WriteIndex(SSD1289_Reg);         
	/* Write 16-bit Reg */
	SSD1289_WriteData(SSD1289_RegValue);  
	Set_Cs; 
}

__inline uint16_t SSD1289_ReadReg(uint16_t SSD1289_Reg)
{
	uint16_t SSD1289_RAM;
	
	/* Write 16-bit Index (then Read Reg) */
	Clr_Cs;
	SSD1289_WriteIndex(SSD1289_Reg);
	/* Read 16-bit Reg */
	SSD1289_RAM = SSD1289_ReadData();      	
	Set_Cs;
	return SSD1289_RAM;
}

static void SSD1289_SetCursor( uint16_t Xpos, uint16_t Ypos )
{
    #if  ( DISP_ORIENTATION == 90 ) || ( DISP_ORIENTATION == 270 )
	
 	uint16_t temp = Xpos;

			 Xpos = Ypos;
			 Ypos = ( MAX_X - 1 ) - temp;  

	#elif  ( DISP_ORIENTATION == 0 ) || ( DISP_ORIENTATION == 180 )
		
	#endif

  	SSD1289_WriteReg(0x004e, Xpos );      
    SSD1289_WriteReg(0x004f, Ypos );
}

void SSD1289_Init(void)
{
	SSD1289_Configuration();
  	Clr_Reset;
	Delay(100);
  	Set_Reset;
  	Set_Backlight;

	SSD1289_WriteReg(0x0000,0x0001);    Delay(50);   /* Enable SSD1289 Oscillator */
	SSD1289_WriteReg(0x0003,0xA8A4);    Delay(50);   
	SSD1289_WriteReg(0x000C,0x0000);    Delay(50);   
	SSD1289_WriteReg(0x000D,0x080C);    Delay(50);   
	SSD1289_WriteReg(0x000E,0x2B00);    Delay(50);   
	SSD1289_WriteReg(0x001E,0x00B0);    Delay(50);   
	SSD1289_WriteReg(0x0001,0x2B3F);    Delay(50);   /* 320*240 0x2B3F */
	SSD1289_WriteReg(0x0002,0x0600);    Delay(50);
	SSD1289_WriteReg(0x0010,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0011,0x6070);    Delay(50);
	SSD1289_WriteReg(0x0005,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0006,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0016,0xEF1C);    Delay(50);
	SSD1289_WriteReg(0x0017,0x0003);    Delay(50);
	SSD1289_WriteReg(0x0007,0x0133);    Delay(50);         
	SSD1289_WriteReg(0x000B,0x0000);    Delay(50);
 	SSD1289_WriteReg(0x000F,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0041,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0042,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0048,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0049,0x013F);    Delay(50);
	SSD1289_WriteReg(0x004A,0x0000);    Delay(50);
	SSD1289_WriteReg(0x004B,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0044,0xEF00);    Delay(50);
	SSD1289_WriteReg(0x0045,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0046,0x013F);    Delay(50);
	SSD1289_WriteReg(0x0030,0x0707);    Delay(50);
	SSD1289_WriteReg(0x0031,0x0204);    Delay(50);
	SSD1289_WriteReg(0x0032,0x0204);    Delay(50);
	SSD1289_WriteReg(0x0033,0x0502);    Delay(50);
	SSD1289_WriteReg(0x0034,0x0507);    Delay(50);
	SSD1289_WriteReg(0x0035,0x0204);    Delay(50);
	SSD1289_WriteReg(0x0036,0x0204);    Delay(50);
	SSD1289_WriteReg(0x0037,0x0502);    Delay(50);
	SSD1289_WriteReg(0x003A,0x0302);    Delay(50);
	SSD1289_WriteReg(0x003B,0x0302);    Delay(50);
	SSD1289_WriteReg(0x0023,0x0000);    Delay(50);
 	SSD1289_WriteReg(0x0024,0x0000);    Delay(50);
	SSD1289_WriteReg(0x0025,0x8000);    Delay(50);
	SSD1289_WriteReg(0x004f,0);
	SSD1289_WriteReg(0x004e,0);

    Delay(50);   /* delay 50 ms */		

    SSD1289_Clear(Black);

    Delay(500); 
}

void SSD1289_Clear(uint16_t Color)
{
	uint32_t index=0;
	
	SSD1289_SetCursor(0,0); 

	Clr_Cs; 
	SSD1289_WriteIndex(0x0022);
	for( index = 0; index < MAX_X * MAX_Y; index++ )
	{
		SSD1289_WriteData(Color);
	}
	Set_Cs;
}

void SSD1289_ClearLine(uint16_t Xpos,uint16_t Ypos, uint16_t Color)
{
	uint32_t index=0;

	SSD1289_SetCursor(Xpos,Ypos);

	Clr_Cs;
	SSD1289_WriteIndex(0x0022);
	for( index = 0; index < 50 * 50; index++ )
	{
		SSD1289_WriteData(Color);
	}
	Set_Cs;
}

uint16_t SSD1289_GetPoint(uint16_t Xpos,uint16_t Ypos)
{
	uint16_t dummy;
	
	SSD1289_SetCursor(Xpos,Ypos);
	Clr_Cs;
	SSD1289_WriteIndex(0x0022);  
	dummy = SSD1289_ReadData();
    dummy = SSD1289_ReadData(); 
    Set_Cs;	
 	return  dummy;
}

void SSD1289_SetPoint(uint16_t Xpos,uint16_t Ypos,uint16_t point)
{
	if( Xpos >= MAX_X || Ypos >= MAX_Y )
	{
		return;
	}
	SSD1289_SetCursor(Xpos,Ypos);
	SSD1289_WriteReg(0x0022,point);
}

void SSD1289_DrawLine( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 , uint16_t color )
{
  short dx,dy;
  short temp;

  if( x0 > x1 )
  {
    temp = x1;
    x1 = x0;
    x0 = temp;   
  }
  if( y0 > y1 )
  {
    temp = y1;
    y1 = y0;
    y0 = temp;   
  }

  dx = x1-x0;
  dy = y1-y0;

  if( dx == 0 )
  {
    do
    { 
      SSD1289_SetPoint(x0, y0, color);
      y0++;
    }
    while( y1 >= y0 ); 
    return; 
  }
  if( dy == 0 )
  {
    do
    {
      SSD1289_SetPoint(x0, y0, color);
      x0++;
    }
    while( x1 >= x0 ); 
		return;
  }

	/* Based on Bresenham's line algorithm  */
  if( dx > dy )
  {
    temp = 2 * dy - dx;
    while( x0 != x1 )
    {
	    SSD1289_SetPoint(x0,y0,color);
	    x0++;
	    if( temp > 0 )
	    {
	      y0++;
	      temp += 2 * dy - 2 * dx; 
	 	  }
      else         
      {
			  temp += 2 * dy;
			}       
    }
    SSD1289_SetPoint(x0,y0,color);
  }  
  else
  {
    temp = 2 * dx - dy;
    while( y0 != y1 )
    {
	  SSD1289_SetPoint(x0,y0,color);     
      y0++;                 
      if( temp > 0 )           
      {
        x0++;               
        temp+=2*dy-2*dx; 
      }
      else
	  {
        temp += 2 * dy;
	  }
    } 
    SSD1289_SetPoint(x0,y0,color);
  }
} 

void SSD1289_PutChar(uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t bkColor)
{
	SSD1289_PutCharFont(Xpos, Ypos, ASCII, charColor, bkColor, SYSTEM_8x16);
}

void SSD1289_PutCharFont( uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t bkColor, uint16_t FONTx)
{
	uint16_t i, j;
    uint8_t buffer[16], tmp_char;
    uint8_t len_x, len_y;

    switch (FONTx)
    {
    	case FONT6x8:
    		len_x = 6;
    		len_y = 8;
    		break;    	
    	case FONT8x8:
    		len_x = 8;
    		len_y = 8;
    		break;
    	case MS_GOTHIC_8x16:
    	case SYSTEM_8x16:
    	default:
    		len_x = 8;
    		len_y = 16;
    		break;
    }

    GetASCIICode(buffer, ASCII, FONTx);
    for( i=0; i<len_y; i++ )
    {
        tmp_char = buffer[i];
        for( j=0; j<len_x; j++ )
        {
            if( (tmp_char >> 7 - j) & 0x01 == 0x01 )
            {
                SSD1289_SetPoint( Xpos + j, Ypos + i, charColor );
            }
            else
            {
                SSD1289_SetPoint( Xpos + j, Ypos + i, bkColor );
            }
        }
    }
}

void SSD1289_CleanPutChar( uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor)
{
	SSD1289_CleanPutCharFont(Xpos, Ypos, ASCII, charColor, SYSTEM_8x16);
}

void SSD1289_CleanPutCharFont( uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t FONTx)
{
	uint16_t i, j;
    uint8_t buffer[16], tmp_char;
    uint8_t len_x, len_y;

    switch (FONTx)
    {
    	case FONT6x8:
    		len_x = 6;
    		len_y = 8;
    		break;    	
    	case FONT8x8:
    		len_x = 8;
    		len_y = 8;
    		break;
    	case MS_GOTHIC_8x16:
    	case SYSTEM_8x16:
    	default:
    		len_x = 8;
    		len_y = 16;
    		break;
    }

    GetASCIICode(buffer, ASCII, FONTx);
    for( i=0; i<len_y; i++ )
    {
        tmp_char = buffer[i];
        for( j=0; j<len_x; j++ )
        {
            if( (tmp_char >> 7 - j) & 0x01 == 0x01 )
            {
                SSD1289_SetPoint( Xpos + j, Ypos + i, charColor );
            }
        }
    }	
}

void SSD1289_Text(uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t Color, uint16_t bkColor)
{
	SSD1289_TextFont(Xpos, Ypos, str, Color, bkColor, SYSTEM_8x16);
}

void SSD1289_TextFont(uint16_t Xpos, uint16_t Ypos, uint8_t *str,uint16_t Color, uint16_t bkColor, uint16_t FONTx)
{
    uint8_t TempChar;
    uint8_t delta_x, delta_y;

    switch (FONTx)
    {
    	case FONT6x8:
    		delta_x = 6;
    		delta_y = 8;
    		break;    	
    	case FONT8x8:
    		delta_x = 8;
    		delta_y = 8;
    		break;
    	case MS_GOTHIC_8x16:
    	case SYSTEM_8x16:
    	default:
    		delta_x = 8;
    		delta_y = 16;
    		break;
    }

    do
    {
        TempChar = *str++;  
        SSD1289_PutCharFont( Xpos, Ypos, TempChar, Color, bkColor, FONTx );    
        if( Xpos < MAX_X - delta_x )
        {
            Xpos += delta_x;
        } 
        else if ( Ypos < MAX_Y - delta_y )
        {
            Xpos = 0;
            Ypos += delta_y;
        }   
        else
        {
            Xpos = 0;
            Ypos = 0;
        }    
    }
    while ( *str != 0 );
}

void SSD1289_CleanText(uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t Color)
{
	SSD1289_CleanTextFont(Xpos, Ypos, str, Color, SYSTEM_8x16);

}
void SSD1289_CleanTextFont(uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t Color, uint16_t FONTx)
{
    uint8_t TempChar;

    do
    {
        TempChar = *str++;  
        SSD1289_CleanPutCharFont( Xpos, Ypos, TempChar, Color, FONTx);    
        if( Xpos < MAX_X - 8 )
        {
            Xpos += 8;
        } 
        else if ( Ypos < MAX_Y - 16 )
        {
            Xpos = 0;
            Ypos += 16;
        }   
        else
        {
            Xpos = 0;
            Ypos = 0;
        }    
    }
    while ( *str != 0 );
}

void SSD1289_DrawPicture(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t *pic)
{
	uint16_t x_index, y_index;
	uint32_t pic_index = 0;

    //for(y_index = y; y_index < (y+h); y_index++)
    //if wrong orientation
    for(y_index = (y+h); y_index > 0 ; y_index--)
    {
        for(x_index = x; x_index < (x+w); x_index++)
        {
			SSD1289_SetPoint(x_index, y_index, pic[pic_index]);
			pic_index++;
		}
	} 
}

void SSD1289_DrawPicture8bit(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t *pic)
{
	uint16_t color;
	uint16_t x_index, y_index;
	uint32_t pic_index = 0;

    //for(y_index = y; y_index < (y+h); y_index++)
    //if wrong orientation
	for(y_index = (y+h); y_index > 0 ; y_index--)
	{
		for(x_index = x; x_index < (x+w); x_index++)
		{
			color = (pic[pic_index+1] << 8) | (pic[pic_index]);
			SSD1289_SetPoint(x_index, y_index, color);
			pic_index += 2;
		}
	} 
}

void SSD1289_DrawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color)
{
	int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;
  
    SSD1289_SetPoint(x0, y0+r, color);
    SSD1289_SetPoint(x0, y0-r, color);
    SSD1289_SetPoint(x0+r, y0, color);
    SSD1289_SetPoint(x0-r, y0, color);

    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        SSD1289_SetPoint(x0 + x, y0 + y, color);
        SSD1289_SetPoint(x0 - x, y0 + y, color);
        SSD1289_SetPoint(x0 + x, y0 - y, color);
        SSD1289_SetPoint(x0 - x, y0 - y, color);
    
        SSD1289_SetPoint(x0 + y, y0 + x, color);
        SSD1289_SetPoint(x0 - y, y0 + x, color);
        SSD1289_SetPoint(x0 + y, y0 - x, color);
        SSD1289_SetPoint(x0 - y, y0 - x, color);
    }
}

void SSD1289_FillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color)
{
	int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    int16_t i;

    for (i=y0-r; i<=y0+r; i++)
        SSD1289_SetPoint(x0, i, color);

    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
  
        for (i=y0-y; i<=y0+y; i++) {
            SSD1289_SetPoint(x0+x, i, color);
            SSD1289_SetPoint(x0-x, i, color);
        } 
        for (i=y0-x; i<=y0+x; i++) {
            SSD1289_SetPoint(x0+y, i, color);
            SSD1289_SetPoint(x0-y, i, color);
        }    
    }
}

void SSD1289_DrawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	if (x > MAX_X)
		x = MAX_X;
	if (y > MAX_Y)
		y = MAX_Y;

	if ((x+w) > MAX_X)
		w = MAX_X - x;

	if ((y+h) > MAX_Y)
		h = MAX_Y - y;

	SSD1289_DrawLine(x, y, x, y+h, color);
	SSD1289_DrawLine(x, y, x+w, y, color);
	SSD1289_DrawLine(x+w, y+h, x, y+h, color);
	SSD1289_DrawLine(x+w, y+h, x+w, y, color);
}

void SSD1289_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	uint16_t x_index, y_index;

	if (x > MAX_X)
		x = MAX_X;
	if (y > MAX_Y)
		y = MAX_Y;

	if ((x+w) > MAX_X)
		w = MAX_X - x;

	if ((y+h) > MAX_Y)
		h = MAX_Y - y;

	for(x_index = x; x_index < x+w; x_index++)
	{
		for(y_index = y; y_index < y+h; y_index++)
		{
			SSD1289_SetPoint(x_index, y_index, color);
		}
	}

}

void SSD1289_DrawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	if (x0 > MAX_X)
		x0 = MAX_X;
	if (y0 > MAX_Y)
		y0 = MAX_Y;
	if (x1 > MAX_X)
		x1 = MAX_X;
	if (y1 > MAX_Y)
		y1 = MAX_Y;
	if (x2 > MAX_X)
		x2 = MAX_X;
	if (y2 > MAX_Y)
		y2 = MAX_Y;

	SSD1289_DrawLine(x0, y0, x1, y1, color);
	SSD1289_DrawLine(x0, y0, x2, y2, color);
	SSD1289_DrawLine(x2, y2, x1, y1, color);
}

void SSD1289_DrawCross(uint16_t Xpos, uint16_t Ypos, uint16_t in_color, uint16_t out_color)
{
  SSD1289_DrawLine(Xpos-15,Ypos,Xpos-2,Ypos,in_color);
  SSD1289_DrawLine(Xpos+2,Ypos,Xpos+15,Ypos,in_color);
  SSD1289_DrawLine(Xpos,Ypos-15,Xpos,Ypos-2,in_color);
  SSD1289_DrawLine(Xpos,Ypos+2,Xpos,Ypos+15,in_color);
  
  SSD1289_DrawLine(Xpos-15,Ypos+15,Xpos-7,Ypos+15,out_color);
  SSD1289_DrawLine(Xpos-15,Ypos+7,Xpos-15,Ypos+15,out_color);

  SSD1289_DrawLine(Xpos-15,Ypos-15,Xpos-7,Ypos-15,out_color);
  SSD1289_DrawLine(Xpos-15,Ypos-7,Xpos-15,Ypos-15,out_color);

  SSD1289_DrawLine(Xpos+7,Ypos+15,Xpos+15,Ypos+15,out_color);
  SSD1289_DrawLine(Xpos+15,Ypos+7,Xpos+15,Ypos+15,out_color);

  SSD1289_DrawLine(Xpos+7,Ypos-15,Xpos+15,Ypos-15,out_color);
  SSD1289_DrawLine(Xpos+15,Ypos-15,Xpos+15,Ypos-7,out_color);
}

void SSD1289_Backlight(uint32_t val)
{
    if(val > 0)
        Set_Backlight;
    else
        Clr_Backlight;
}
