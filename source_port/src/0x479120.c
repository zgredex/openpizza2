// Company_ComputeTypePercentages: ported from Pizza Connection 2 at 0x479120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479120
#include "pc2_port.h"

void __fastcall Company_ComputeTypePercentages(int arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t *uptr4;
  int64_t lvalue5;
  int local_14 [5];
  
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  value2 = 0;
  local_14[4] = 0;
  value3 = 0;
  if (0 < *(int *)(arg1 + 0x170c)) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x16f8),value3,(int *)0x0);
      if (value1 != 0) {
        value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(value1 + 4),(int *)0x0);
        value1 = *(int *)(value1 + 0x10);
        if (value1 != 4) {
          value2 = value2 + 1;
          local_14[value1] = local_14[value1] + 1;
        }
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(arg1 + 0x170c));
  }
  uptr4 = (uint32_t *)(arg1 + 0x183c);
  value3 = 4;
  do {
    if (value2 < 1) {
      *uptr4 = 0;
    }
    else {
      lvalue5 = __ftol();
      *uptr4 = (intptr_t)lvalue5;
    }
    uptr4 = uptr4 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return;
}
