
static void Init_SPI_1(void)
{
	/*  GPIO_InitTypeDef GPIO_InitStructure;
	  SPI_InitTypeDef SPI_InitStructure;

	  // Тактирование модуля SPI1 и порта А
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	  // Настраиваем ноги SPI1 для работы в режиме альтернативной функции
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);

	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_5;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

	  //Заполняем структуру с параметрами SPI модуля
	  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; //полный дуплекс
	  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b; // передаем по 8 бит
	  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; // Полярность и
	  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; // фаза тактового сигнала
	  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft; // Управлять состоянием сигнала NSS программно
	  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; // Предделитель SCK
	  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB; // Первым отправляется старший бит
	  SPI_InitStructure.SPI_Mode = SPI_Mode_Master; // Режим - мастер
	  SPI_Init(SPI1, &SPI_InitStructure); //Настраиваем SPI1
	  SPI_Cmd(SPI1, ENABLE); // Включаем модуль SPI1....

	  // Поскольку сигнал NSS контролируется программно, установим его в единицу
	  // Если сбросить его в ноль, то наш SPI модуль подумает, что
	  // у нас мультимастерная топология и его лишили полномочий мастера.
	  //SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
	   *
	   */
}
static void Init_a(void)
{


}
