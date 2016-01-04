/* Includes ------------------------------------------------------------------*/
#include "AsciiLib.h"

/*******************************************************************************
* Function Name  : GetASCIICode
* Description    : 
* Input          : 
* Output         : 
* Return         : None
* Attention		 : None
*******************************************************************************/
void GetASCIICode(unsigned char* pBuffer, unsigned char ASCII, uint16_t FONTx)
{  
	switch (FONTx)
	{
		case MS_GOTHIC_8x16:
			memcpy(pBuffer, MS_GOTHIC_8x16_table[(ASCII - 32)], 16);
			break;
		case FONT6x8:
			memcpy(pBuffer, FONT6x8_table[(ASCII - 32)], 8);
			break;
		case FONT8x8:
			memcpy(pBuffer, FONT8x8_table[(ASCII - 32)], 8);
			break;
		case SYSTEM_8x16:
		default:
			memcpy(pBuffer, SYSTEM_8x16_table[(ASCII - 32)], 16);
			break;
	}
}


/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

