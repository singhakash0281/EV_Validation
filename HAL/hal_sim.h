#ifndef HAL_SIM_H
#define HAL_SIM_H

#include <stdint.h>

void HAL_UpdateInputs(void);

uint16_t HAL_GetWheelFL(void);
uint16_t HAL_GetWheelFR(void);
uint16_t HAL_GetWheelRL(void);
uint16_t HAL_GetWheelRR(void);

uint16_t HAL_GetAcceleratorADC(void);
uint8_t  HAL_GetBrakeGPIO(void);

#endif