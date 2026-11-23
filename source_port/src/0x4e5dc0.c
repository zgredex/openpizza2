// ConstructionOrder_StreamConstruct: ported from Pizza Connection 2 at 0x4e5dc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e5dc0
#include "pc2_port.h"

uint32_t * __thiscall ConstructionOrder_StreamConstruct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_ConstructionOrder_Delete_0055c5bc;
  ConstructionOrder_Load(self,arg1);
  return self;
}
