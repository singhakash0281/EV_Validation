#include "vehicle.h"
#include "wheel_speed.h"
#include "brake.h"
#include "fault_manager.h"
#include <stdint.h>

static float vehicle_speed = 0;
static Direction_t direction = STANDSTILL;

void Vehicle_Update(void)
{
    uint8_t fault = Fault_Get();

    if (fault & (FAULT_WSS | FAULT_ACC | FAULT_TIMEOUT))
    {
        vehicle_speed = 0;
        direction = STANDSTILL;
        return;
    }

    float avg = (Wheel_GetFL() + Wheel_GetFR() +
                 Wheel_GetRL() + Wheel_GetRR()) / 4.0f;

    vehicle_speed = avg * 0.1f;

    if (Brake_GetState())
        direction = STANDSTILL;
    else if (avg > 0)
        direction = FORWARD;
    else
        direction = STANDSTILL;
}

float Vehicle_GetSpeed(void) { return vehicle_speed; }
Direction_t Vehicle_GetDirection(void) { return direction; }