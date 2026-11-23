// CRT_TypeInfo_Delete: ported from Pizza Connection 2 at 0x54fe4e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fe4e
#include "pc2_port.h"

uint32_t * __thiscall CRT_TypeInfo_Delete(void *self,uint8_t arg1)

{
  CRT_TypeInfoDtor(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
