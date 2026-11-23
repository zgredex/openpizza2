// UI_GetActionDuration: ported from Pizza Connection 2 at 0x483eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483eb0
#include "pc2_port.h"

int __thiscall UI_GetActionDuration(void *self,int arg1)

{
  int value1;
  int value2;
  
  switch(*(uint32_t *)(arg1 + 4)) {
  case 0xf:
    if (*(int *)(arg1 + 0x38) == 0) {
      value1 = *(int *)(arg1 + 8);
      value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
      return (-(uint32_t)(value1 != value2) & 0xfffffffb) + 0x1a;
    }
switchD_00483ec4_caseD_1a:
    return 0x14;
  case 0x10:
    if (*(int *)(arg1 + 0x38) == 0) {
      value1 = *(int *)(arg1 + 8);
      value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
      return (value1 != value2) + 3;
    }
    return 0x14;
  case 0x11:
    return 0x1c;
  default:
    return 0x12;
  case 0x13:
    return 10;
  case 0x17:
    return 7;
  case 0x18:
    return 9;
  case 0x1a:
    goto switchD_00483ec4_caseD_1a;
  case 0x1b:
    return (-(uint32_t)(*(int *)(arg1 + 8) != -1) & 0x11) + 8;
  case 0x1c:
    return 5;
  }
}
