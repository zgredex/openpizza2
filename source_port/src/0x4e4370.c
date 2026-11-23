// BuildingValue_StreamConstruct: ported from Pizza Connection 2 at 0x4e4370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4370
#include "pc2_port.h"

uint32_t * __thiscall BuildingValue_StreamConstruct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_BuildingValue_Delete_0055c5a4;
  BuildingValue_Load(self,arg1);
  return self;
}
