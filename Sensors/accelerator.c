#include <stdio.h>
#include "accelerator.h"
#include "hal_sim.h"
#include "validation.h"
#include "fault_manager.h"
#include <stdint.h>
static float accel_percent = 0;

void Accelerator_Update(void)
{
    uint16_t adc = HAL_GetAcceleratorADC();
    accel_percent = (adc / 4095.0f) * 100.0f;

    if (!Validate_Accelerator(accel_percent))
    {
        printf("Accelerator Validation: INVALID\n");
        Fault_Set(FAULT_ACC);
    }
    else
    {
        printf("Accelerator Validation: VALID\n");
        Fault_Clear(FAULT_ACC);
    }
}

float Accelerator_GetPercent(void)
{
    return accel_percent;
}