// GamePlan_SetActiveEffect: ported from Pizza Connection 2 at 0x50fb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fb70
#include "pc2_port.h"

void __thiscall GamePlan_SetActiveEffect(void *self,int arg1,int arg2)

{
  int64_t lvalue1;
  
  if (arg1 == 0) {
    *(uint32_t *)((intptr_t)self + 4) = 0;
    return;
  }
  lvalue1 = GamePlan_ComputeEffectValue(self,arg2);
  *(int *)((intptr_t)self + 4) = arg1;
  *(int *)((intptr_t)self + 0x28) = (intptr_t)lvalue1;
  return;
}
