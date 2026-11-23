// Sound_ApplyVolumePreset: ported from Pizza Connection 2 at 0x548570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548570
#include "pc2_port.h"

void __thiscall Sound_ApplyVolumePreset(void *self,int arg1)

{
  int *ptr1;
  int value2;
  int64_t lvalue3;
  
  if (arg1 == 0) {
    if (*(float *)((intptr_t)self + 0x170) == 1.0) {
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x170) = 0x3f800000;
  }
  else if (arg1 == 1) {
    if (*(float *)((intptr_t)self + 0x170) == 0.7) {
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x170) = 0x3f000000;
  }
  else {
    if (arg1 != 2) {
      return;
    }
    if (*(float *)((intptr_t)self + 0x170) == 0.4) {
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x170) = 0x3e99999a;
  }
  if (((*(char *)((intptr_t)self + 0x169) != '\0') && (*(char *)((intptr_t)self + 0xfc) != '\0')) &&
     (*(int *)((intptr_t)self + 0x1d0) != 0)) {
    lvalue3 = __ftol();
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x7c))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x84),(intptr_t)lvalue3);
    ptr1 = *(int **)((intptr_t)self + 8);
    value2 = *ptr1;
    lvalue3 = __ftol();
    (**(code **)(value2 + 0xa4))(ptr1,*(uint32_t *)((intptr_t)self + 0xf8),(intptr_t)lvalue3);
  }
  return;
}
