// Window_UnlockState: ported from Pizza Connection 2 at 0x486e00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486e00
#include "pc2_port.h"

void __fastcall Window_UnlockState(int arg1)

{
  *(uint32_t *)(arg1 + 600) = 0;
  CS_Leave(*(int *)(arg1 + 0x23c));
  return;
}
