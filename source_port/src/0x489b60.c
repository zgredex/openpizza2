// Game_AdvanceAnimFrame: ported from Pizza Connection 2 at 0x489b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489b60
#include "pc2_port.h"

void __fastcall Game_AdvanceAnimFrame(int arg1)

{
  int value1;
  int value2;
  
  value1 = IDMap_Lookup((void *)(arg1 + 0x74),*(int *)(arg1 + 0x344),(int *)0x0);
  if (value1 != 0) {
    value2 = *(int *)(arg1 + 0x350) + 1;
    *(int *)(arg1 + 0x350) = value2;
    if (3 < value2) {
      *(uint32_t *)(arg1 + 0x350) = 0;
    }
    if (*(short *)(value1 + (*(int *)(arg1 + 0x350) + (*(int *)(arg1 + 0x354) + 10) * 6) * 2)
        == -1) {
      *(uint32_t *)(arg1 + 0x350) = 0;
    }
  }
  return;
}
