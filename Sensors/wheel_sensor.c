
#include "wheel_speed.h"
#include "hal_sim.h"
#include "validation.h"
#include "fault_manager.h"

static float wheel_rpm = 0;

void Wheel_Update(void)
{
    uint16_t pulse = HAL_GetWheelPulse();

    if (!Validate_Pulse(pulse))
    {
        Fault_Set(FAULT_WHEEL);
        return;
    }

    wheel_rpm = pulse * 0.5f;  // conversion example
}

float Wheel_GetRPM(void)
{
    return wheel_rpm;
}