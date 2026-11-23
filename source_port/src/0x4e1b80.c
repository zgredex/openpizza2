// Game_ResetRecordTurnCounters: ported from Pizza Connection 2 at 0x4e1b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1b80
#include "pc2_port.h"

void __fastcall Game_ResetRecordTurnCounters(int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)(arg1 + 0x124)) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x110),value2,(int *)0x0);
      *(uint32_t *)(value1 + 0x30c) = 0;
      value2 = value2 + 1;
    } while (value2 < *(int *)(arg1 + 0x124));
  }
  return;
}
