#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "sensor_manager.h"
#include "vehicle.h"
#include "fault_manager.h"

int main(void)
{
    srand(time(NULL));

    while (1)
    {
        SensorManager_Update();
        Vehicle_Update();

        printf("Speed: %.2f km/h | Direction: %d | Fault: %d\n",
               Vehicle_GetSpeed(),
               Vehicle_GetDirection(),
               Fault_Get());

        Fault_Clear();
    }

    return 0;
}