// Counter_IncrementShortBA: ported from Pizza Connection 2 at 0x4f0e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0e20
#include "pc2_port.h"

uint16_t __fastcall Counter_IncrementShortBA(int arg1)

{
  *(short *)(arg1 + 0xba) = *(short *)(arg1 + 0xba) + 1;
  return *(uint16_t *)(arg1 + 0xba);
}
