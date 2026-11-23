// Matrix_Max4x9: ported from Pizza Connection 2 at 0x47a8e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a8e0
#include "pc2_port.h"

void __fastcall Matrix_Max4x9(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  
  value1 = 0;
  ptr2 = (int *)(arg1 + 0x13f4);
  value3 = 9;
  do {
    if (value1 < ptr2[-0x12]) {
      value1 = ptr2[-0x12];
    }
    if (value1 < *ptr2) {
      value1 = *ptr2;
    }
    if (value1 < ptr2[0x12]) {
      value1 = ptr2[0x12];
    }
    if (value1 < ptr2[0x24]) {
      value1 = ptr2[0x24];
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return;
}
