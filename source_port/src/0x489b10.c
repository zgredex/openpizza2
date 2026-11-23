// Game_GetDateField0C: ported from Pizza Connection 2 at 0x489b10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489b10
#include "pc2_port.h"

uint32_t __fastcall Game_GetDateField0C(int arg1)

{
  return *(uint32_t *)(*(int *)(arg1 + 0x94) + 0xc);
}
