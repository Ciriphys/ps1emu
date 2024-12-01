#include "common.h"
#include "bios.h"

int init_bios(const char* path, bios_t* bios)
{
    // Allocate space for the bios
    bios->data = (uint8_t*)malloc(BIOS_SIZE * sizeof(uint8_t));
    if(!bios->data) { return ALLOCATION_FAILURE; }

    // Load file
    FILE* handle = fopen(path, "rb");
    if(!handle) { return INVALID_HANDLE; }

    uint32_t result = fread(bios->data, sizeof(uint8_t), BIOS_SIZE, handle);

    // Close the handle and check for errors
    fclose(handle);
    return OK_STATUS + (result != BIOS_SIZE) * INVALID_IO;
}

uint32_t bios_load32(uint32_t offset, bios_t* bios)
{
    uint8_t b0 = bios->data[offset + 0];
    uint8_t b1 = bios->data[offset + 1];
    uint8_t b2 = bios->data[offset + 2];
    uint8_t b3 = bios->data[offset + 3];

    uint32_t result = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
    return result;
}