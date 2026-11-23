// Game_ResetStats: ported from Pizza Connection 2 at 0x50fdf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fdf0
#include "pc2_port.h"

void __fastcall Game_ResetStats(int arg1)

{
  uint32_t *uptr1;
  int value2;
  
  *(uint32_t *)(arg1 + 0x240) = 1;
  *(uint32_t *)(arg1 + 0x244) = 0;
  *(uint32_t *)(arg1 + 0x248) = 0;
  *(uint32_t *)(arg1 + 0x24c) = 0;
  *(uint32_t *)(arg1 + 0x250) = 0;
  *(uint32_t *)(arg1 + 0x254) = 0;
  *(uint32_t *)(arg1 + 600) = 0;
  *(uint32_t *)(arg1 + 0x25c) = 0;
  *(uint32_t *)(arg1 + 0x260) = 0;
  uptr1 = (uint32_t *)(arg1 + 0x284);
  value2 = 8;
  do {
    uptr1[-8] = 0;
    *uptr1 = 0;
    uptr1[8] = 0;
    uptr1[0x10] = 0;
    uptr1 = uptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
