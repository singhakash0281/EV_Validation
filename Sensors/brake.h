#ifndef SENSOR_PROC_H
#define SENSOR_PROC_H

#include <stdint.h>


typedef struct
{
    
    uint8_t  Brake_Pedal_Value;  // Brake pedal percentage (0-100)

} SensorData_t;


void Sensor_Init(void);

void Sensor_Read(SensorData_t *sensorData);

#endif