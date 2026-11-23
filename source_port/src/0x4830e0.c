// Game_DestroyEventWindow: ported from Pizza Connection 2 at 0x4830e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4830e0
#include "pc2_port.h"

void __fastcall Game_DestroyEventWindow(int arg1)

{
  uint32_t *uptr1;
  
  uptr1 = *(uint32_t **)(arg1 + 0x26c);
  if (uptr1 != (uint32_t *)0x0) {
    *(uint32_t *)(arg1 + 0x26c) = 0;
    Window_DestroyChild(DAT_0057c5e0,uptr1);
  }
  return;
}
