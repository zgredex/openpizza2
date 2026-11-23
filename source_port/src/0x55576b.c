// FUN_0055576b: ported from Pizza Connection 2 at 0x55576b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55576b
#include "pc2_port.h"

uint32_t __cdecl FUN_0055576b(int arg1,int arg2)

{
  int *ptr1;
  int value2;
  
  if ((*(uint32_t *)(arg1 + (arg2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(arg2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  value2 = arg2 / 0x20 + 1;
  if (value2 < 3) {
    ptr1 = (int *)(arg1 + value2 * 4);
    do {
      if (*ptr1 != 0) {
        return 0;
      }
      value2 = value2 + 1;
      ptr1 = ptr1 + 1;
    } while (value2 < 3);
  }
  return 1;
}
