#ifndef CPU_H_
#define CPU_H_

#include "common.h"
#include "interconnect.h"

typedef struct __cpu
{
  uint32_t pc; // Program counter
  interconnect_t* interconnect; // Peripheral handler
} cpu_t;

cpu_t init_cpu(interconnect_t* interconnect);
void reset(cpu_t* cpu);
void next(cpu_t* cpu);
void cpu_execute(uint32_t instruction);

void panic(const char* format, ...);

#endif // CPU_H_
