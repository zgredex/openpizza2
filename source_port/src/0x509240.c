// UI_SetChildHeightFromValue: ported from Pizza Connection 2 at 0x509240.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509240
#include "pc2_port.h"

void __fastcall UI_SetChildHeightFromValue(int arg1)

{
  int value1;
  int64_t lvalue2;
  
  if (*(int *)(arg1 + 200) != 0) {
    value1 = State_Is2DOr2E(arg1);
    if (value1 == 0) {
      lvalue2 = __ftol();
      *(short *)(*(int *)(arg1 + 200) + 8) = 0x99 - (short)lvalue2;
      if (*(short *)(*(int *)(arg1 + 200) + 8) < 0x88) {
        *(uint16_t *)(*(int *)(arg1 + 200) + 8) = 0x88;
      }
    }
  }
  return;
}
