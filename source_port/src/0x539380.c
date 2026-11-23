// Gfx_Blit16Clipped: ported from Pizza Connection 2 at 0x539380.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539380
#include "pc2_port.h"

void __thiscall
Gfx_Blit16Clipped(void *self,int arg1,int arg2,int arg3,int arg4,int arg5,int arg6
                 ,int arg7)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint64_t *uptr6;
  uint64_t *uptr7;
  uint64_t *uptr8;
  uint64_t *uptr9;
  uint64_t *uptr10;
  int local_18;
  int local_14;
  
  value3 = arg3 + arg1;
  value4 = arg2 + arg4;
  local_18 = arg6;
  local_14 = arg7;
  value2 = *(int *)(arg5 + 4);
  if (arg6 < value2) {
    arg1 = (value2 - arg6) + arg1;
    local_18 = value2;
  }
  value2 = *(int *)(arg5 + 0xc);
  if (arg7 < value2) {
    arg2 = (value2 - arg7) + arg2;
    local_14 = value2;
  }
  if (*(int *)(arg5 + 8) < arg3 + arg6) {
    value3 = value3 + (*(int *)(arg5 + 8) - (arg3 + arg6));
  }
  if (*(int *)(arg5 + 0x10) < arg4 + arg7) {
    value4 = value4 + (*(int *)(arg5 + 0x10) - (arg4 + arg7));
  }
  if (arg1 < *(int *)((intptr_t)self + 4)) {
    local_18 = local_18 + (*(int *)((intptr_t)self + 4) - arg1);
    arg1 = *(int *)((intptr_t)self + 4);
  }
  if (arg2 < *(int *)((intptr_t)self + 0xc)) {
    local_14 = local_14 + (*(int *)((intptr_t)self + 0xc) - arg2);
    arg2 = *(int *)((intptr_t)self + 0xc);
  }
  if (*(int *)((intptr_t)self + 8) < value3) {
    value3 = *(int *)((intptr_t)self + 8);
  }
  if (*(int *)((intptr_t)self + 0x10) < value4) {
    value4 = *(int *)((intptr_t)self + 0x10);
  }
  uvalue1 = value3 - arg1;
  value4 = value4 - arg2;
  if ((0 < (intptr_t)uvalue1) && (0 < value4)) {
    value3 = *(int *)((intptr_t)self + 0x20) * 2;
    uptr9 = (uint64_t *)
             (*(int *)((intptr_t)self + 0x28) + (*(int *)((intptr_t)self + 0x20) * arg2 + arg1) * 2);
    value2 = *(int *)(arg5 + 0x20) * 2;
    uptr7 = (uint64_t *)
             (*(int *)(arg5 + 0x28) + (*(int *)(arg5 + 0x20) * local_14 + local_18) * 2);
    if (*(int *)(DAT_0057c5c8 + 0x74) != 0) {
      do {
        uvalue5 = uvalue1;
        uptr6 = uptr7;
        uptr10 = uptr9;
        do {
          uptr8 = uptr10;
          if ((uvalue5 & 3) == 0) break;
          uptr8 = (uint64_t *)((intptr_t)uptr10 + 2);
          *(uint16_t *)uptr10 = *(uint16_t *)uptr6;
          uptr6 = (uint64_t *)((intptr_t)uptr6 + 2);
          uvalue5 = (uvalue5 & 3) - 1;
          uptr10 = uptr8;
        } while (uvalue5 != 0);
        for (uvalue5 = uvalue1 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
          *uptr8 = *uptr6;
          uptr6 = uptr6 + 1;
          uptr8 = uptr8 + 1;
        }
        uptr7 = (uint64_t *)((intptr_t)uptr7 + value2);
        uptr9 = (uint64_t *)((intptr_t)uptr9 + value3);
        value4 = value4 + -1;
        if (value4 == 0) {
          return;
        }
      } while( true );
    }
    do {
      uptr6 = uptr7;
      uptr10 = uptr9;
      if ((uvalue1 & 1) != 0) {
        uptr10 = (uint64_t *)((intptr_t)uptr9 + 2);
        *(uint16_t *)uptr9 = *(uint16_t *)uptr7;
        uptr6 = (uint64_t *)((intptr_t)uptr7 + 2);
      }
      for (uvalue5 = uvalue1 >> 1; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *(uint32_t *)uptr10 = *(uint32_t *)uptr6;
        uptr6 = (uint64_t *)((intptr_t)uptr6 + 4);
        uptr10 = (uint64_t *)((intptr_t)uptr10 + 4);
      }
      uptr7 = (uint64_t *)((intptr_t)uptr7 + value2);
      uptr9 = (uint64_t *)((intptr_t)uptr9 + value3);
      value4 = value4 + -1;
    } while (value4 != 0);
  }
  return;
}
