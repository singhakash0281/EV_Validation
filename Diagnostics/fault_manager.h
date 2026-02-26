#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H

#include <stdint.h>

#define FAULT_WSS     0x01
#define FAULT_BRAKE   0x02
#define FAULT_ACC     0x04
#define FAULT_TIMEOUT 0x08

void Fault_Set(uint8_t fault);
void Fault_Clear(uint8_t fault);
uint8_t Fault_Get(void);

#endif