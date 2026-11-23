// CRT_Ios_Delete: ported from Pizza Connection 2 at 0x54d8bb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d8bb
#include "pc2_port.h"

uint32_t * __thiscall CRT_Ios_Delete(void *self,uint8_t arg1)

{
  CRT_Ios_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
