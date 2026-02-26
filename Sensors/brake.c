#include <stdio.h>
#include <stdint.h>
#include "brake.h"
#include "hal_sim.h"
#include "validation.h"
#include "fault_manager.h"

static uint8_t brake_state = 0;

void Brake_Update(void)
{
    brake_state = HAL_GetBrakeGPIO();

    if (!Validate_Brake(brake_state))
    {
        printf("Brake Validation: INVALID\n");
        Fault_Set(FAULT_BRAKE);
    }
    else
    {
        printf("Brake Validation:  VALID\n");
        Fault_Clear(FAULT_BRAKE);
    }
}

uint8_t Brake_GetState(void)
{
    return brake_state;
}