#include "Motor.h"

void Motor_init()
{
	TCCR3B |= ((0<<CS32) | (1<<CS31) | (1<<CS30)); //PreScaler 1/64
	//Fast PWM
	TCCR3B |= ((1<<WGM33) | (1<<WGM32));
	TCCR3A |= ((1<<WGM31) | (0<<WGM30));	//Fast PWM 14
	
	Motor_ICR = 250-1; // 1Khz frequency, Top value
	
	DDRE |= (1<<3);
}

void Motor_start()
{
	TCCR3A |= ((1<<COM3A1) | (0<<COM3A0));	//non-inverting mode
}

void Motor_stop()
{
	TCCR3A &= ~((1<<COM3A1) | (1<<COM3A0));	//non-inverting mode Off
}
// 20hz~20khz	가청주파수

void Motor_setSpeed(uint8_t speed)
{
	if(speed > 100) speed = 100;

	Motor_OCR = ((Motor_ICR + 1) * speed) / 100;
}