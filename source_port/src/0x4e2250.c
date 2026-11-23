// Game_FindCityIndex: ported from Pizza Connection 2 at 0x4e2250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2250
#include "pc2_port.h"

int __fastcall Game_FindCityIndex(int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = &DAT_00563874;
  do {
    if (*ptr2 == *(int *)(arg1 + 0x1dc)) {
      return value1;
    }
    ptr2 = ptr2 + 1;
    value1 = value1 + 1;
  } while ((intptr_t)ptr2 < 0x563890);
  return 7;
}
