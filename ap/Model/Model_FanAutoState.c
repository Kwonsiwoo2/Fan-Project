#include "Model_FanAutoState.h"

uint8_t FanAutoState;

uint8_t Model_getFanAutoState()
{
	return FanAutoState;
}

void Model_setFanAutoState(uint8_t state)
{
	FanAutoState = state;
}