// UI_RandomChildEffect: ported from Pizza Connection 2 at 0x509ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509ff0
#include "pc2_port.h"

void __fastcall UI_RandomChildEffect(int arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int local_4;
  
  if (*(int *)(arg1 + 200) == 0) {
    value2 = 0;
  }
  else {
    value2 = *(int *)(*(int *)(arg1 + 200) + 0x20);
  }
  value2 = *(int *)(*(int *)(arg1 + 0xc4) + 0x4c) + *(int *)(value2 + 8) * 0xc;
  uvalue1 = Random_RangeFast(0x10,0x1c);
  value3 = 0;
  local_4 = value2;
  if (0 < (intptr_t)uvalue1) {
    do {
      value2 = Grid_GetNeighborCell(*(void **)(arg1 + 0xc4),local_4,2);
      if (((value2 == 0) || (*(int *)(value2 + 8) == 0)) ||
         (*(int *)(*(int *)(value2 + 8) + 0x28) == 0)) {
        value2 = local_4;
        break;
      }
      value3 = value3 + 1;
      local_4 = value2;
    } while (value3 < (intptr_t)uvalue1);
  }
  Array_GetRecord28(*(void **)(arg1 + 0xc4),1,(intptr_t)*(short *)(*(int *)(value2 + 8) + 0x24));
  return;
}
