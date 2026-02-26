#include "Sensor_Proc.h"
#include <stdio.h>

int main()
{
    SensorData_t sensorData;

    Sensor_Init();
    Sensor_Read(&sensorData);

    printf("\n--- Sensor Data ---\n");
    printf("WSS: %u\n", sensorData.WSS_Value);
    printf("Accelerator: %u%%\n", sensorData.Acc_Pedal_Value);
    printf("Brake: %u%%\n", sensorData.Brake_Pedal_Value);

    return 0;
}