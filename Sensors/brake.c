#include "brake.h"
#include "hal_sim.h"
#include "validation.h"
#include "fault_manager.h"


static uint8_t brake_state = 0;

void Brake_Update(void)
{
    uint8_t raw = HAL_GetBrakeGPIO();

    if (!Validate_Brake(raw))
    {
        Fault_Set(FAULT_BRAKE);
        return;
    }

    brake_state = raw;
}

uint8_t Brake_GetState(void)
{
    return brake_state;
}

