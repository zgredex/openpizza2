// GamePlan_StreamConstruct: ported from Pizza Connection 2 at 0x50f690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f690
#include "pc2_port.h"

uint32_t * __thiscall GamePlan_StreamConstruct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_GamePlan_Delete_0055c688;
  GamePlan_LoadRecord(self,arg1);
  return self;
}
