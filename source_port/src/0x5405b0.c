// Sound_AllocVoice: ported from Pizza Connection 2 at 0x5405b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5405b0
#include "pc2_port.h"

int __fastcall Sound_AllocVoice(int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = (int *)(arg1 + 0x268);
  do {
    if (*ptr2 == 0) {
      value1 = arg1 + value1 * 0x24;
      *(uint32_t *)(value1 + 0x268) = 1;
      return value1 + 0x254;
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 9;
  } while (value1 < 0x14);
  return 0;
}
