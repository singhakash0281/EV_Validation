#include "Brk_sensor.h"
#include <stdio.h>


void Sensor_Init(void)
{
   
    printf("Sensors Initialized\n");
}


void Sensor_Read(SensorData_t *sensorData)
{
    if(sensorData != NULL)
    {


        printf("Enter Brake Pedal Value (0-100): ");
        scanf("%hhu", &sensorData->Brake_Pedal_Value);
    }
}