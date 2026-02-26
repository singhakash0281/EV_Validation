#include "validation.h"

uint8_t Validate_Wheel(uint16_t pulse)
{
    return (pulse <= 300);
}

uint8_t Validate_Accelerator(float percent)
{
    return (percent >= 0 && percent <= 100);
}

uint8_t Validate_Brake(uint8_t brake)
{
    return (brake == 0 || brake == 1);
}