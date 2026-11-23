// Rating_ClampAdjusted: ported from Pizza Connection 2 at 0x4d3f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3f90
#include "pc2_port.h"

int __fastcall Rating_ClampAdjusted(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x38);
  if (value1 < 0x33) {
    value1 = *(int *)(arg1 + 4) + -0x19 + value1;
  }
  else {
    value1 = (0x37 - value1) * 5 + *(int *)(arg1 + 4);
  }
  if (value1 < 0) {
    return 0;
  }
  if (100 < value1) {
    value1 = 100;
  }
  return value1;
}
