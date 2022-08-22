#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "a3992.h"
#include "core_cm3.h"
u8 j;

int main(void)
{	
	Stm32_Clock_Init(9);
	delay_init(72);	  	
	MOTOR_init();
	MOTOR_send(0x40779);//设置电机芯片A3992
	//MOTOR_send1(0x40779);//设置电机芯片2 A2992
	
//	MOTOR_send(0x5E3FE);
//	MOTOR_send(0x5FFFE);
//	MOTOR_send(0x5F786);

	
	while(1) 
	{
		MOTOR_send(0x5dffe);				//不停的把数组中的数据发送到电机驱动芯片,此时电机顺时针转
		delay_ms(1000);
		MOTOR_send(0x40000);
		delay_ms(1000);
//		MOTOR_send(0x57d30);
//		MOTOR_send(0x5DFFE);
//		delay_us(2000);	
//		MOTOR_send(0x5FFFE);
//		delay_us(200);
//		for(j=0;j<32;j++)
//		{
////			delay_us(2000);											//控制此延时，可以控制电机的转速。
////			MOTOR_send(MotorForward8[31-j]);	//此时电机逆时针转
////			delay_us(200);
//			//MOTOR_send1(MotorForward8[j]);
//			//MOTOR_send1(MotorForward8[31-j]);	//此时电机逆时针转
//		  //delay_us(800);			
//		}
		GPIOA->ODR|=7<<4;
	}
}


