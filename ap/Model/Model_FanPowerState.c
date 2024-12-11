#include "Model_FanPowerState.h"

uint8_t FanPowerState;

uint8_t Model_getFanPowerState()
{
	return FanPowerState;
}

void Model_setFanPowerState(uint8_t state)
{
	FanPowerState = state;
}