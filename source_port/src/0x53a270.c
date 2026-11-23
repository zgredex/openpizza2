// Gfx_BlitScaled16Rows: ported from Pizza Connection 2 at 0x53a270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a270
#include "pc2_port.h"

void __thiscall
Gfx_BlitScaled16Rows(void *self,int arg1,uint32_t *arg2,int arg3,uint32_t arg4)

{
  uint8_t uvalue1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  uint32_t *uptr8;
  int local_4;
  
  uvalue4 = arg4;
  if ((((*(uint8_t *)((intptr_t)self + 4) & 1) == 0) && (*(char *)((intptr_t)self + 5) == '\x10')) &&
     (*(int *)(arg1 + 0x28) != 0)) {
    uptr7 = (uint32_t *)(intptr_t)*(short *)((intptr_t)self + 8);
    local_4 = 0;
    uptr6 = uptr7;
    if ((intptr_t)arg4 < 0) {
      arg4 = 0;
      local_4 = -uvalue4;
      uptr6 = (uint32_t *)((intptr_t)uptr7 + uvalue4);
    }
    uvalue4 = arg4;
    if ((intptr_t)(uint32_t)*(uint16_t *)(arg1 + 0x1c) <= (intptr_t)((intptr_t)uptr6 + arg4)) {
      uptr6 = (uint32_t *)(*(uint16_t *)(arg1 + 0x1c) - arg4);
    }
    if ((intptr_t)uptr6 < 1) {
      uvalue1 = *(uint8_t *)((intptr_t)self + 0x1c);
      uvalue3 = (intptr_t)*(short *)((intptr_t)self + 6) * (intptr_t)uptr7;
      for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
        *arg2 = CONCAT22(CONCAT11(uvalue1,uvalue1),CONCAT11(uvalue1,uvalue1));
        arg2 = arg2 + 1;
      }
      for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
        *(uint8_t *)arg2 = uvalue1;
        arg2 = (uint32_t *)((intptr_t)arg2 + 1);
      }
      return;
    }
    if (uptr6 != uptr7) {
      uvalue1 = *(uint8_t *)((intptr_t)self + 0x1c);
      uvalue5 = (intptr_t)*(short *)((intptr_t)self + 6) * (intptr_t)uptr7;
      uptr7 = arg2;
      for (uvalue3 = uvalue5 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
        *uptr7 = CONCAT22(CONCAT11(uvalue1,uvalue1),CONCAT11(uvalue1,uvalue1));
        uptr7 = uptr7 + 1;
      }
      for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *(uint8_t *)uptr7 = uvalue1;
        uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
      }
    }
    arg4 = (uint32_t)*(short *)((intptr_t)self + 6);
    uptr7 = (uint32_t *)(arg4 * local_4 + (intptr_t)arg2);
    if (arg3 < 0) {
      arg4 = arg4 + arg3 * 2;
      uptr7 = (uint32_t *)((intptr_t)uptr7 + arg3 * -2);
      arg3 = 0;
    }
    value2 = *(int *)(arg1 + 0x20);
    uptr8 = (uint32_t *)(*(int *)(arg1 + 0x28) + (value2 * uvalue4 + arg3) * 2);
    if (0 < (intptr_t)uptr6) {
      arg2 = uptr6;
      do {
        Memory_Fill16(uptr7,uptr8,arg4,1);
        uptr7 = (uint32_t *)((intptr_t)uptr7 + (intptr_t)*(short *)((intptr_t)self + 6));
        uptr8 = (uint32_t *)((intptr_t)uptr8 + value2 * 2);
        arg2 = (uint32_t *)((intptr_t)arg2 + -1);
      } while (arg2 != (uint32_t *)0x0);
    }
  }
  return;
}
