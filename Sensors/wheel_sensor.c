#include "wheel_sensor.h"
#include <stdio.h>


void Sensor_Init(void)
{
   
    printf("Sensors Initialized\n");
}


void Sensor_Read(SensorData_t *sensorData)
{
    if(sensorData != NULL)
    {
        printf("Enter WSS Value: ");
        scanf("%hu", &sensorData->WSS_Value);

    }
}