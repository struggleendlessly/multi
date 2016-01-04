#include "I2C.h"

GPIO_InitTypeDef gpio;
I2C_InitTypeDef i2c;



/*******************************************************************/
void init_I2C1(void)
{
    // �������� ������������ ������ �������
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    // � ��� � ��������� I2C
    i2c.I2C_ClockSpeed = 100000;
    i2c.I2C_Mode = I2C_Mode_I2C;
    i2c.I2C_DutyCycle = I2C_DutyCycle_2;
    // ����� � ��� ���� ������ ��������� � ������
    i2c.I2C_OwnAddress1 = 0x15;
    i2c.I2C_Ack = I2C_Ack_Disable;
    i2c.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C1, &i2c);

    // I2C ���������� ��� ���� ����������������, �� ���� ����� ���������
    gpio.GPIO_Pin = GYRO_SDA | GYRO_SCL;
    gpio.GPIO_Mode = GPIO_Mode_AF;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    gpio.GPIO_OType = GPIO_OType_OD;
    gpio.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GYRO_CTRL_PORT, &gpio);

    GPIO_PinAFConfig(GYRO_CTRL_PORT, GPIO_PinSource6, GPIO_AF_I2C1);
    GPIO_PinAFConfig(GYRO_CTRL_PORT, GPIO_PinSource7, GPIO_AF_I2C1);

    // �� � ��������, ����������, ������ I2C1
    I2C_Cmd(I2C1, ENABLE);
}

/*******************************************************************/
void I2C_StartTransmission(I2C_TypeDef* I2Cx, uint8_t transmissionDirection,  uint8_t slaveAddress)
{
    // �� ������ ������ ����, ���� ���� ������������
    while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));

    // ���������� ����� - ��� ��� ������� )
    I2C_GenerateSTART(I2Cx, ENABLE);

    // ���� ���� ������� ������ ����
    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT));

    // �������� ����� ������������
    I2C_Send7bitAddress(I2Cx, slaveAddress, transmissionDirection);

    // � ������ � ��� ��� �������� �������� ������� - � ����������� �� ���������� ����������� ������ �������
    if(transmissionDirection== I2C_Direction_Transmitter)
    {
    	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
    }

    if(transmissionDirection== I2C_Direction_Receiver)
    {
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
    }
}

/*******************************************************************/
void I2C_WriteData(I2C_TypeDef* I2Cx, uint8_t data)
{
    // ������ �������� �������� ������� �� SPL � ����, ���� ������ ������
    I2C_SendData(I2Cx, data);
    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}



/*******************************************************************/
uint8_t I2C_ReadData(I2C_TypeDef* I2Cx)
{
    // ��� ������� ������, ��� ������ ������ ������ ���������� ��������� �� � ����������
    while( !I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED) );
    uint8_t data = I2C_ReceiveData(I2Cx);
    return data;
}

/*******************************************************************/
