// Game_IsBuildingOpenAtHour: ported from Pizza Connection 2 at 0x47e520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e520
#include "pc2_port.h"

uint8_t __fastcall Game_IsBuildingOpenAtHour(void *arg1)

{
  int value1;
  uint32_t local_8;
  uint32_t local_4;
  
  if (*(char *)((intptr_t)arg1 + 0x16f5) != '\0') {
    return 0;
  }
  value1 = Game_CountOperatingObjectsByType(arg1,0);
  if (value1 == 0) {
    return 0;
  }
  Game_GetDateFields(DAT_0057c670,&local_8,(int *)&local_4);
  if (*(char *)(local_8 + 0x1a08 + (intptr_t)arg1) != '\0') {
    return 1;
  }
  if (0x3b < (intptr_t)local_4) {
    local_8 = local_8 + local_4 / 0x3c;
  }
  if (0x17 < (intptr_t)local_8) {
    local_8 = local_8 % 0x18;
  }
  return *(uint8_t *)(local_8 + 0x1a08 + (intptr_t)arg1);
}
