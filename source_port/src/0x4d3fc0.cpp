// Rating_AdjustA: ported from Pizza Connection 2 at 0x4d3fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3fc0
#include "pc2_port.h"

int __fastcall Rating_AdjustA(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 8);
  if (0x37 < *(int *)(arg1 + 0x38)) {
    value1 = value1 + (0x37 - *(int *)(arg1 + 0x38)) * 3;
  }
  if (value1 < 0) {
    value1 = 0;
  }
  return value1;
}
