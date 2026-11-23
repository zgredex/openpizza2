// Player_MissionState_Construct: ported from Pizza Connection 2 at 0x4f5df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5df0
#include "pc2_port.h"

uint32_t * __thiscall Player_MissionState_Construct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_Player_MissionState_Delete_0055c5e8;
  if (arg1 == (void *)0x0) {
    Game_InitDateState(self);
    return self;
  }
  Player_MissionState_Load(self,arg1);
  return self;
}
