// Game_RefreshBuildingCondition: ported from Pizza Connection 2 at 0x4e2950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2950
#include "pc2_port.h"

void __fastcall Game_RefreshBuildingCondition(int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  
  value3 = 0;
  *(int *)(arg1 + 0x68) = *(int *)(arg1 + 0x68) + 1;
  if (0 < *(int *)(arg1 + 0x1cc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)(arg1 + 0x1b8),value3,(int *)0x0);
      if (ptr1[1] == 0x1e) {
        value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
        *(uint32_t *)(value2 + 0xa8) = 100;
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(arg1 + 0x1cc));
  }
  return;
}
