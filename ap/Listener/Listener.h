#ifndef LISTENER_H_
#define LISTENER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <string.h>

extern bool isTimerRunning;

#include "../Model/Model_FanPowerState.h"
#include "../Model/Model_FanModeState.h"
#include "../Model/Model_FanAutoState.h"
#include "../../driver/Button/Button.h"
#include "../Service/Service_Fan.h"
#include "../Presenter/Presenter.h"
#include "../../periph/UART0/UART0.h"
#include "../../driver/Buzzer/Buzzer.h"

void Listener_init();
void Listener_TimEvent();
void Listener_ControlEvent();
void Listener_eventCheck();
void Listener_AutoEvent();

#endif 