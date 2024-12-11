#ifndef PRESENTER_H_
#define PRESENTER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "../../driver/FND/FND.h"
#include "../../driver/LCD/LCD.h"
#include "../../driver/Motor/Motor.h"
#include "../Model/Model_FanModeState.h"
#include "../Model/Model_FanPowerState.h"
#include "../Model/Model_FanTimState.h"
#include "../Service/Service_Fan.h"

void Presenter_init();
void Presenter_dispControlData();
void Presenter_dispAutoData();
void Presenter_dispFanData(uint8_t hour, uint8_t min, uint8_t sec);
void Motor_run();
void Motor_runTime();
void Motor_runAuto();
void UART0_execute();

#endif /* PRESENTER_H_ */