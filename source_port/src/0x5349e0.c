// RecordList_ReadSlot98: ported from Pizza Connection 2 at 0x5349e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5349e0
#include "pc2_port.h"

void __thiscall RecordList_ReadSlot98(void *self,int arg1,int arg2,uint32_t *arg3)

{
  uint32_t *uptr1;
  
  if ((arg1 < 0) || (*(int *)((intptr_t)self + 100) <= arg1)) {
    *arg3 = 0;
    *(uint16_t *)(arg3 + 1) = 0;
  }
  else if ((-1 < arg2) && (arg2 < 0x10)) {
    uptr1 = (uint32_t *)(*(int *)((intptr_t)self + 0x50) + arg1 * 0x98 + arg2 * 6);
    *arg3 = *uptr1;
    *(uint16_t *)(arg3 + 1) = *(uint16_t *)(uptr1 + 1);
    return;
  }
  return;
}
