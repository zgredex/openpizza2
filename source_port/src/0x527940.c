// UI_SetWindowProc: ported from Pizza Connection 2 at 0x527940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527940
#include "pc2_port.h"

void __thiscall UI_SetWindowProc(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x8304) = arg1;
  return;
}
