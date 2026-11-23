// Matrix_Max100x8: ported from Pizza Connection 2 at 0x47a4a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a4a0
#include "pc2_port.h"

void __fastcall Matrix_Max100x8(int arg1)

{
  uint16_t uvalue1;
  int value2;
  uint32_t uvalue3;
  int *ptr4;
  int value5;
  int *ptr6;
  
  value2 = 0;
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uvalue3 = (uint32_t)uvalue1;
  if (100 < uvalue1) {
    uvalue3 = 100;
  }
  if (uvalue3 != 0) {
    ptr6 = (int *)(arg1 + 0x554);
    do {
      value5 = 8;
      ptr4 = ptr6;
      do {
        if (value2 < *ptr4) {
          value2 = *ptr4;
        }
        ptr4 = ptr4 + 100;
        value5 = value5 + -1;
      } while (value5 != 0);
      ptr6 = ptr6 + 1;
      uvalue3 = uvalue3 - 1;
    } while (uvalue3 != 0);
  }
  return;
}
