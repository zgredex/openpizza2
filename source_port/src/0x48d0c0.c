// Game_RemoveScreenTimers: ported from Pizza Connection 2 at 0x48d0c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d0c0
#include "pc2_port.h"

void __fastcall Game_RemoveScreenTimers(int arg1)

{
  if (*(int *)(arg1 + 0x2d8c) != -1) {
    Timer_RemoveById((void *)(arg1 + 0x2d1c),*(int *)(arg1 + 0x2d8c));
  }
  *(uint32_t *)(arg1 + 0x2d8c) = 0xffffffff;
  if (*(int *)(arg1 + 0x2da4) != -1) {
    Timer_RemoveById((void *)(arg1 + 0x2d1c),*(int *)(arg1 + 0x2da4));
  }
  *(uint32_t *)(arg1 + 0x2da4) = 0xffffffff;
  return;
}
