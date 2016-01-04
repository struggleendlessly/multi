#include "main.h"

int main(void)
{
	SystemInit();

    if (SysTick_Config(SystemCoreClock / 1000))
    {
	    //* Capture error *
	    while (1);
    }


	SSD1289_Init();
    //SSD1289_CleanTextFont(0, 50, "Hello Oleksandr. Start your project ;-)", Green, SYSTEM_8x16);

	Configure_PinsForIRQsInit();
	Tim4Init();
   // Tim3Init();

	while(1)
	{

	}
}



