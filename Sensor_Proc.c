#include "Sensor_Proc.h"
#include <stdio.h>


void Sensor_Init(void)
{
   
    printf("Sensors Initializ\n");
}


void Sensor_Read(SensorData_t *sensorData)
{
    if(sensorData != NULL)
    {
        printf("Enter WSS Value: ");
        scanf("%hu", &sensorData->WSS_Value);

        printf("Enter Accelerator Pedal Value (0-100): ");
        scanf("%hhu", &sensorData->Acc_Pedal_Value);

        printf("Enter Brake Pedal Value (0-100): ");
        scanf("%hhu", &sensorData->Brake_Pedal_Value);
    }
}