#include "fault_manager.h"

static FaultLevel_t level = FAULT_NONE;

void Fault_SetWarning(void)
{
    if (level != FAULT_CRITICAL)
        level = FAULT_WARNING;
}

void Fault_SetCritical(void)
{
    level = FAULT_CRITICAL;
}

FaultLevel_t Fault_GetLevel(void)
{
    return level;
}

void Fault_Clear(void)
{
    level = FAULT_NONE;
}