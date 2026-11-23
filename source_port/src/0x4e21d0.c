// Game_UnlinkBuildingObject: ported from Pizza Connection 2 at 0x4e21d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e21d0
#include "pc2_port.h"

void __thiscall Game_UnlinkBuildingObject(void *self,int arg1)

{
  int value1;
  int value2;
  int *ptr3;
  
  ptr3 = (int *)0x0;
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),arg1,(int *)0x0);
  if (value1 != 0) {
    *(uint32_t *)(value1 + 0x110) = 0xffffffff;
    *(uint32_t *)(value1 + 0x10c) = 0xffffffff;
    value1 = *(int *)((intptr_t)self + 0x1cc);
    value2 = 0;
    if (0 < value1) {
      do {
        ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value2,(int *)0x0);
        if (*ptr3 == arg1) break;
        value2 = value2 + 1;
      } while (value2 < value1);
    }
    IDMap_RemoveByKey((void *)((intptr_t)self + 0x1b8),(intptr_t)ptr3);
  }
  return;
}
