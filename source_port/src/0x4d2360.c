// Game_GetObjectBottom: ported from Pizza Connection 2 at 0x4d2360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2360
#include "pc2_port.h"

int __fastcall Game_GetObjectBottom(int arg1)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x28),(int *)0x0);
  value1 = *(int *)(value1 + 0xfa8);
  if (value1 == 0) {
    return -1;
  }
  return *(int *)(*(int *)(value1 + 0x4c) + 4 + *(int *)(arg1 + 0x24) * 0xc) +
         (*(int *)(value1 + 0x10) >> 1) + *(int *)(value1 + 0x10);
}
