#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>  // Sleep(ms)
#else
#include <unistd.h>   // usleep(us)
#endif

#include "sensor_manager.h"
#include "vehicle.h"
#include "fault_manager.h"

int main(void)
{
    srand(time(NULL));

    const int iterations = 20;   // finite loop for testing
    const int delay_ms = 500;    // 500 ms delay

    for (int i = 0; i < iterations; i++)
    {
        SensorManager_Update();
        Vehicle_Update();

        float speed = Vehicle_GetSpeed();
        int dir = Vehicle_GetDirection();
        Fault_t fault = Fault_Get();

        // Print with fault highlighted in red
        if (fault != FAULT_NONE)
            printf("\033[0;31m"); // Red text
        else
            printf("\033[0;32m"); // Green text

        printf("Speed: %.2f km/h | Direction: %d | Fault: %d\n",
               speed, dir, fault);

        printf("\033[0m"); // Reset color

        Fault_Clear();

        // Delay
        #ifdef _WIN32
        Sleep(delay_ms);
        #else
        usleep(delay_ms * 1000);
        #endif
    }

    printf("Simulation finished.\n");
    return 0;
}