#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdint.h>

uint8_t Validate_Wheel(uint16_t pulse);
uint8_t Validate_Accelerator(float percent);
uint8_t Validate_Brake(uint8_t brake);

#endif