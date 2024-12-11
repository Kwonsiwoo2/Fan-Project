#include "Model_FanTimState.h"

uint8_t FanTimState;

uint8_t Model_getFanTimState()
{
	return FanTimState;
}

void Model_setFanTimState(uint8_t state)
{
	FanTimState = state;
}