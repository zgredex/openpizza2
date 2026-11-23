// Game_ResetBuildingUtilization: ported from Pizza Connection 2 at 0x4e28e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e28e0
#include "pc2_port.h"

void __fastcall Game_ResetBuildingUtilization(int arg1)

{
  int *ptr1;
  void *self;
  int value2;
  
  value2 = 0;
  *(int *)(arg1 + 0x6c) = *(int *)(arg1 + 0x6c) + 1;
  if (0 < *(int *)(arg1 + 0x1cc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)(arg1 + 0x1b8),value2,(int *)0x0);
      if (ptr1[1] == 0x1d) {
        self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
        *(uint32_t *)((intptr_t)self + 0xa8) = 100;
        Object_GetPlayerValue(self,-1);
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)(arg1 + 0x1cc));
  }
  return;
}
