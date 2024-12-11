#ifndef APMAIN_H_
#define APMAIN_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>

#include "../periph/UART0/UART0.h"
#include "Model/Model_FanModeState.h"
#include "Model/Model_FanPowerState.h"
#include "Model/Model_FanTimState.h"
#include "../periph/TIM/TIM.h"
#include "Listener/Listener.h"
#include "Presenter/Presenter.h"
#include "Service/Service_Fan.h"
#include "../periph/UART0/UART0.h"

void apMain_init();
void apMain_excute();

#endif /* APMAIN_H_ */