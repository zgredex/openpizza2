// Sprite_GetSize: ported from Pizza Connection 2 at 0x53d090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d090
#include "pc2_port.h"

void __thiscall Sprite_GetSize(void *self,int *arg1,int *arg2)

{
  int value1;
  
  if (*(int *)((intptr_t)self + 0x30) == 0) {
    value1 = (intptr_t)*(short *)((intptr_t)self + 6);
    if (0xe < *(uint8_t *)((intptr_t)self + 5)) {
      value1 = value1 >> 1;
    }
    *arg1 = value1;
    *arg2 = (intptr_t)*(short *)((intptr_t)self + 8);
    return;
  }
  if (*(char *)((intptr_t)self + 0x37) == '\0') {
    value1 = (intptr_t)*(short *)((intptr_t)self + 6);
    if (0xe < *(uint8_t *)((intptr_t)self + 5)) {
      value1 = value1 >> 1;
    }
    *arg1 = value1;
    *arg2 = (intptr_t)*(short *)((intptr_t)self + 8);
    return;
  }
  value1 = (intptr_t)*(short *)((intptr_t)self + 6);
  if (0xe < *(uint8_t *)((intptr_t)self + 5)) {
    value1 = value1 >> 1;
  }
  *arg2 = value1;
  *arg1 = (intptr_t)*(short *)((intptr_t)self + 8);
  return;
}
