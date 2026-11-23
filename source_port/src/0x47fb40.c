// Branch_EndConstructionMode: ported from Pizza Connection 2 at 0x47fb40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fb40
#include "pc2_port.h"

void __fastcall Branch_EndConstructionMode(int arg1)

{
  if (*(int *)((intptr_t)DAT_0057c670 + 0x2fc) == *(int *)(arg1 + 0x14e0)) {
    Game_LoadBackgroundImage(DAT_0057c670,(char *)0x0);
  }
  *(uint8_t *)(arg1 + 0x16f5) = 0;
  return;
}
