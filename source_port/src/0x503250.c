// UI_AppendCommandIfActive: ported from Pizza Connection 2 at 0x503250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x503250
#include "pc2_port.h"

void __thiscall UI_AppendCommandIfActive(void *self,int arg1,int arg2)

{
  if ((*(char *)((intptr_t)self + 0x60) != '\0') && (arg1 == *(int *)((intptr_t)self + 0x48))) {
    *(int *)((intptr_t)self + 8) = arg1;
    if (arg2 != -1) {
      List_Add((void *)((intptr_t)self + 0x68),arg2);
    }
  }
  return;
}
