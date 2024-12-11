#include "Model_FanModeState.h"

uint8_t FanModeState;

uint8_t Model_getFanModeState()
{
	return FanModeState;
}

void Model_setFanModeState(uint8_t state)
{
	FanModeState = state;
}