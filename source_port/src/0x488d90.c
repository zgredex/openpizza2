// Game_GetTimeSegment: ported from Pizza Connection 2 at 0x488d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488d90
#include "pc2_port.h"

uint32_t __fastcall Game_GetTimeSegment(int arg1)

{
  return *(uint8_t *)(*(int *)(arg1 + 0x94) + 7) / 3;
}
