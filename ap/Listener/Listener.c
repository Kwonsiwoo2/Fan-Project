#include "Listener.h"

button_t btnPower, btnAuto, btnTim, btnSwitch;
uint8_t FanModeState;
uint8_t FanPowerState;
uint8_t FanTimState;
bool isTimerRunning = false;


void Listener_init()
{
	Button_init(&btnPower, &DDRA, &PINA, 0);
	Button_init(&btnAuto, &DDRA, &PINA, 1);
	Button_init(&btnTim, &DDRA, &PINA, 2);
	Button_init(&btnSwitch, &DDRA, &PINA, 3);
	Buzzer_init();
}

void Listener_eventCheck()
{
	FanModeState = Model_getFanModeState();
	UART0_execute();
	switch(FanModeState)
	{
		case CONTROL:
		Listener_ControlEvent();
		if(Button_GetState(&btnSwitch) == ACT_PUSHED)
		{
			Buzzer_click();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
			FanModeState = AUTO;
			Model_setFanModeState(FanModeState);
		}
		break;
		case AUTO:
		Listener_AutoEvent();
		if(Button_GetState(&btnSwitch) == ACT_PUSHED)
		{
			Buzzer_click();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
			FanModeState = TIM;
			Model_setFanModeState(FanModeState);
		}
		break;
		case TIM:
		Listener_TimEvent();
		if(Button_GetState(&btnSwitch) == ACT_PUSHED)
		{
			Buzzer_click();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
			FanModeState = CONTROL;
			Model_setFanModeState(FanModeState);	
		}
		break;
	}
}


void Listener_ControlEvent()
{
	FanPowerState = Model_getFanPowerState();
	switch(FanPowerState)
	{
		case STOP:
		if(Button_GetState(&btnPower) == ACT_PUSHED)
		{
			Buzzer_run();
			FanPowerState = LOW;
			Model_setFanPowerState(FanPowerState);
		}
		else if(Button_GetState(&btnTim) == ACT_PUSHED)
		{
			Buzzer_runOff();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
		}
		break;
		case LOW:
		if(Button_GetState(&btnPower) == ACT_PUSHED)
		{
			Buzzer_click();
			FanPowerState = MID;
			Model_setFanPowerState(FanPowerState);
		}
		else if(Button_GetState(&btnTim) == ACT_PUSHED)
		{
			Buzzer_runOff();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
		}
		break;
		case MID:
		if(Button_GetState(&btnPower) == ACT_PUSHED)
		{
			Buzzer_click();
			FanPowerState = HIGH;
			Model_setFanPowerState(FanPowerState);
		}
		else if(Button_GetState(&btnTim) == ACT_PUSHED)
		{
			Buzzer_runOff();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
		}
		break;
		case HIGH:
		if(Button_GetState(&btnPower) == ACT_PUSHED)
		{
			Buzzer_runOff();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
		}
		else if(Button_GetState(&btnTim) == ACT_PUSHED)
		{
			Buzzer_runOff();
			FanPowerState = STOP;
			Model_setFanPowerState(FanPowerState);
		}
		break;
	}
}

void Listener_TimEvent()
{
	if(Button_GetState(&btnPower) == ACT_PUSHED)
	{
		Buzzer_click();
		incHour();
		Presenter_dispFanData(hour, min, sec);
	}
	else if(Button_GetState(&btnAuto) == ACT_PUSHED)
	{
		Buzzer_click();
		incMin();
		Presenter_dispFanData(hour, min, sec);
	}
	else if(Button_GetState(&btnTim) == ACT_PUSHED)
	{
		Buzzer_run();
		Motor_start();
		reHour = hour;
		reMin = min;
		reSec = sec;
		if(reHour == 0 && reMin == 0 && reSec == 0) return;
		isTimerRunning = true;
	}
}

void Listener_AutoEvent()
{
	FanPowerState = Model_getFanPowerState();
	uint8_t counter = Model_getFanAutoState();
	
	if (counter == 5)
	{
		switch(FanPowerState)
		{
			case STOP:
			FanPowerState = LOW;
			break;
			case LOW:
			FanPowerState = MID;
			break;
			case MID:
			FanPowerState = HIGH;
			break;
			case HIGH:
			FanPowerState = STOP;
			break;
		}

		Model_setFanPowerState(FanPowerState);
		Model_setFanAutoState(0);
	}
}


void UART0_execute()
{
	if(UART0_getRxFlag())
	{
		UART0_clearRxFlag();
		uint8_t* rxString = UART0_readRxBuff();
		FanModeState = Model_getFanModeState();
		
		if(!strcmp((char *)rxString,"CONTROL_MODE\n"))
		{
			FanModeState = CONTROL;
			Model_setFanModeState(FanModeState);
		}
		else if(!strcmp((char *)rxString,"AUTO_MODE\n"))
		{
			printf("Auto_Mode\n");
			FanModeState = AUTO;
			Model_setFanModeState(FanModeState);
		}
		else if(!strcmp((char *)rxString,"Time_Mode\n"))
		{
			printf("Time_Mode\n");
			FanModeState = TIM;
			Model_setFanModeState(FanModeState);
		}
	}
}