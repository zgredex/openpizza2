// Grid_CollectNearbyIds: ported from Pizza Connection 2 at 0x4f12e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f12e0
#include "pc2_port.h"

void __thiscall Grid_CollectNearbyIds(void *self,void *arg1,int arg2,int arg3,int arg4)

{
  uint32_t uvalue1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int local_4;
  
  value5 = 0;
  local_4 = 0;
  if (0 < *(int *)((intptr_t)self + 0xa4)) {
    value4 = 0;
    do {
      value2 = value4 + *(int *)((intptr_t)self + 0x9c);
      if (((value2 != arg2) &&
          (uvalue1 = *(int *)(value2 + 0xc) - *(int *)(arg2 + 0xc), uvalue3 = (intptr_t)uvalue1 >> 0x1f,
          -1 < (intptr_t)(arg4 - ((uvalue1 ^ uvalue3) - uvalue3)))) &&
         (uvalue1 = *(int *)(value2 + 0x10) - *(int *)(arg2 + 0x10), uvalue3 = (intptr_t)uvalue1 >> 0x1f,
         -1 < (intptr_t)(arg4 - ((uvalue1 ^ uvalue3) - uvalue3)))) {
        List_Add(arg1,(uint32_t)*(uint16_t *)(value2 + 4));
        local_4 = local_4 + 1;
        if (arg3 <= local_4) {
          return;
        }
      }
      value5 = value5 + 1;
      value4 = value4 + 0x28;
    } while (value5 < *(int *)((intptr_t)self + 0xa4));
  }
  return;
}
