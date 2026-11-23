// Enum_MapDirection: ported from Pizza Connection 2 at 0x4f1d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1d90
#include "pc2_port.h"

uint32_t Enum_MapDirection(int arg1)

{
  switch(*(uint32_t *)(arg1 + 0xc) & 7) {
  default:
    return 0;
  case 1:
    return 4;
  case 2:
    return 1;
  case 3:
    return 5;
  case 4:
    return 2;
  case 5:
    return 6;
  case 6:
    return 3;
  case 7:
    return 7;
  }
}
