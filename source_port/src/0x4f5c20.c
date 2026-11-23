// UI_GetViewRect: ported from Pizza Connection 2 at 0x4f5c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5c20
#include "pc2_port.h"

void __thiscall UI_GetViewRect(void *self,int *arg1)

{
  *arg1 = *(int *)((intptr_t)self + 0x1016c) + *(int *)((intptr_t)self + 0x2c);
  arg1[2] = *(int *)((intptr_t)self + 0x10160) - *(int *)((intptr_t)self + 0x10168);
  arg1[1] = *(int *)((intptr_t)self + 0x30) - *(int *)((intptr_t)self + 0x10174);
  arg1[3] = *(int *)((intptr_t)self + 0x10170) + *(int *)((intptr_t)self + 0x10164);
  return;
}
