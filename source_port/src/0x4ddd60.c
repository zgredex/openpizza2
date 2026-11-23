// Company_RemoveRecipe: ported from Pizza Connection 2 at 0x4ddd60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddd60
#include "pc2_port.h"

void __thiscall Company_RemoveRecipe(void *self,uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  
  Game_ClearObjectReferences((intptr_t)arg1);
  value1 = *(int *)((intptr_t)self + 0x124);
  value3 = 0;
  if (0 < value1) {
    while( true ) {
      uptr2 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)self + 0x110),value3,(int *)0x0);
      if (uptr2 == arg1) break;
      value3 = value3 + 1;
      if (value1 <= value3) {
        Company_InvalidateAllBranchRatings((intptr_t)self);
        return;
      }
    }
    IDMap_RemoveRecursive((void *)((intptr_t)self + 0x110),value3);
    if (arg1 != (uint32_t *)0x0) {
      (**(code **)*arg1)(1);
    }
  }
  Company_InvalidateAllBranchRatings((intptr_t)self);
  return;
}
