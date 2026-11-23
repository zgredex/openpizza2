// Game_GetHourlyValue: ported from Pizza Connection 2 at 0x47e470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e470
#include "pc2_port.h"

uint8_t __thiscall Game_GetHourlyValue(void *self,int arg1)

{
  int value1;
  uint32_t local_8;
  int local_4;
  
  if (*(char *)((intptr_t)self + 0x16f5) != '\0') {
    return 0;
  }
  value1 = Game_CountOperatingObjectsByType(self,0);
  if (value1 == 0) {
    return 0;
  }
  Game_GetDateFields(DAT_0057c670,&local_8,&local_4);
  if (0x3b < local_4 + arg1) {
    local_8 = local_8 + (uint32_t)(local_4 + arg1) / 0x3c;
  }
  if (0x17 < (intptr_t)local_8) {
    local_8 = local_8 % 0x18;
  }
  return *(uint8_t *)(local_8 + 0x1a08 + (intptr_t)self);
}
