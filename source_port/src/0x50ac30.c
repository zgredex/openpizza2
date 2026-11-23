// UI_SetChildIconAndRatingHeight: ported from Pizza Connection 2 at 0x50ac30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ac30
#include "pc2_port.h"

void __fastcall UI_SetChildIconAndRatingHeight(int arg1)

{
  int value1;
  int64_t lvalue2;
  
  if (*(int *)(arg1 + 200) != 0) {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(arg1 + 0x50),(int *)0x0);
    Rating_GetComposite(value1);
    switch(*(uint8_t *)(value1 + 0x824)) {
    case 0:
      *(uint16_t *)(*(int *)(arg1 + 200) + 8) = 0x2c;
      break;
    case 1:
      *(uint16_t *)(*(int *)(arg1 + 200) + 8) = 0x2e;
      break;
    case 2:
      *(uint16_t *)(*(int *)(arg1 + 200) + 8) = 0x2d;
      break;
    case 3:
      *(uint16_t *)(*(int *)(arg1 + 200) + 8) = 0x2b;
    }
    lvalue2 = __ftol();
    *(short *)(*(int *)(arg1 + 200) + 10) = 0x99 - (short)lvalue2;
    if (*(short *)(*(int *)(arg1 + 200) + 10) < 0x88) {
      *(uint16_t *)(*(int *)(arg1 + 200) + 10) = 0x88;
    }
  }
  return;
}
