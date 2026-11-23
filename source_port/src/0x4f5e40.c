// Player_MissionState_Destructor: ported from Pizza Connection 2 at 0x4f5e40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5e40
#include "pc2_port.h"

void __fastcall Player_MissionState_Destructor(uint32_t *arg1)

{
                    /* Destructor body for the player mission-state object. */
  *arg1 = &PTR_Player_MissionState_Delete_0055c5e8;
  return;
}
