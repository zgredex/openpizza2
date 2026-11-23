// UI_SliderStepValue: ported from Pizza Connection 2 at 0x52a160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52a160
#include "pc2_port.h"

void __thiscall UI_SliderStepValue(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  int64_t lvalue3;
  
  uvalue2 = *(uint32_t *)((intptr_t)self + 0xd0);
  if (0x7fffffff < uvalue2) {
    lvalue3 = __ftol();
    uvalue2 = (uint32_t)lvalue3;
  }
  value1 = *(int *)((intptr_t)self + 0x8c);
  if (arg1 != 0) {
    uvalue2 = -uvalue2;
  }
  UI_SetClampedValue(self,value1 + uvalue2,0);
  if (*(int *)((intptr_t)self + 0x8c) != value1) {
    UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),0x1a,value1);
    if (*(int *)((intptr_t)self + 0xc4) != 0) {
      UI_QueueControlCommand
                (*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),0x19,*(int *)((intptr_t)self + 0x8c));
    }
    UI_QueueControlCommand
              (*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),0x18,*(int *)((intptr_t)self + 0x8c));
    UI_ClipRect(*(void **)((intptr_t)self + 8),(int *)((intptr_t)self + 0x28),1);
  }
  return;
}
