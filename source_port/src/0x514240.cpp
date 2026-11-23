// Array_CountNonZero20: ported from Pizza Connection 2 at 0x514240.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514240
#include "pc2_port.h"

int __fastcall Array_CountNonZero20(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  
  value1 = 0;
  ptr2 = (int *)(arg1 + 0x60);
  value3 = 0x14;
  do {
    if (*ptr2 != 0) {
      value1 = value1 + 1;
    }
    ptr2 = ptr2 + 3;
    value3 = value3 + -1;
  } while (value3 != 0);
  return value1;
}
