#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "hal_sim.h"
#include "sensor_manager.h"
#include "vehicle.h"
#include "fault_manager.h"

static void PrintFaultDetails(uint8_t fault)
{
    if (fault & FAULT_WSS)
        printf("Wheel Speed Sensor Fault\n");

    if (fault & FAULT_ACC)
        printf("Accelerator Fault\n");

    if (fault & FAULT_BRAKE)
        printf("Brake Fault\n");

    if (fault & FAULT_TIMEOUT)
        printf("Sensor Timeout Fault\n");
}

int main()
{
    static unsigned long alive_counter = 0;

    while (1)
    {
        alive_counter++;

        HAL_UpdateInputs();
        SensorManager_Update();
        Vehicle_Update();

        uint8_t fault = Fault_Get();

        printf("\n===== VEHICLE STATUS =====\n");
        printf("Alive Counter: %lu\n", alive_counter);
        printf("Speed: %.2f km/h\n", Vehicle_GetSpeed());
        printf("Direction: %d\n", Vehicle_GetDirection());
        printf("Fault Byte: 0x%02X\n", fault);

        if (fault)
            PrintFaultDetails(fault);

        printf("\n");

        sleep(1);
    }

    return 0;
}