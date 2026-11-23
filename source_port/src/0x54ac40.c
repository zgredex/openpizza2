// UI_AdvanceChildProgress: ported from Pizza Connection 2 at 0x54ac40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ac40
#include "pc2_port.h"

void __thiscall UI_AdvanceChildProgress(void *self,void *arg1,uint32_t arg2,int arg3)

{
  int value1;
  int value2;
  int64_t lvalue3;
  
  if (*(float *)(arg3 + 0x20) != 0.0) {
    *(float *)(arg3 + 0x1c) =
         (float)arg2 * *(float *)(arg3 + 0x20) * 0.001 + *(float *)(arg3 + 0x1c);
    lvalue3 = __ftol();
    value1 = *(int *)(arg3 + 0xc);
    value2 = (intptr_t)lvalue3;
    if ((intptr_t)lvalue3 < value1) {
      *(uint32_t *)(arg3 + 0x20) = 0;
      *(float *)(arg3 + 0x1c) = (float)value1;
      value2 = value1;
    }
    UI_MoveChildToPosition(arg1,value2,*(int *)((intptr_t)self + 0x24));
  }
  return;
}
