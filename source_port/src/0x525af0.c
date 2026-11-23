// UI_ProcessCommandQueue: ported from Pizza Connection 2 at 0x525af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525af0
#include "pc2_port.h"

void __fastcall UI_ProcessCommandQueue(int arg1)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  code *cptr4;
  uint32_t uvalue5;
  int value6;
  
  value6 = *(int *)(arg1 + 0x82bc);
  if (value6 != *(int *)(arg1 + 0x82c0)) {
    do {
      value1 = *(int *)(arg1 + (value6 * 5 + 0xcb2) * 4);
      if (value1 == 0x22) {
        *(uint32_t *)(arg1 + 0x82bc) = value6 + 1U & 0x3ff;
      }
      else {
        uvalue2 = *(uint32_t *)(arg1 + 0x32c0 + value6 * 0x14);
        uvalue3 = *(uint32_t *)(arg1 + 0x32c4 + value6 * 0x14);
        cptr4 = *(code **)(arg1 + 0x32bc + value6 * 0x14);
        uvalue5 = *(uint32_t *)(arg1 + value6 * 0x14 + 0x32cc);
        *(uint32_t *)(arg1 + 0x82bc) = value6 + 1U & 0x3ff;
        (*cptr4)(uvalue2,uvalue3,value1,uvalue5);
      }
      value6 = *(int *)(arg1 + 0x82bc);
    } while (value6 != *(int *)(arg1 + 0x82c0));
  }
  return;
}
