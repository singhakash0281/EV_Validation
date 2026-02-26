#ifndef VEHICLE_H
#define VEHICLE_H

typedef enum
{
    VEH_STOPPED,
    VEH_FORWARD
} Direction_t;

void Vehicle_Update(void);
float Vehicle_GetSpeed(void);
Direction_t Vehicle_GetDirection(void);

#endif