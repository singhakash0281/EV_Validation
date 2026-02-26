#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdint.h>

int Validate_Pulse(uint16_t pulse);
int Validate_Accelerator(float percent);
int Validate_Brake(uint8_t brake);

#endif