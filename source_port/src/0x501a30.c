// AwardNode_Destructor: ported from Pizza Connection 2 at 0x501a30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501a30
#include "pc2_port.h"

void __fastcall AwardNode_Destructor(uint32_t *arg1)

{
                    /* Destructor body for a player award/rank node. */
  *arg1 = &PTR_AwardNode_Delete_0055c660;
  return;
}
