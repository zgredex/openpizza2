// Matrix_MaxByRow9x8: ported from Pizza Connection 2 at 0x47a590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a590
#include "pc2_port.h"

void __thiscall Matrix_MaxByRow9x8(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int *ptr3;
  int value4;
  int value5;
  
  value1 = 0;
  value5 = 0;
  ptr3 = (int *)((intptr_t)self + 0x188);
  do {
    if ((arg1 == value5) || (arg1 == -1)) {
      value4 = 8;
      ptr2 = ptr3;
      do {
        if (value1 < *ptr2) {
          value1 = *ptr2;
        }
        ptr2 = ptr2 + 9;
        value4 = value4 + -1;
      } while (value4 != 0);
    }
    value5 = value5 + 1;
    ptr3 = ptr3 + 1;
  } while (value5 < 9);
  return;
}
