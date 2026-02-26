#ifndef HAL_SIM_H
#define HAL_SIM_H

#include <stdint.h>

uint16_t HAL_GetWheelPulse(void);
uint16_t HAL_GetAcceleratorADC(void);
uint8_t HAL_GetBrakeGPIO(void);

#endif