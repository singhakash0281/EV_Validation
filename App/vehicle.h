#ifndef VEHICLE_H
#define VEHICLE_H

typedef enum
{
    STANDSTILL = 0,
    FORWARD
} Direction_t;

void Vehicle_Update(void);
float Vehicle_GetSpeed(void);
Direction_t Vehicle_GetDirection(void);

#endif