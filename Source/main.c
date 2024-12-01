#include "interconnect.h"
#include "common.h"
#include "bios.h"
#include "cpu.h"

int main(void) 
{
  bios_t bios; 
  int result = init_bios("Roms/BIOS/SCPH1001.BIN", &bios);
  if(result) { 
    panic("BIOS was not loaded correctly. Error code: (%d) [main]\n", result); 
  }

  interconnect_t interconnect = init_interconnect(&bios); 
  cpu_t cpu = init_cpu(&interconnect);

  while(1) { next(&cpu); }

  return 0;
}
