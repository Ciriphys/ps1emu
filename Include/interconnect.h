#ifndef INTERCONNECT_H
#define INTERCONNECT_H

#include "common.h"
#include "bios.h"

typedef struct __interconnect 
{
    bios_t* bios;
} interconnect_t;

typedef struct __pair 
{
    uint32_t first;
    uint32_t second;
} pair_t;

uint32_t contains(pair_t range, uint32_t address, int* valid);
interconnect_t init_interconnect(bios_t* bios);
uint32_t load32(interconnect_t* interconnect, uint32_t address);

// extern const pair_t BIOS_DOMAIN;

#endif