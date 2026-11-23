// AI_AddKnownRecord: ported from Pizza Connection 2 at 0x4d8610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8610
#include "pc2_port.h"

void __thiscall AI_AddKnownRecord(void *self,uint32_t arg1)

{
  uint32_t *uptr1;
  
  uptr1 = operator_new(8);
  if (uptr1 == (uint32_t *)0x0) {
    List_Add((void *)((intptr_t)self + 0xfc8),0);
    return;
  }
  *uptr1 = arg1;
  uptr1[1] = 0xffffffff;
  List_Add((void *)((intptr_t)self + 0xfc8),uptr1);
  return;
}
