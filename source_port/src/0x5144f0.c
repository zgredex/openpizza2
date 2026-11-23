// Storage_GetFillPercent: ported from Pizza Connection 2 at 0x5144f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5144f0
#include "pc2_port.h"

int __fastcall Storage_GetFillPercent(int arg1)

{
  int value1;
  int value2;
  
  value1 = *(int *)(arg1 + 0x58);
  value2 = Storage_GetCapacity(arg1);
  return (value1 * 100) / value2;
}
