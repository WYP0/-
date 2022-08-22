#ifndef __A3992_H
#define __A3992_H
extern unsigned long MotorForward8[];

//SPI HARDWARE 
//STROBE-------------->PA4
//CLK----------------->PA5
//DATA---------------->PA6

//水平电机三线SPI接口设置
#define MOTOR_STROBE_H     GPIOA->ODR|=1<<4			//拉高STROBE片选线
#define MOTOR_STROBE_L     GPIOA->ODR&=~(1<<4)	//拉低STROBE片选线-PA4
#define MOTOR_CLK_H 		GPIOA->ODR|=1<<5				//拉高时钟线
#define MOTOR_CLK_L 		GPIOA->ODR&=~(1<<5)			//拉低时钟线-PA5
#define MOTOR_DATA_H 		GPIOA->ODR|=1<<6				//拉高数据线-PA6
#define MOTOR_DATA_L 		GPIOA->ODR&=~(1<<6)			//拉低数据线

//#define MOTOR_STROBE_H1     GPIOB->ODR|=1<<13			//拉高STROBE片选线
//#define MOTOR_STROBE_L1     GPIOB->ODR&=~(1<<13)	//拉低STROBE片选线
//#define MOTOR_CLK_H1 		GPIOB->ODR|=1<<14					//拉高时钟线
//#define MOTOR_CLK_L1		GPIOB->ODR&=~(1<<14)			//拉低时钟线
//#define MOTOR_DATA_H1 		GPIOB->ODR|=1<<15				//拉高数据线
//#define MOTOR_DATA_L1 		GPIOB->ODR&=~(1<<15)		//拉低数据线


void MOTOR_init(void);
void MOTOR_send(unsigned long buf);
//void MOTOR_send1(unsigned long buf);

#endif

