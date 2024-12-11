#include "apMain.h"


FILE OUTPUTS = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);


ISR(TIMER0_OVF_vect)
{
	FND_ISR_Process();
	TCNT0 = 130;
}

ISR(USART0_RX_vect)
{
	UART0_ISR_Process();
}

ISR(TIMER2_COMP_vect)
{
	Fan_AutoSec();
	Fan_DecSec();
}

void apMain_init()
{	
	Presenter_init();
	Listener_init();
	UART0_init();
	stdout = &OUTPUTS;
	TIM0_init();
	TIM2_init();
	sei();
	Model_setFanPowerState(STOP);
	Model_setFanModeState(CONTROL);
	Model_setFanAutoState(0);
}

void apMain_excute()
{
	Listener_eventCheck();
	Fan_Run();
	Fan_RunTime();
	Fan_runAuto();
	UART0_execute();
}