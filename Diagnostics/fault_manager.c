#include "fault_manager.h"

static Fault_t current_fault = FAULT_NONE;

void Fault_Set(Fault_t fault)
{
    current_fault = fault;
}

Fault_t Fault_Get(void)
{
    return current_fault;
}

void Fault_Clear(void)
{
    current_fault = FAULT_NONE;
}