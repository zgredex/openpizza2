// CRT_Filebuf_Overflow: ported from Pizza Connection 2 at 0x54ce81.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ce81
#include "pc2_port.h"

uint32_t __thiscall CRT_Filebuf_Overflow(void *self,uint32_t arg1)

{
  int value1;
  
  value1 = Stream_GetStatus(self);
  if ((value1 == -1) || (value1 = CRT_Filebuf_Sync((intptr_t)self), value1 == -1)) {
    return 0xffffffff;
  }
  if (*(int *)((intptr_t)self + 8) == 0) {
    *(uint32_t *)((intptr_t)self + 0x18) = *(uint32_t *)((intptr_t)self + 0x10);
    *(uint32_t *)((intptr_t)self + 0x1c) = *(uint32_t *)((intptr_t)self + 0x10);
    *(uint32_t *)((intptr_t)self + 0x20) = *(uint32_t *)((intptr_t)self + 0x14);
  }
  if (arg1 != 0xffffffff) {
    if ((*(int *)((intptr_t)self + 8) == 0) &&
       (*(uint32_t *)((intptr_t)self + 0x1c) < *(uint32_t *)((intptr_t)self + 0x20))) {
      Stream_PutByte(self,arg1);
    }
    else {
      value1 = CRT_Write(*(uint32_t *)((intptr_t)self + 0x4c),(char *)&arg1,1);
      if (value1 != 1) {
        return 0xffffffff;
      }
    }
  }
  return 1;
}
