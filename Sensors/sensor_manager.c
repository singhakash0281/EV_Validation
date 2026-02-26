#include "sensor_manager.h"
#include "wheel_speed.h"
#include "accelerator.h"
#include "brake.h"
#include <stdint.h>
void SensorManager_Update(void)
{
    Wheel_Update();
    Accelerator_Update();
    Brake_Update();
}
