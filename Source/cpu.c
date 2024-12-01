#include "common.h"
#include "bios.h"
#include "cpu.h"

cpu_t init_cpu(interconnect_t* interconnect)
{
    cpu_t cpu = { .pc = 0, .interconnect = interconnect }; 
    reset(&cpu);

    return cpu;
}

void reset(cpu_t* cpu)
{
    // Reset the cpu to the BIOS address
    cpu->pc = BIOS_ADDR;
}

void next(cpu_t* cpu)
{
    uint32_t instruction = load32(cpu->interconnect, cpu->pc);
    cpu->pc += 4;
    cpu_execute(instruction);
}

void cpu_execute(uint32_t instruction)
{
    panic("No implementation has been provided for [cpu_execute].\nHalted at instruction: {0x%x}\n", instruction);
}

void panic(const char *format, ...) 
{
    va_list args;
    fprintf(stderr, "[PANIC] ");

    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    exit(EXIT_FAILURE);
}