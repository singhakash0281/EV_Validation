#ifndef SENSOR_PROC_H
#define SENSOR_PROC_H

#include <stdint.h>


typedef struct
{
    uint16_t WSS_Value;          // Wheel Speed Sensor value
   
} SensorData_t;


void Sensor_Init(void);

void Sensor_Read(SensorData_t *sensorData);

#endif