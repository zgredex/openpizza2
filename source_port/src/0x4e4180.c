// Array_FindEmptySlot8: ported from Pizza Connection 2 at 0x4e4180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4180
#include "pc2_port.h"

void __fastcall Array_FindEmptySlot8(int arg1)

{
  int value1;
  short *psVar2;
  
  value1 = 0;
  psVar2 = (short *)(arg1 + 0x78);
  do {
    if (*psVar2 == -1) {
      return;
    }
    value1 = value1 + 1;
    psVar2 = psVar2 + 6;
  } while (value1 < 8);
  return;
}
