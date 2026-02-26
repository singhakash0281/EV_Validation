#include <stdio.h>
#include <stdint.h>
#include "wheel_speed.h"
#include "hal_sim.h"
#include "validation.h"
#include "fault_manager.h"

#define TIMEOUT_LIMIT 5

static float fl_rpm = 0.0f;
static float fr_rpm = 0.0f;
static float rl_rpm = 0.0f;
static float rr_rpm = 0.0f;

static uint16_t prev_fl = 0;
static uint8_t fl_timeout = 0;

void Wheel_Update(void)
{
    uint16_t fl = HAL_GetWheelFL();
    uint16_t fr = HAL_GetWheelFR();
    uint16_t rl = HAL_GetWheelRL();
    uint16_t rr = HAL_GetWheelRR();

    /* Validation */
    if (!Validate_Wheel(fl) || !Validate_Wheel(fr) ||
        !Validate_Wheel(rl) || !Validate_Wheel(rr))
    {
        printf("Wheel Validation: INVALID VALUE\n");
        Fault_Set(FAULT_WSS);
        return;
    }
    else
    {
        Fault_Clear(FAULT_WSS);
    }

    /* Timeout Detection */
    if (fl == prev_fl)
    {
        fl_timeout++;
        if (fl_timeout > TIMEOUT_LIMIT)
        {
            printf("Wheel Timeout: TIMEOUT DETECTED\n");
            Fault_Set(FAULT_TIMEOUT);
        }
    }
    else
    {
        fl_timeout = 0;
        Fault_Clear(FAULT_TIMEOUT);
    }

    prev_fl = fl;

    /* Convert to RPM */
    fl_rpm = fl * 0.5f;
    fr_rpm = fr * 0.5f;
    rl_rpm = rl * 0.5f;
    rr_rpm = rr * 0.5f;
}



float Wheel_GetFL(void)
{
    return fl_rpm;
}

float Wheel_GetFR(void)
{
    return fr_rpm;
}

float Wheel_GetRL(void)
{
    return rl_rpm;
}

float Wheel_GetRR(void)
{
    return rr_rpm;
}