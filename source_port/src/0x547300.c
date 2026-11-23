// Sound_SetParam: ported from Pizza Connection 2 at 0x547300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547300
#include "pc2_port.h"

void __thiscall Sound_SetParam(void *self,uint32_t arg1)

{
  uint32_t unaff_ESI;
  
  if (*(int *)((intptr_t)self + 0x1d0) != 0) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x7c))
              (*(int **)((intptr_t)self + 8),arg1,*(int *)((intptr_t)self + 0x1d0));
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x5c))(*(int **)((intptr_t)self + 8),arg1,unaff_ESI);
  }
  return;
}
