// UI_Group_DestroyMemberList: ported from Pizza Connection 2 at 0x532510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532510
#include "pc2_port.h"

void __fastcall UI_Group_DestroyMemberList(int arg1)

{
  Array_Destroy((uint32_t *)(arg1 + 4));
  return;
}
