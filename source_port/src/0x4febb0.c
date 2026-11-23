// Branch_ApplyStyleSettings: ported from Pizza Connection 2 at 0x4febb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4febb0
#include "pc2_port.h"

uint32_t __thiscall Branch_ApplyStyleSettings(void *self,int arg1,void *arg2)

{
  int value1;
  int value2;
  int value3;
  
                    /* Applies a branch's AI style adjustment percentages. */
  value1 = Game_GetPlayerFieldC20(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70));
  if (2 < value1) {
    if ((*(int *)((intptr_t)arg2 + 0x14c4) == 0) &&
       (City_AssignPersonToBuilding(arg2,1), *(int *)((intptr_t)arg2 + 0x14c4) == 0)) {
      return 3;
    }
    switch(*(uint32_t *)((intptr_t)arg2 + 0x24)) {
    case 0:
    case 4:
      arg1 = 0x32;
      value1 = 0x1e;
      value2 = 0;
      value3 = -10;
      break;
    case 1:
      arg1 = 0x41;
      value1 = 0x2d;
      value2 = 10;
      value3 = 0;
      break;
    case 2:
      value2 = 10;
      arg1 = 0x46;
      value1 = 0x37;
      value3 = 10;
      break;
    case 3:
      value2 = 0x14;
      arg1 = 0x4b;
      value1 = 0x50;
      value3 = 0x14;
      break;
    default:
      value1 = arg1;
      value2 = arg1;
      value3 = arg1;
    }
    *(int *)((intptr_t)arg2 + 0x14c8) = value1;
    *(int *)((intptr_t)arg2 + 0x14cc) = arg1;
    *(int *)((intptr_t)arg2 + 0x14d0) = value2;
    Game_UpdateObjectRatingScales((intptr_t)arg2);
    *(int *)((intptr_t)arg2 + 0x14c0) = value3;
    *(uint32_t *)((intptr_t)arg2 + 0x14d4) = 0;
    Game_UpdateObjectRatingScales((intptr_t)arg2);
  }
  return 1;
}
