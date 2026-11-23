// Record_Clear48: ported from Pizza Connection 2 at 0x533a50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533a50
#include "pc2_port.h"

void __thiscall Record_Clear48(void *self,int arg1)

{
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    *(uint32_t *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48) = 0xffffffff;
  }
  return;
}
