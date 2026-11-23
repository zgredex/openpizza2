// Palette_FindIndex: ported from Pizza Connection 2 at 0x535cb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535cb0
#include "pc2_port.h"

int __thiscall Palette_FindIndex(void *self,uint32_t *arg1)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  int *ptr4;
  int *ptr5;
  bool flag6;
  
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 8)) {
    uptr3 = *(uint32_t **)self;
    do {
      value2 = 0xc0;
      flag6 = true;
      ptr4 = (int *)*arg1;
      ptr5 = *(int **)*uptr3;
      do {
        if (value2 == 0) break;
        value2 = value2 + -1;
        flag6 = *ptr4 == *ptr5;
        ptr4 = ptr4 + 1;
        ptr5 = ptr5 + 1;
      } while (flag6);
      if (flag6) {
        return value1;
      }
      value1 = value1 + 1;
      uptr3 = uptr3 + 1;
    } while (value1 < *(int *)((intptr_t)self + 8));
  }
  return -1;
}
