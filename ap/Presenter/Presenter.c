#include "Presenter.h"

void Presenter_init()
{
	FND_init();
	LCD_init();
	Motor_init();
}

void Presenter_dispControlData()
{
	char buff[30];
	uint8_t FanPowerState;
	FanPowerState = Model_getFanPowerState();
	sprintf(buff, "Control Mode        ");
	LCD_writeStringXY(0, 2, buff);
	
	switch(FanPowerState)
	{
		case STOP:
		sprintf(buff, "   STOP  ");
		LCD_writeStringXY(1, 3, buff);
		break;
		case LOW:
		sprintf(buff, "    LOW  ");
		LCD_writeStringXY(1, 3, buff);
		break;
		case MID:
		sprintf(buff, "    MID  ");
		LCD_writeStringXY(1, 3, buff);
		break;
		case HIGH:
		sprintf(buff, "   HIGH  ");
		LCD_writeStringXY(1, 3, buff);
		break;
	}
}

void Presenter_dispAutoData()
{
	char buff[30];
	uint8_t FanPowerState;
	FanPowerState = Model_getFanPowerState();
	sprintf(buff, " Auto Mode     ");
	LCD_writeStringXY(0, 2, buff);
	
	switch(FanPowerState)
	{
		case STOP:
		sprintf(buff, "   STOP         ");
		LCD_writeStringXY(1, 3, buff);
		break;
		case LOW:
		sprintf(buff, "    LOW         ");
		LCD_writeStringXY(1, 3, buff);
		break;
		case MID:
		sprintf(buff, "    MID         ");
		LCD_writeStringXY(1, 3, buff);
		break;
		case HIGH:
		sprintf(buff, "   HIGH          ");
		LCD_writeStringXY(1, 3, buff);
		break;
	}
	
}

void Presenter_dispFanData(uint8_t hour, uint8_t min, uint8_t sec)
{
	uint16_t FanData;

	FanData = (hour % 100 * 100) + (min % 100);
	FND_setFndData(FanData);
	
	char buff[30];

	sprintf(buff, " Time Mode              ");
	LCD_writeStringXY(0, 2, buff);
	sprintf(buff, " %02d:%02d:%02d      ", hour, min, sec);
	LCD_writeStringXY(1, 3, buff);
}

void Motor_run()
{
	uint8_t FanPowerState;
	FanPowerState = Model_getFanPowerState();
	Motor_start();
	switch(FanPowerState)
	{
		case STOP:
		Motor_stop();
		break;
		case LOW:
		Motor_setSpeed(30);
		break;
		case MID:
		Motor_setSpeed(60);
		break;
		case HIGH:
		Motor_setSpeed(100);
		break;
	}
}

void Motor_runTime()
{
	Motor_setSpeed(0);
}

void Motor_runAuto()
{
	 uint8_t FanPowerState;
	 FanPowerState = Model_getFanPowerState();
	 Motor_start();
	 switch(FanPowerState)
	 {
		 case STOP:
		 Motor_stop();
		 break;
		 case LOW:
		 Motor_setSpeed(30);
		 break;
		 case MID:
		 Motor_setSpeed(60);
		 break;
		 case HIGH:
		 Motor_setSpeed(100);
		 break;
	 }
}
