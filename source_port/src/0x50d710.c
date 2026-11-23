// Object_BeginServiceDecision: ported from Pizza Connection 2 at 0x50d710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d710
#include "pc2_port.h"

void __thiscall Object_BeginServiceDecision(void *self,float arg1)

{
  int value1;
  float fVar2;
  
                    /* Switches an object into service-decision state toward a target. */
  value1 = State_Is2DOr2E((intptr_t)arg1);
  if (value1 == 0) {
    *(uint32_t *)((intptr_t)self + 0x108) = 3;
    fVar2 = Game_ComputeObjectValue(self,arg1);
    UI_SetChildRecordVariant(self,(intptr_t)fVar2);
  }
  return;
}
