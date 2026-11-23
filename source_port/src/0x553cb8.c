// CRT_StrToDouble: ported from Pizza Connection 2 at 0x553cb8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553cb8
#include "pc2_port.h"

void __thiscall CRT_StrToDouble(void *self,uint32_t *arg1,uint8_t *arg2)

{
  uint32_t uvalue1;
  int value2;
  uint32_t uvalue3;
  uint16_t local_1c [6];
  uint32_t local_10;
  uint32_t uStack_c;
  int local_8;
  
                    /* Parses a floating-point literal and returns status, length, and value. */
  uvalue3 = 0;
  uvalue1 = FUN_0055606a(self,local_1c,&local_8,arg2,0,0,0,0);
  if ((uvalue1 & 4) == 0) {
    value2 = FUN_00555ad1(local_1c,&local_10);
    if (((uvalue1 & 2) != 0) || (value2 == 1)) {
      uvalue3 = 0x80;
    }
    if (((uvalue1 & 1) != 0) || (value2 == 2)) {
      uvalue3 = uvalue3 | 0x100;
    }
  }
  else {
    uvalue3 = 0x200;
    local_10 = 0;
    uStack_c = 0;
  }
  *arg1 = uvalue3;
  *(uint64_t *)(arg1 + 4) = CONCAT44(uStack_c,local_10);
  arg1[1] = local_8 - (intptr_t)arg2;
  return;
}
