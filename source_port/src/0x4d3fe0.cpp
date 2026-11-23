// Rating_AdjustB: ported from Pizza Connection 2 at 0x4d3fe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3fe0
#include "pc2_port.h"

int __fastcall Rating_AdjustB(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x10);
  if (0x32 < *(int *)(arg1 + 0x38)) {
    value1 = value1 + (0x32 - *(int *)(arg1 + 0x38)) * 2;
  }
  if (value1 < 0) {
    value1 = 0;
  }
  return value1;
}
