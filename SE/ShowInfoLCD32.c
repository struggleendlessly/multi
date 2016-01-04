#include "ShowInfoLCD32.h"

void AddSeparator (char * strToShow, char * strToAdd)
{
	strcat(strToShow, strToAdd);

	switch( 4 - strlen(strToAdd) )
	{
	    case 0 :
	    	strcat(strToShow, TimShow_Separator);
	        break;
	    case 1 :
	    	strcat(strToShow, TimShow_Separator1);
	        break;
	    case 2 :
	    	strcat(strToShow, TimShow_Separator2);
	        break;
	}
}

void Tim3_Show()
{
    char tim_CCR1[8] = "";
    char tim_CCR2[8] = "";
    char tim_CCR3[8] = "";
    char tim_CCR4[8] = "";

    char tim_CCR_show[40] = "";

    itoa(TIM3->CCR1, tim_CCR1, 10);
    itoa(TIM3->CCR2, tim_CCR2, 10);
    itoa(TIM3->CCR3, tim_CCR3, 10);
    itoa(TIM3->CCR4, tim_CCR4, 10);

    strcat(tim_CCR_show, "TIM3: ");

    AddSeparator(tim_CCR_show, tim_CCR1);
    AddSeparator(tim_CCR_show, tim_CCR2);
    AddSeparator(tim_CCR_show, tim_CCR3);
    AddSeparator(tim_CCR_show, tim_CCR4);

    SSD1289_FillRect(Tim3_Show_X,Tim3_Show_Y, MAX_X, 15, Black);
    SSD1289_CleanTextFont(Tim3_Show_X, Tim3_Show_Y, tim_CCR_show, Green, SYSTEM_8x16);
}

void Tim4_Show()
{
    char tim_CCR1[8] = "";
    char tim_CCR2[8] = "";
    char tim_CCR3[8] = "";
    char tim_CCR4[8] = "";

    char tim_CCR_show[40] = "";

    itoa(TIM4->CCR1, tim_CCR1, 10);
    itoa(TIM4->CCR2, tim_CCR2, 10);
    itoa(TIM4->CCR3, tim_CCR3, 10);
    itoa(TIM4->CCR4, tim_CCR4, 10);

    strcat(tim_CCR_show, "TIM4: ");

    AddSeparator(tim_CCR_show, tim_CCR1);
    AddSeparator(tim_CCR_show, tim_CCR2);
    AddSeparator(tim_CCR_show, tim_CCR3);
    AddSeparator(tim_CCR_show, tim_CCR4);

    SSD1289_FillRect(Tim4_Show_X,Tim4_Show_Y, MAX_X, 15, Black);
    SSD1289_CleanTextFont(Tim4_Show_X, Tim4_Show_Y, tim_CCR_show, Green, SYSTEM_8x16);
}
