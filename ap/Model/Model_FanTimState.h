#ifndef MODEL_FANTIMSTATE_H_
#define MODEL_FANTIMSTATE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

enum{HOUR, MIN, RUN, NO};
	
uint8_t Model_getFanTimState();
void Model_setFanTimState(uint8_t state);

#endif /* MODEL_FANTIMSTATE_H_ */