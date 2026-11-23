// UI_HitTestTopChild: ported from Pizza Connection 2 at 0x52ffe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ffe0
#include "pc2_port.h"

uint32_t __thiscall UI_HitTestTopChild(void *self,int *arg1,void *arg2)

{
  int value1;
  void *this_00;
  int value2;
  uint32_t uvalue3;
  
  if (arg2 != (void *)0x0) {
    value1 = *(int *)((intptr_t)self + 0xf0);
    do {
      value1 = value1 + -1;
      if ((value1 < 0) ||
         (this_00 = *(void **)(*(int *)((intptr_t)self + 0xec) + value1 * 8), this_00 == arg2)) {
        uvalue3 = UI_IsValidSize(arg2,*arg1 - *(int *)((intptr_t)self + 0x18),
                               arg1[1] - *(int *)((intptr_t)self + 0x1c));
        return uvalue3;
      }
    } while ((this_00 == (void *)0x0) ||
            (value2 = UI_IsValidSize(this_00,*arg1 - *(int *)((intptr_t)self + 0x18),
                                    arg1[1] - *(int *)((intptr_t)self + 0x1c)), value2 == 0));
  }
  return 0;
}
