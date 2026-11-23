// List_ContainerDestroy: ported from Pizza Connection 2 at 0x545b00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545b00
#include "pc2_port.h"

uint32_t * __thiscall List_ContainerDestroy(void *self,uint8_t arg1)

{
  List_ContainerDestruct(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
