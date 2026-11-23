// Player_AIState_Destroy: ported from Pizza Connection 2 at 0x501b70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501b70
#include "pc2_port.h"

void __fastcall Player_AIState_Destroy(uint32_t *arg1)

{
  *arg1 = &PTR_Player_AIState_Delete_0055c664;
  List_Node_Destroy(arg1 + 0x1a);
  return;
}
