// Object_ApplyDeferredType: ported from Pizza Connection 2 at 0x508d50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508d50
#include "pc2_port.h"

void __thiscall Object_ApplyDeferredType(void *self,int arg1)

{
  if (arg1 == 0x10) {
    Object_InitCompanyBuildingGraphics(self,-1);
    UI_SetChildIconAndRatingHeight((intptr_t)self);
  }
  else if (arg1 == 0x23) {
    *(uint32_t *)((intptr_t)self + 0x30) = 0x23;
    Object_SetState(self,4);
    *(uint32_t *)((intptr_t)self + 0xa0) = 0;
    return;
  }
  return;
}
