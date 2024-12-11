#ifndef MODEL_FANMODESTATE_H_
#define MODEL_FANMODESTATE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

enum{CONTROL, AUTO, TIM};

uint8_t Model_getFanModeState();
void Model_setFanModeState(uint8_t state);

#endif /* MODEL_FANMODESTATE_H_ */