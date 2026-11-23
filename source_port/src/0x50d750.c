// State_IsMenuState: ported from Pizza Connection 2 at 0x50d750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d750
#include "pc2_port.h"

uint32_t __fastcall State_IsMenuState(int arg1)

{
  switch(*(uint32_t *)(arg1 + 0x30)) {
  case 0xd:
  case 0x17:
  case 0x1d:
  case 0x1e:
    return 1;
  default:
    return 0;
  }
}
