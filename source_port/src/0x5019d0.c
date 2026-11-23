// Player_Event_StreamConstruct: ported from Pizza Connection 2 at 0x5019d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5019d0
#include "pc2_port.h"

uint32_t * __thiscall Player_Event_StreamConstruct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_AwardNode_Delete_0055c660;
  if (arg1 == (void *)0x0) {
    *(uint16_t *)((intptr_t)self + 8) = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
    return self;
  }
  Player_Event_Load(self,arg1);
  return self;
}
