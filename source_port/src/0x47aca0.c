// Rating_ComputePenalty: ported from Pizza Connection 2 at 0x47aca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47aca0
#include "pc2_port.h"

int __fastcall Rating_ComputePenalty(int arg1)

{
  int value1;
  
  if (*(int *)(arg1 + 0x14c4) == 0) {
    return 0;
  }
  value1 = Rating_ClampAdjusted(*(int *)(arg1 + 0x14c4));
  value1 = value1 / 10;
  if (value1 < 1) {
    value1 = 1;
  }
  return -(*(int *)(arg1 + 0x14d4) / value1);
}
