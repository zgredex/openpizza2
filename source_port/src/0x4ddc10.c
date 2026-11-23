// Player_RemoveBranch: ported from Pizza Connection 2 at 0x4ddc10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddc10
#include "pc2_port.h"

void __thiscall Player_RemoveBranch(void *self,int arg1)

{
  uint32_t *uptr1;
  void *this_00;
  int value2;
  int value3;
  
                    /* Removes a branch from a player's lists and orders. */
  Game_AbortOrdersTargetingObject(*(int *)(arg1 + 0x16f0),1,(void *)0x0);
  value2 = *(int *)((intptr_t)self + 0x140) + -1;
  if (-1 < value2) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)self + 300),value2,(int *)0x0);
      if (uptr1[3] == *(int *)(arg1 + 0x3c)) {
        Company_DeactivatePlanEntry(self,uptr1,1);
      }
      value2 = value2 + -1;
    } while (-1 < value2);
  }
  IDMap_RemoveByKey((void *)((intptr_t)self + 0x148),arg1);
  value2 = *(int *)((intptr_t)self + 0x194);
  value3 = 0;
  if (0 < value2) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x180),value3,(int *)0x0);
      Storage_RemoveRecord(this_00,arg1);
      value3 = value3 + 1;
    } while (value3 < value2);
  }
  return;
}
