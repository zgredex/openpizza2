// UI_RemoveListEntryAt: ported from Pizza Connection 2 at 0x500fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500fd0
#include "pc2_port.h"

void __thiscall UI_RemoveListEntryAt(void *self,int arg1,int arg2)

{
  int value1;
  
  if ((-1 < arg2) && (arg2 < 10)) {
    if (arg2 < 9) {
      value1 = arg2 * 0x10 + arg1 * 0x168;
      _memmove((uint32_t *)((intptr_t)self + value1 + 0x74),(uint32_t *)((intptr_t)self + value1 + 0x84),
               arg2 * -0x10 + 0x90);
    }
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x110) = 0;
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x104) = 0xffffffff;
  }
  return;
}
