#include "a3992.h" 
#include "delay.h" 										 

//2������1.8�Ȳ��������أ������˵����8ϸ�ֵ���������
 unsigned long  MotorForward8[]=
{0x4be98,0x4bd30,0x4ba44,0x4b658,0x4b168,0x4ac74,0x4a67a,0x4a07e,0x5667a,0x56c74,0x57168,0x57658,0x57a44,0x57d30,0x57e98,0x57f80, 
 0x4de98,0x4dd30,0x4da44,0x4d658,0x4d168,0x4cc74,0x4c67a,0x4c07e,0x5067a,0x50c74,0x51168,0x51658,0x51a44,0x51d30,0x51e98,0x51f80};

//��ʼ������ 
void MOTOR_init(void)
{                                 
 	RCC->APB2ENR|=1<<2;//��ʹ������IO PORTAʱ��
	//RCC->APB2ENR|=1<<3;//��ʹ������IO PORTBʱ��
//	GPIOB->CRH&=0X000FFFFF;//PB13,14,15 �������
	//GPIOB->CRH|=0X33300000;	   
//	GPIOB->ODR|=7<<13;     //PB13,14,15 �����
	GPIOA->CRL&=0XF000FFFF;//PA4,5,6 �������
	GPIOA->CRL|=0XF333FFFF;
	GPIOA->ODR|=7<<4;
}
//����SPI�������ݸ����оƬ 1
void MOTOR_send(unsigned long  buf)//buf��Ҫ���͵�����
{
	u8 i;
	MOTOR_STROBE_L;
	for(i=0;i<19;i++)//һ�η�19������
	{
		if(buf&0x40000)
			MOTOR_DATA_H;//�����λΪ1�����������͸ߵ�ƽ,����MSB
		else 
			MOTOR_DATA_L;//�����͵͵�ƽ
		delay_us(100);
		MOTOR_CLK_H;//ʱ���ߵ������أ�����оƬ����һλ����
		delay_us(100);
		buf<<=1;//�������ƣ�׼��������һλ����
		MOTOR_CLK_L;//ʱ���ߵ�
	}
	MOTOR_STROBE_H;//������һ֡���ݺ�����Ƭѡ��
}

//����SPI�������ݸ����оƬ 2
//void MOTOR_send1(unsigned long  buf)//buf��Ҫ���͵�����
//{
	//u8 i;
	//MOTOR_STROBE_L1;
	//for(i=0;i<19;i++)//һ�η�19������
	//{
	//	if(buf&0x40000)
	//		MOTOR_DATA_H1;//�����λΪ1�����������͸ߵ�ƽ,����MSB
	//	else 
	//		MOTOR_DATA_L1;//�����͵͵�ƽ
	//	MOTOR_CLK_L1;//ʱ���ߵ�
	//	delay_us(1);
	//	MOTOR_CLK_H1;//ʱ���ߵ������أ�����оƬ����һλ����
	//	buf<<=1;//�������ƣ�׼��������һλ����
	//}
	//MOTOR_STROBE_H1;//������һ֡���ݺ�����Ƭѡ��
//}




