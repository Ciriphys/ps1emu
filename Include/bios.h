#ifndef BIOS_H
#define BIOS_H

#define BIOS_ADDR 0xbfc00000
#define BIOS_SIZE 512 * 1024 // 512 Kb in size

typedef struct __bios 
{
    uint8_t* data;
} bios_t;

int init_bios(const char* path, bios_t* bios);
uint32_t bios_load32(uint32_t offset, bios_t* bios);

#endif