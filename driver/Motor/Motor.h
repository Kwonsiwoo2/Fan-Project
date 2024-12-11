#ifndef MOTOR_H_
#define MOTOR_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define Motor_ICR		ICR3
#define Motor_OCR		OCR3A

void Motor_init();
void Motor_start();
void Motor_stop();
void Motor_setSpeed(uint8_t speed);

#endif /* BUZZER_H_ */