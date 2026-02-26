#include "fault_manager.h"

static uint8_t fault_byte = 0;

void Fault_Set(uint8_t fault)
{
    fault_byte |= fault;
}

void Fault_Clear(uint8_t fault)
{
    fault_byte &= ~fault;
}

uint8_t Fault_Get(void)
{
    return fault_byte;
}