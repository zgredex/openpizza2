// Game_CountActiveStats: ported from Pizza Connection 2 at 0x50fe50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fe50
#include "pc2_port.h"

int __fastcall Game_CountActiveStats(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  
  value1 = 0;
  ptr2 = (int *)(arg1 + 100);
  value3 = 0x56;
  do {
    if (0 < *ptr2) {
      value1 = value1 + 1;
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return value1;
}
