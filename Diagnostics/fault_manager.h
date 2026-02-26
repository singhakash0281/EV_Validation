#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H

typedef enum
{
    FAULT_NONE,
    FAULT_WHEEL,
    FAULT_ACCELERATOR,
    FAULT_BRAKE
} Fault_t;

void Fault_Set(Fault_t fault);
Fault_t Fault_Get(void);
void Fault_Clear(void);

#endif