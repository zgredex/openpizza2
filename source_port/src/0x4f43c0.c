// List_AppendQuad: ported from Pizza Connection 2 at 0x4f43c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f43c0
#include "pc2_port.h"

void __thiscall List_AppendQuad(void *self,uint32_t *arg1)

{
  uint32_t *uptr1;
  
  uptr1 = operator_new(0x10);
  *uptr1 = *arg1;
  uptr1[1] = arg1[1];
  uptr1[2] = arg1[2];
  uptr1[3] = arg1[3];
  List_Add((void *)((intptr_t)self + 0x140),uptr1);
  return;
}
