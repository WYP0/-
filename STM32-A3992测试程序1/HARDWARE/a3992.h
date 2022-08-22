#ifndef __A3992_H
#define __A3992_H
extern unsigned long MotorForward8[];

//SPI HARDWARE 
//STROBE-------------->PA4
//CLK----------------->PA5
//DATA---------------->PA6

//ˮƽ�������SPI�ӿ�����
#define MOTOR_STROBE_H     GPIOA->ODR|=1<<4			//����STROBEƬѡ��
#define MOTOR_STROBE_L     GPIOA->ODR&=~(1<<4)	//����STROBEƬѡ��-PA4
#define MOTOR_CLK_H 		GPIOA->ODR|=1<<5				//����ʱ����
#define MOTOR_CLK_L 		GPIOA->ODR&=~(1<<5)			//����ʱ����-PA5
#define MOTOR_DATA_H 		GPIOA->ODR|=1<<6				//����������-PA6
#define MOTOR_DATA_L 		GPIOA->ODR&=~(1<<6)			//����������

//#define MOTOR_STROBE_H1     GPIOB->ODR|=1<<13			//����STROBEƬѡ��
//#define MOTOR_STROBE_L1     GPIOB->ODR&=~(1<<13)	//����STROBEƬѡ��
//#define MOTOR_CLK_H1 		GPIOB->ODR|=1<<14					//����ʱ����
//#define MOTOR_CLK_L1		GPIOB->ODR&=~(1<<14)			//����ʱ����
//#define MOTOR_DATA_H1 		GPIOB->ODR|=1<<15				//����������
//#define MOTOR_DATA_L1 		GPIOB->ODR&=~(1<<15)		//����������


void MOTOR_init(void);
void MOTOR_send(unsigned long buf);
//void MOTOR_send1(unsigned long buf);

#endif

