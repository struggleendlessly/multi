
static void Init_SPI_1(void)
{
	/*  GPIO_InitTypeDef GPIO_InitStructure;
	  SPI_InitTypeDef SPI_InitStructure;

	  // ������������ ������ SPI1 � ����� �
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	  // ����������� ���� SPI1 ��� ������ � ������ �������������� �������
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);

	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_5;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

	  //��������� ��������� � ����������� SPI ������
	  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; //������ �������
	  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b; // �������� �� 8 ���
	  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; // ���������� �
	  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; // ���� ��������� �������
	  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft; // ��������� ���������� ������� NSS ����������
	  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; // ������������ SCK
	  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB; // ������ ������������ ������� ���
	  SPI_InitStructure.SPI_Mode = SPI_Mode_Master; // ����� - ������
	  SPI_Init(SPI1, &SPI_InitStructure); //����������� SPI1
	  SPI_Cmd(SPI1, ENABLE); // �������� ������ SPI1....

	  // ��������� ������ NSS �������������� ����������, ��������� ��� � �������
	  // ���� �������� ��� � ����, �� ��� SPI ������ ��������, ���
	  // � ��� ��������������� ��������� � ��� ������ ���������� �������.
	  //SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
	   *
	   */
}
static void Init_a(void)
{


}
