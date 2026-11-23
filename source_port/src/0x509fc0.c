// Building_IsSpecialType: ported from Pizza Connection 2 at 0x509fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509fc0
#include "pc2_port.h"

uint32_t __fastcall Building_IsSpecialType(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x30);
  if ((((value1 == 4) || (value1 == 5)) || (value1 == 0xb)) || ((value1 == 0x21 || (value1 == 0xf)))) {
    return 1;
  }
  return 0;
}
