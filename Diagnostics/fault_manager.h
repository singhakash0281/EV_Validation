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
typedef enum
{
    FAULT_NONE,
    FAULT_WARNING,
    FAULT_CRITICAL
} FaultLevel_t;

void Fault_SetWarning(void);
void Fault_SetCritical(void);
FaultLevel_t Fault_GetLevel(void);
void Fault_Clear(void);

#endif