// Sound_ApplyVolumesForPlaybackMode: ported from Pizza Connection 2 at 0x547ba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547ba0
#include "pc2_port.h"

void __thiscall Sound_ApplyVolumesForPlaybackMode(void *self,int arg1)

{
  int value1;
  bool flag2;
  
  flag2 = Sound_SetVolumeSetting(self,*(int *)((intptr_t)self + 0x104),arg1);
  if (!flag2) {
    return;
  }
  if (*(char *)((intptr_t)self + 0xfc) == '\0') {
    return;
  }
  value1 = *(int *)((intptr_t)self + 0x104);
  if (value1 == 1) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x7c))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x80),
               *(uint32_t *)((intptr_t)self + 0x1d0));
    if (*(int *)((intptr_t)self + 0xc) != 0) {
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x80))
                (*(int **)((intptr_t)self + 8),*(int *)((intptr_t)self + 0xc),
                 *(uint32_t *)((intptr_t)self + 0x1d4));
    }
    value1 = *(int *)((intptr_t)self + 0x20);
  }
  else {
    if (value1 == 2) {
      if (*(int *)((intptr_t)self + 0xc) == 0) {
        return;
      }
      (**(code **)(**(int **)((intptr_t)self + 8) + 0x80))
                (*(int **)((intptr_t)self + 8),*(int *)((intptr_t)self + 0xc),
                 *(uint32_t *)((intptr_t)self + 0x1d4));
      return;
    }
    if (value1 != 3) {
      return;
    }
    value1 = *(int *)((intptr_t)self + 0x20);
  }
  if (value1 != 0) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x80))
              (*(int **)((intptr_t)self + 8),value1,*(uint32_t *)((intptr_t)self + 0x1d8));
  }
  return;
}
