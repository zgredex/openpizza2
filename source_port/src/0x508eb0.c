// Game_UpdatePlayerObject: ported from Pizza Connection 2 at 0x508eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508eb0
#include "pc2_port.h"

void __thiscall Game_UpdatePlayerObject(void *self,int *arg1)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  int value4;
  
  this_00 = (void *)Game_GetPlayerSubmapValue
                              (DAT_0057c670,*(int *)(*(int *)((intptr_t)self + 0xf4) + 8),
                               *(int *)(*(int *)((intptr_t)self + 0xf4) + 0x2c));
  if (this_00 == (void *)0x0) {
    return;
  }
  value1 = Game_PickRandomUnownedAdjacentRecord(this_00,(intptr_t)self,1,arg1);
  if (value1 == 0) {
    return;
  }
  value3 = *(int *)(value1 + 0x1c);
  value4 = *(int *)(value1 + 0x18);
  value2 = Grid_GetCell(*(void **)((intptr_t)self + 0xc4),value4,value3);
  value1 = City_IndexOfListValue
                    (DAT_0057c670,*(int *)(*(int *)(value2 + 8) + 0x10),*(int *)(value1 + 4),
                     *(int *)(value1 + 8));
  *(int *)((intptr_t)self + 0x84) = value1;
  *(uint32_t *)((intptr_t)self + 0x88) = **(uint32_t **)(value2 + 8);
  switch(value1) {
  case 0:
    value4 = value4 + 3;
    break;
  case 1:
    value3 = value3 + -3;
    break;
  case 2:
    value3 = value3 + 1;
    value4 = value4 + -2;
    break;
  case 3:
    value3 = value3 + 3;
    value4 = value4 + 1;
    break;
  default:
    goto switchD_00508f3b_default;
  }
  value2 = Grid_GetCell(*(void **)((intptr_t)self + 0xc4),value4,value3);
switchD_00508f3b_default:
  *(uint32_t *)((intptr_t)self + 0x8c) = **(uint32_t **)(value2 + 8);
  Array_GetRecord28(*(void **)((intptr_t)self + 0xc4),1,(intptr_t)*(short *)(*(int *)(value2 + 8) + 0x24));
  return;
}
