// Stats_SumPlayerGrid: ported from Pizza Connection 2 at 0x47a430.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a430
#include "pc2_port.h"

int __thiscall Stats_SumPlayerGrid(void *self,int arg1,int arg2)

{
  uint16_t uvalue1;
  int value2;
  int value3;
  int *ptr4;
  int *ptr5;
  uint32_t uvalue6;
  int value7;
  
  value2 = 0;
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uvalue6 = (uint32_t)uvalue1;
  if (100 < uvalue1) {
    uvalue6 = 100;
  }
  value7 = 0;
  if (uvalue6 != 0) {
    ptr5 = (int *)((intptr_t)self + 0x554);
    do {
      if ((value7 == arg2) || (arg2 == -1)) {
        value3 = 0;
        ptr4 = ptr5;
        do {
          if ((arg1 == value3) || (arg1 == -1)) {
            value2 = value2 + *ptr4;
          }
          value3 = value3 + 1;
          ptr4 = ptr4 + 100;
        } while (value3 < 8);
      }
      value7 = value7 + 1;
      ptr5 = ptr5 + 1;
    } while (value7 < (intptr_t)uvalue6);
  }
  return value2;
}
