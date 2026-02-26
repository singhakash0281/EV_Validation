#include "validation.h"

int Validate_Pulse(uint16_t pulse)
{
    return (pulse <= 300);
}

int Validate_Accelerator(float percent)
{
    return (percent >= 0.0f && percent <= 100.0f);
}

int Validate_Brake(uint8_t brake)
{
    return (brake == 0 || brake == 1);
}