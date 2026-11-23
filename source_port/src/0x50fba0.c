// GamePlan_ComputeEffectValue: ported from Pizza Connection 2 at 0x50fba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fba0
#include "pc2_port.h"

int64_t __thiscall GamePlan_ComputeEffectValue(void *self,int arg1)

{
  int value1;
  uint32_t extraout_EDX;
  int64_t lvalue2;
  
  value1 = GamePlan_ComputeAverageEffect(self,arg1);
  if (value1 < 0x28) {
    return CONCAT44(extraout_EDX,0x28 - value1);
  }
  lvalue2 = __ftol();
  return lvalue2;
}
