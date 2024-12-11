#ifndef MODEL_FANPOWERSTATE_H_
#define MODEL_FANPOWERSTATE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

enum{STOP, LOW, MID, HIGH};
	
uint8_t Model_getFanPowerState();
void Model_setFanPowerState(uint8_t state);


#endif /* MODEL_FANPOWERSTATE_H_ */