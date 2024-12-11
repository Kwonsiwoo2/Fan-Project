#ifndef SERVICE_FAN_H_
#define SERVICE_FAN_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../Presenter/Presenter.h"
#include "../../driver/Motor/Motor.h"
#include "../Model/Model_FanPowerState.h"
#include "../Model/Model_FanModeState.h"
#include "../Model/Model_FanTimState.h"
#include "../Model/Model_FanAutoState.h"
#include "../Listener/Listener.h"
#include "../../driver/Buzzer/Buzzer.h"

extern uint16_t milisec;
extern uint8_t sec, min, hour;
extern uint8_t reHour, reMin, reSec;
extern uint16_t reMilisec;

void incHour();
void incMin();
void incSec();
void Fan_incMilisec();
void Fan_DecSec();
void Fan_Run();
void Fan_RunTime();
void Fan_runAuto();
void Fan_AutoSec();

#endif /* SERVICE_FAN_H_ */