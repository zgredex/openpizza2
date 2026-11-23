// GameClock_Reset: ported from Pizza Connection 2 at 0x4dd4a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd4a0
#include "pc2_port.h"

void __fastcall GameClock_Reset(int arg1)

{
  *(uint32_t *)(arg1 + 0x10) = 0;
  *(uint8_t *)(arg1 + 6) = 0;
  *(uint8_t *)(arg1 + 7) = 0;
  *(uint8_t *)(arg1 + 8) = 0;
  *(uint8_t *)(arg1 + 0x18) = 0;
  *(uint16_t *)(arg1 + 4) = (uint16_t)DAT_0057dfbc;
  *(uint16_t *)(arg1 + 10) = 0;
  *(uint32_t *)(arg1 + 0x10) = 0;
  *(uint32_t *)(arg1 + 0xc) = 0;
  *(uint8_t *)(arg1 + 0x19) = 0;
  return;
}
