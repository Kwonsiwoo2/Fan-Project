#include "Service_Fan.h"

uint16_t milisec;
uint8_t sec, min, hour;
uint16_t counter;
uint16_t reMilisec;
uint8_t reSec ,reMin, reHour;

void Fan_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
}

void incHour()
{
	hour++;
	if(hour >= 24) hour = 0;
	Presenter_dispFanData(hour, min, sec);
}

void incMin()
{
	min++;
	if(min >= 60) min = 0;
	Presenter_dispFanData(hour, min, sec);
}

void incSec()
{
	sec++;
	if(sec >= 60) sec = 0;
	Presenter_dispFanData(hour, min, sec);
}

void Fan_DecSec()
{
	if(!isTimerRunning) return;
	
	Motor_setSpeed(30);
	
	if (reMilisec == 0)
	{
		reMilisec = 999;
		milisec = 999;
		if (reSec == 0)
		{
			reSec = 59;
			sec = 59;
			if (reMin == 0)
			{
				reMin = 59;
				min = 59;
				if (reHour == 0)
				{
					reHour = 23;
					hour = 23;
				}
				else
				{
					reHour = (reHour - 1) % 24;
					hour = (hour - 1) % 24;
				}
			}
			else
			{
				reMin = (reMin - 1) % 60;
				min = (min -1) %60;
			}
		}
		else
		{
			reSec = (reSec - 1) % 60;
			sec = (sec - 1) % 60;

		}
	}
	else
	{
		reMilisec = (reMilisec - 1) % 1000;
		milisec = (milisec - 1) % 1000;
	}	
	if (reHour == 0 && reMin == 0 && reSec == 0 && reMilisec == 0)
	{
		Motor_stop();
		Buzzer_runOff();
		isTimerRunning = false;
		hour = 0;
		min = 0;
		sec = 0;
		milisec = 0;
	}
}


void Fan_AutoSec()
{
	if (++milisec >= 1000)
	{
		milisec = 0;
		counter++;
		
		if (counter == 5)
		{
			Model_setFanAutoState(counter);
			counter = 0;
		}
	}
}

void Fan_Run()
{
	uint8_t FanModeState;
	FanModeState = Model_getFanModeState();
	if(FanModeState != CONTROL) return;
	Motor_run();
	Presenter_dispControlData();
}

void Fan_RunTime()
{
	uint8_t FanModeState;
	FanModeState = Model_getFanModeState();
	if(FanModeState != TIM) return;
	Motor_runTime();
	Presenter_dispFanData(hour, min, sec);
}

void Fan_runAuto()
{
	uint8_t FanModeState;
	FanModeState = Model_getFanModeState();
	if(FanModeState != AUTO) return;
	Motor_runAuto();
	Presenter_dispAutoData();
}