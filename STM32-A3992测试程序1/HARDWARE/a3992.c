#include "a3992.h" 
#include "delay.h" 										 

//2相四线1.8度步进电机相关，包含了电机的8细分的驱动数据
 unsigned long  MotorForward8[]=
{0x4be98,0x4bd30,0x4ba44,0x4b658,0x4b168,0x4ac74,0x4a67a,0x4a07e,0x5667a,0x56c74,0x57168,0x57658,0x57a44,0x57d30,0x57e98,0x57f80, 
 0x4de98,0x4dd30,0x4da44,0x4d658,0x4d168,0x4cc74,0x4c67a,0x4c07e,0x5067a,0x50c74,0x51168,0x51658,0x51a44,0x51d30,0x51e98,0x51f80};

//初始化程序 
void MOTOR_init(void)
{                                 
 	RCC->APB2ENR|=1<<2;//先使能外设IO PORTA时钟
	//RCC->APB2ENR|=1<<3;//先使能外设IO PORTB时钟
//	GPIOB->CRH&=0X000FFFFF;//PB13,14,15 推挽输出
	//GPIOB->CRH|=0X33300000;	   
//	GPIOB->ODR|=7<<13;     //PB13,14,15 输出高
	GPIOA->CRL&=0XF000FFFF;//PA4,5,6 推挽输出
	GPIOA->CRL|=0XF333FFFF;
	GPIOA->ODR|=7<<4;
}
//三线SPI发送数据给电机芯片 1
void MOTOR_send(unsigned long  buf)//buf是要发送的数据
{
	u8 i;
	MOTOR_STROBE_L;
	for(i=0;i<19;i++)//一次发19个数据
	{
		if(buf&0x40000)
			MOTOR_DATA_H;//如果首位为1，数据线上送高电平,先送MSB
		else 
			MOTOR_DATA_L;//否则送低电平
		delay_us(100);
		MOTOR_CLK_H;//时钟线的上升沿，驱动芯片读入一位数据
		delay_us(100);
		buf<<=1;//数据左移，准备发送下一位数据
		MOTOR_CLK_L;//时钟线低
	}
	MOTOR_STROBE_H;//发送完一帧数据后拉高片选线
}

//三线SPI发送数据给电机芯片 2
//void MOTOR_send1(unsigned long  buf)//buf是要发送的数据
//{
	//u8 i;
	//MOTOR_STROBE_L1;
	//for(i=0;i<19;i++)//一次发19个数据
	//{
	//	if(buf&0x40000)
	//		MOTOR_DATA_H1;//如果首位为1，数据线上送高电平,先送MSB
	//	else 
	//		MOTOR_DATA_L1;//否则送低电平
	//	MOTOR_CLK_L1;//时钟线低
	//	delay_us(1);
	//	MOTOR_CLK_H1;//时钟线的上升沿，驱动芯片读入一位数据
	//	buf<<=1;//数据左移，准备发送下一位数据
	//}
	//MOTOR_STROBE_H1;//发送完一帧数据后拉高片选线
//}




