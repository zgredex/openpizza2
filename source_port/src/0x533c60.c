// Record_ClearActive48: ported from Pizza Connection 2 at 0x533c60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533c60
#include "pc2_port.h"

void __thiscall Record_ClearActive48(void *self,int arg1)

{
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3c + arg1 * 0x48) = 0;
    *(uint16_t *)(*(int *)((intptr_t)self + 0x4c) + 0x30 + arg1 * 0x48) = 0;
  }
  return;
}
