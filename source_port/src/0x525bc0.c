// UI_QueueCommand: ported from Pizza Connection 2 at 0x525bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525bc0
#include "pc2_port.h"

void __thiscall
UI_QueueCommand(void *self,int arg1,int arg2,int arg3,int arg4,int arg5)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  
  value1 = (intptr_t)self + 0x1cc;
  CS_Enter(value1);
  uvalue2 = *(uint32_t *)((intptr_t)self + 0x82c0);
  uvalue3 = *(uint32_t *)((intptr_t)self + 0x82bc);
  if ((uvalue2 + 1 & 0x3ff) != uvalue3) {
    if ((0x22 < arg4) || (arg4 < 0)) {
      for (; uvalue3 != uvalue2; uvalue3 = uvalue3 + 1 & 0x3ff) {
        if ((((*(int *)((intptr_t)self + (uvalue3 * 5 + 0xcb2) * 4) == arg4) &&
             (*(int *)((intptr_t)self + uvalue3 * 0x14 + 0x32bc) == arg1)) &&
            (*(int *)((intptr_t)self + uvalue3 * 0x14 + 0x32c0) == arg2)) &&
           ((*(int *)((intptr_t)self + uvalue3 * 0x14 + 0x32c4) == arg3 &&
            (*(int *)((intptr_t)self + uvalue3 * 0x14 + 0x32cc) == arg5)))) {
          CS_Leave(value1);
          return;
        }
      }
    }
    *(int *)((intptr_t)self + uvalue2 * 0x14 + 0x32bc) = arg1;
    *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x82c0) * 0x14 + 0x32c0) = arg2;
    *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x82c0) * 0x14 + 0x32c4) = arg3;
    *(int *)((intptr_t)self + (*(int *)((intptr_t)self + 0x82c0) + 0x28a) * 0x14) = arg4;
    *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x82c0) * 0x14 + 0x32cc) = arg5;
    *(uint32_t *)((intptr_t)self + 0x82c0) = *(int *)((intptr_t)self + 0x82c0) + 1U & 0x3ff;
  }
  CS_Leave(value1);
  return;
}
