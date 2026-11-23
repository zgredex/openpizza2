// Weather_SelectRandomState: ported from Pizza Connection 2 at 0x4dca00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dca00
#include "pc2_port.h"

void __fastcall Weather_SelectRandomState(int arg1)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int value4;
  
  uvalue2 = *(uint32_t *)(arg1 + 0x10bc);
  do {
    uvalue3 = _rand();
    uvalue3 = uvalue3 & 7;
    *(uint32_t *)(arg1 + 0x10bc) = uvalue3;
  } while (uvalue2 == uvalue3);
  value4 = *(int *)(&DAT_0056ca28 + uvalue3 * 0x24) -
          (uint32_t)*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  value1 = value4 + 0x30;
  *(int *)(arg1 + 0x10c0) = value1;
  if (value1 < 0x19) {
    *(int *)(arg1 + 0x10c0) = value4 + 0x48;
  }
  if (0x30 < *(int *)(arg1 + 0x10c0)) {
    *(int *)(arg1 + 0x10c0) = *(int *)(arg1 + 0x10c0) + -0x18;
  }
  return;
}
