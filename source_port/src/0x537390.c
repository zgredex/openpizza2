// Surface_CopyRect16: ported from Pizza Connection 2 at 0x537390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537390
#include "pc2_port.h"

uint32_t __thiscall Surface_CopyRect16(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int value4;
  uint32_t *uptr5;
  uint32_t *uptr6;
  int local_4;
  
  value1 = arg3;
  if ((*(uint8_t *)((intptr_t)self + 0x10) < 0x11) && (0xe < *(uint8_t *)((intptr_t)self + 0x10))) {
    value4 = *(int *)((intptr_t)self + 8);
    local_4 = 0;
    if (arg3 < 0) {
      arg3 = 0;
      local_4 = -value1;
      value4 = value4 + value1;
    }
    value1 = arg3;
    if ((intptr_t)(uint32_t)*(uint16_t *)(arg1 + 0x1c) <= value4 + arg3) {
      value4 = (uint32_t)*(uint16_t *)(arg1 + 0x1c) - arg3;
    }
    if (0 < value4) {
      if (value4 < *(int *)((intptr_t)self + 8)) {
        uvalue2 = *(int *)((intptr_t)self + 4) * *(int *)((intptr_t)self + 8);
        uptr5 = *(uint32_t **)((intptr_t)self + 0x18);
        for (uvalue3 = uvalue2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          *uptr5 = 0;
          uptr5 = uptr5 + 1;
        }
        for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
          *(uint8_t *)uptr5 = 0;
          uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
        }
      }
      arg3 = *(int *)((intptr_t)self + 4);
      uptr5 = (uint32_t *)(*(int *)((intptr_t)self + 0x18) + arg3 * local_4 * 2);
      if (arg2 < 0) {
        arg3 = arg3 + arg2 * -2;
        uptr5 = uptr5 + -arg2;
        arg2 = 0;
      }
      uptr6 = (uint32_t *)
               (*(int *)(arg1 + 0x28) + (*(int *)(arg1 + 0x20) * value1 + arg2) * 2);
      if (0 < value4) {
        value1 = *(int *)(arg1 + 0x20);
        arg1 = value4;
        do {
          Memory_Fill16(uptr5,uptr6,arg3 * 2,1);
          uptr6 = (uint32_t *)((intptr_t)uptr6 + value1 * 2);
          uptr5 = (uint32_t *)((intptr_t)uptr5 + *(int *)((intptr_t)self + 4) * 2);
          arg1 = arg1 + -1;
        } while (arg1 != 0);
      }
      return 1;
    }
  }
  return 0;
}
