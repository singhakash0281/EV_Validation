#include "hal_sim.h"
#include <stdlib.h>
#include <stdint.h>
#include "hal_sim.h"


uint16_t HAL_GetWheelPulse(void)
{
    uint16_t val;
    printf("Enter Wheel Pulse: ");
    scanf("%hu", &val);
    return val;
}

uint16_t HAL_GetAcceleratorADC(void)
{
    uint16_t val;
    printf("Enter Accelerator ADC (0-4095): ");
    scanf("%hu", &val);
    return val;
}

uint8_t HAL_GetBrakeGPIO(void)
{
    uint8_t val;
    printf("Enter Brake State (0 or 1): ");
    scanf("%hhu", &val);
    return val;
}