// State_Is1A1B1C: ported from Pizza Connection 2 at 0x509fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509fa0
#include "pc2_port.h"

uint32_t __fastcall State_Is1A1B1C(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x30);
  if (((value1 == 0x1a) || (value1 == 0x1b)) || (value1 == 0x1c)) {
    return 1;
  }
  return 0;
}
