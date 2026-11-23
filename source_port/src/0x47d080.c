// Game_PickRandomUnownedAdjacentRecord: ported from Pizza Connection 2 at 0x47d080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d080
#include "pc2_port.h"

int __thiscall Game_PickRandomUnownedAdjacentRecord(void *self,int arg1,int arg2,int *arg3)

{
  char cVar1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int *ptr5;
  int value6;
  int local_7d4;
  int local_7d0 [500];
  
  value6 = 0;
  local_7d4 = 0;
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x170c)) {
    ptr5 = local_7d0;
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value6,(int *)0x0);
      if (value2 != 0) {
        cVar1 = Game_GetPlayerByte8(value2);
        if (((cVar1 == '\x01') && (*(int *)(value2 + 0x10) < 1)) && (0 < *(int *)(value2 + 0xc))) {
          value3 = Game_HasAdjacentOccupiedCell(self,value2);
          if (value3 != 0) {
            *ptr5 = value2;
            local_7d4 = local_7d4 + 1;
            ptr5 = ptr5 + 1;
          }
        }
      }
      value6 = value6 + 1;
    } while (value6 < *(int *)((intptr_t)self + 0x170c));
    value2 = local_7d4;
  }
  *arg3 = value2;
  if (value2 < 1) {
    value2 = 0;
  }
  else {
    uvalue4 = Random_RangeFast(0,value2 - 1);
    value2 = local_7d0[uvalue4];
    if (arg2 != 0) {
      *(uint32_t *)(value2 + 0x10) = *(uint32_t *)(arg1 + 0x164);
      return value2;
    }
  }
  return value2;
}
