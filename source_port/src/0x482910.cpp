// Game_GetActiveScreenOrFallback: ported from Pizza Connection 2 at 0x482910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482910
#include "pc2_port.h"

int __fastcall Game_GetActiveScreenOrFallback(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x270);
  if (value1 == 0) {
    value1 = *(int *)(arg1 + 0x264);
  }
  return value1;
}
