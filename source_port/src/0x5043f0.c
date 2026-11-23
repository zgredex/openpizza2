// UI_DecrementTimer: ported from Pizza Connection 2 at 0x5043f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5043f0
#include "pc2_port.h"

void __thiscall UI_DecrementTimer(void *self,int arg1,char arg2)

{
  int value1;
  
  if (arg2 == '\0') {
    value1 = *(int *)((intptr_t)self + arg1 * 4 + 0x16c);
    if (0 < value1) {
      *(int *)((intptr_t)self + arg1 * 4 + 0x16c) = value1 + -1;
    }
  }
  else {
    value1 = *(int *)((intptr_t)self + arg1 * 4 + 0x88);
    if (0 < value1) {
      *(int *)((intptr_t)self + arg1 * 4 + 0x88) = value1 + -1;
      return;
    }
  }
  return;
}
