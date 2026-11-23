// UI_SetChildScale: ported from Pizza Connection 2 at 0x509130.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509130
#include "pc2_port.h"

void __thiscall UI_SetChildScale(void *self,double arg1)

{
  int *ptr1;
  
  ptr1 = *(int **)((intptr_t)self + 200);
  if ((ptr1 != (int *)0x0) && (ptr1[0x16] != 0)) {
    UI_SetListEntryPosition(ptr1[0x16],*ptr1,arg1 * 0.01 + 0.6);
  }
  return;
}
