// ResourceHandle_Alloc: ported from Pizza Connection 2 at 0x402260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402260
#include "pc2_port.h"

int __fastcall ResourceHandle_Alloc(int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = (int *)(arg1 + 0x16f4);
  do {
    if (*ptr2 == 0) {
      value1 = arg1 + value1 * 0x24;
      *(uint32_t *)(value1 + 0x16f4) = 1;
      return value1 + 0x16e0;
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 9;
  } while (value1 < 0x14);
  return 0;
}
