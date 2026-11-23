// Game_InitPlayerSlotTables: ported from Pizza Connection 2 at 0x4f6fb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6fb0
#include "pc2_port.h"

void __fastcall Game_InitPlayerSlotTables(int arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  uint32_t *uptr4;
  int value5;
  
  value3 = 0;
  value5 = 0x224;
  uptr4 = (uint32_t *)(arg1 + 0x114);
  do {
    value1 = *(int *)(value5 + (intptr_t)DAT_0057c670);
    if (value1 == 0) {
      uptr4[1] = 0;
      *uptr4 = 0;
    }
    else {
      uptr4[-0x2a] = value1;
      uvalue2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 8));
      uptr4[-0x29] = uvalue2;
      uvalue2 = Game_GetPlayerField8(DAT_0057c670,value3);
      uptr4[-0x35] = uvalue2;
    }
    value5 = value5 + 4;
    value3 = value3 + 1;
    uptr4 = uptr4 + 0x5a;
  } while (value5 < 0x23c);
  return;
}
