// Stream_AttachBuffer: ported from Pizza Connection 2 at 0x54dcd4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dcd4
#include "pc2_port.h"

void __thiscall
Stream_AttachBuffer(void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3)

{
  if ((*(int *)((intptr_t)self + 4) != 0) && (*(LPVOID *)((intptr_t)self + 0x10) != (LPVOID)0x0)) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x10));
  }
  *(uint32_t *)((intptr_t)self + 0x10) = arg1;
  *(uint32_t *)((intptr_t)self + 4) = arg3;
  *(uint32_t *)((intptr_t)self + 0x14) = arg2;
  return;
}
