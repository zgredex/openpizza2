// Rating_GetInverse100: ported from Pizza Connection 2 at 0x4781b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4781b0
#include "pc2_port.h"

int __fastcall Rating_GetInverse100(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x19f4) * -3 + 100;
  if (value1 < 0) {
    value1 = 0;
  }
  return value1;
}
