// Stats_Increment2D: ported from Pizza Connection 2 at 0x47db10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47db10
#include "pc2_port.h"

void __thiscall Stats_Increment2D(void *self,int arg1,int arg2)

{
  int *ptr1;
  
  ptr1 = (int *)((intptr_t)self + (arg2 + 0x626 + arg1 * 2) * 4);
  *ptr1 = *ptr1 + 1;
  return;
}
