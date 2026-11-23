// Object_SetChildShort8: ported from Pizza Connection 2 at 0x5078b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5078b0
#include "pc2_port.h"

void __thiscall Object_SetChildShort8(void *self,int arg1)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 200);
  if ((value1 != 0) && (*(short *)(value1 + 8) != arg1)) {
    *(short *)(value1 + 8) = (short)arg1;
  }
  return;
}
