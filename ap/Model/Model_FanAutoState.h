#ifndef MODEL_FANAUTOSTATE_H_
#define MODEL_FANAUTOSTATE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t Model_getFanAutoState();
void Model_setFanAutoState(uint8_t state);

#endif /* MODEL_FANAUTOSTATE_H_ */