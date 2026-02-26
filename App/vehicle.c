#include <stdint.h>
#include "vehicle.h"
#include "wheel_speed.h"
#include "brake.h"


static float vehicle_speed = 0;
static Direction_t direction = VEH_STOPPED;

void Vehicle_Update(void)
{
    float rpm = Wheel_GetRPM();
    uint8_t brake = Brake_GetState();

    vehicle_speed = rpm * 0.1f;

    if (brake || vehicle_speed < 1.0f)
        direction = VEH_STOPPED;
    else
        direction = VEH_FORWARD;
}

float Vehicle_GetSpeed(void)
{
    return vehicle_speed;
}

Direction_t Vehicle_GetDirection(void)
{
    return direction;
}
