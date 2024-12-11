#include "Buzzer.h"

void Buzzer_init()
{
	TCCR1B |= ((0<<CS12) | (1<<CS11) | (1<<CS10)); // PreScaler 1/64
	TCCR1B |= ((1<<WGM13) | (1<<WGM12)); // Fast PWM with ICR1 as TOP
	TCCR1A |= ((1<<WGM11) | (0<<WGM10)); // Fast PWM 14
	
	ICR1 = 250-1; // 1Khz frequency, Top value
	
	DDRB |= (1<<5); // Set PB5 as output
}

void Buzzer_soundOn()
{
	TCCR1A |= ((1<<COM1A1) | (0<<COM1A0)); // Non-inverting mode
}

void Buzzer_soundOff()
{
	TCCR1A &= ~((1<<COM1A1) | (1<<COM1A0)); // Non-inverting mode Off
}


void Buzzer_makeHertz(uint16_t hertz)
{
	if(hertz < 100) hertz = 100;
	else if(hertz > 5000) hertz = 5000;
	
	BUZZER_ICR = (250000 / hertz) - 1;
	BUZZER_OCR = BUZZER_ICR / 2;
}

void Buzzer_buttonOn()
{
	Buzzer_makeHertz(1046);		
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_makeHertz(1318);		
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_makeHertz(1567);		
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_makeHertz(2093);		
	_delay_ms(100);
	TCNT1 = 0;
}

void Buzzer_runOff()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(2093);
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_makeHertz(1567);
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_makeHertz(1318);
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_soundOff();
}

void Buzzer_click()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_makeHertz(1318);
	_delay_ms(100);
	TCNT1 = 0;
	Buzzer_soundOff();
}

void Buzzer_run()
{
	Buzzer_soundOn();
	Buzzer_buttonOn();
	Buzzer_soundOff();
}