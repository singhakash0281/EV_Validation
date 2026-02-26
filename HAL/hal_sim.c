#include <stdio.h>
#include <stdint.h>
#include "hal_sim.h"

static uint16_t fl, fr, rl, rr;
static uint16_t accel_adc;
static uint8_t brake_gpio;

void HAL_UpdateInputs(void)
{
    printf("\nEnter FL FR RL RR pulses: ");
    scanf("%hu %hu %hu %hu", &fl, &fr, &rl, &rr);

    printf("Enter Accelerator ADC (0-4095): ");
    scanf("%hu", &accel_adc);

    printf("Enter Brake (0/1): ");
    scanf("%hhu", &brake_gpio);
}

uint16_t HAL_GetWheelFL(void) { return fl; }
uint16_t HAL_GetWheelFR(void) { return fr; }
uint16_t HAL_GetWheelRL(void) { return rl; }
uint16_t HAL_GetWheelRR(void) { return rr; }

uint16_t HAL_GetAcceleratorADC(void) { return accel_adc; }
uint8_t HAL_GetBrakeGPIO(void) { return brake_gpio; }