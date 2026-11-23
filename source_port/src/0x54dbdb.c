// CRT_FRead: ported from Pizza Connection 2 at 0x54dbdb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dbdb
#include "pc2_port.h"

int __thiscall CRT_FRead(void *self,uint32_t *arg1,uint32_t arg2)

{
  uint32_t uvalue1;
  int value2;
  uint32_t uvalue3;
  int local_8;
  
  local_8 = 0;
  if (*(int *)((intptr_t)self + 8) == 0) {
    while (arg2 != 0) {
      value2 = (**(code **)(*(int *)self + 0x20))();
      if (value2 == -1) {
        return local_8;
      }
      uvalue3 = *(int *)((intptr_t)self + 0x2c) - (intptr_t)*(uint32_t **)((intptr_t)self + 0x28);
      if ((intptr_t)arg2 <= (intptr_t)uvalue3) {
        uvalue3 = arg2;
      }
      if (0 < (intptr_t)uvalue3) {
        _memmove_2(arg1,*(uint32_t **)((intptr_t)self + 0x28),uvalue3);
        arg1 = (uint32_t *)((intptr_t)arg1 + uvalue3);
        *(int *)((intptr_t)self + 0x28) = *(int *)((intptr_t)self + 0x28) + uvalue3;
        local_8 = local_8 + uvalue3;
        arg2 = arg2 - uvalue3;
      }
    }
  }
  else {
    if (*(int *)((intptr_t)self + 0xc) == -1) {
      uvalue1 = (**(code **)(*(int *)self + 0x20))();
      *(uint32_t *)((intptr_t)self + 0xc) = uvalue1;
    }
    if (arg2 != 0) {
      do {
        arg2 = arg2 - 1;
        if (*(int *)((intptr_t)self + 0xc) == -1) {
          return local_8;
        }
        *(uint8_t *)arg1 = *(uint8_t *)((intptr_t)self + 0xc);
        arg1 = (uint32_t *)((intptr_t)arg1 + 1);
        local_8 = local_8 + 1;
        uvalue1 = (**(code **)(*(int *)self + 0x20))();
        *(uint32_t *)((intptr_t)self + 0xc) = uvalue1;
      } while (arg2 != 0);
    }
  }
  return local_8;
}
