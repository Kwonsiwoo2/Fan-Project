#include "TIM.h"

void TIM0_init() // 1ms overflow Interrupt, FND Display
{
	// 128 1ms interrupt
	//TCNT0이랑 TCNT2는 DATASHEET가 다름
	TCCR0 |= ((1<<CS02) | (0<<CS01) | (1<<CS00));	// 128 PreScaler
	TIMSK |= (1<<TOIE0);
	//TCNT2 = 5;				//TIMSK Timer/Counter0 overflow 설정
	// 1/(16000000/64)*250 = 1밀리세크 250초마다 하면 됨
	// overflow 255마다 발생 따라서 TCNT2 = 5
	TCNT0 = 130;
}

void TIM2_init()
{
		//Timer/Counter 2 1/64 1ms period interrupt, CTC mode
		
		// 1/64 Prescaler
		TCCR2 |= ((0<<CS22) | (1<<CS21) | (1<<CS20));
		TIMSK |= (1<<OCIE2);
		
		//CTC mode
		TCCR2 |= ((1<<WGM21) | (0<<WGM20));
		OCR2 = 250-1;
		
}