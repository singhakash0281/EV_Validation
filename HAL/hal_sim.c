#include "hal_sim.h"
#include <stdlib.h>

uint16_t HAL_GetWheelPulse(void)
{
    return rand() % 200;  // simulate pulse count
}

uint16_t HAL_GetAcceleratorADC(void)
{
    return rand() % 4096;  // simulate ADC (12-bit)
}

uint8_t HAL_GetBrakeGPIO(void)
{
    return rand() % 2;
}