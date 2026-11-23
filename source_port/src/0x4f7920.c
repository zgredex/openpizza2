// Map_PickObject: ported from Pizza Connection 2 at 0x4f7920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7920
#include "pc2_port.h"

uint32_t __thiscall Map_PickObject(void *self,int arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  void *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c [3];
  
  value3 = 0;
  value2 = 0;
  local_1c = 0;
  local_20 = (void *)0x0;
  local_18 = 0;
  local_10 = *(int *)(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70) + 0x15c);
  if (0 < local_10) {
    do {
      pvVar1 = (void *)Game_GetPlayerSubrecord(self,arg1,value2,1);
      if ((pvVar1 != (void *)0x0) &&
         (value3 = AI_ComputePlanScores((intptr_t)pvVar1,&local_14,local_c,2), value3 == 2)) {
        if ((local_20 == (void *)0x0) || (local_14 < local_18)) {
          local_18 = local_14;
          local_20 = pvVar1;
        }
        value3 = 3;
        local_1c = local_1c + local_14;
      }
      value2 = value2 + 1;
    } while (value2 < local_10);
    if (((9 < value3) && (local_20 != (void *)0x0)) && (local_18 < local_1c / (value3 * 2))) {
      UI_ShiftRowData(self,pvVar1,1);
      return 1;
    }
  }
  return 0;
}
