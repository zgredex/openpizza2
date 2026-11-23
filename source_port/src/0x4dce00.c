// Game_InitCompanyAIStrategy: ported from Pizza Connection 2 at 0x4dce00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dce00
#include "pc2_port.h"

void __fastcall Game_InitCompanyAIStrategy(int arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  
  value4 = -1;
  value3 = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if ((value1 != 0) && (*(int *)(value1 + 0x50) == 0)) {
      value4 = value4 + 1;
    }
    value3 = value3 + 1;
  } while (value3 < 6);
  uvalue2 = Random_RangeFast(0,7);
  *(uint32_t *)(arg1 + 0x1148) = uvalue2;
  *(int *)(arg1 + 0x1150) = value4 * 5000;
  value3 = (intptr_t)(0xc / (int64_t)value4) + 3;
  *(int *)(arg1 + 0x114c) = value3;
  *(int *)(arg1 + 0x1154) = value3;
  return;
}
