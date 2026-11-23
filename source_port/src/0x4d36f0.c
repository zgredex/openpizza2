// Character_StreamConstruct: ported from Pizza Connection 2 at 0x4d36f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d36f0
#include "pc2_port.h"

uint32_t * __thiscall Character_StreamConstruct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_Character_Delete_0055c4fc;
  Character_Load(self,arg1);
  return self;
}
