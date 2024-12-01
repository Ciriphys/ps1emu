#include "interconnect.h"
#include "common.h"
#include "cpu.h"

const pair_t BIOS_DOMAIN = { BIOS_ADDR, BIOS_SIZE };

interconnect_t init_interconnect(bios_t* bios)
{
    // Initialize peripherals
    interconnect_t interconnect = { .bios = bios };
    return interconnect;
}

uint32_t contains(pair_t range, uint32_t address, int* valid)
{
    *valid = 0;

    // Check if address is within the the scope of the peripheral domain
    if(address >= range.first and address < range.first + range.second) 
    { 
        *valid = 1;
        return address - range.first;
    }

    return 0;
}

uint32_t load32(interconnect_t* interconnect, uint32_t address)
{
    int valid = 0;
    uint32_t offset = contains(BIOS_DOMAIN, address, &valid);

    if(valid) { return bios_load32(offset, interconnect->bios); }

    panic("Unhandled address: {0x%x} [load32]\n", address);
    return -1;
}