// MapObject_CreateFromTile: ported from Pizza Connection 2 at 0x4f9df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f9df0
#include "pc2_port.h"

void MapObject_CreateFromTile
               (int *arg1,int arg2,uint16_t arg3,uint16_t arg4,uint8_t arg5,
               int arg6,int arg7)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  int64_t lvalue5;
  
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*arg1 + 0x30));
  value2 = Game_GetPlayerCity(value1);
  ptr3 = operator_new(0x24);
  *(uint16_t *)((intptr_t)ptr3 + 0x16) = arg4;
  *(uint16_t *)(ptr3 + 5) = arg3;
  ptr3[7] = arg7;
  *(uint8_t *)(ptr3 + 6) = arg5;
  ptr3[8] = (uint32_t)(arg6 == 1);
  *ptr3 = arg2;
  ptr3[1] = 0;
  City_FindListContainingValue(arg2,ptr3 + 3,ptr3 + 4);
  value1 = ptr3[3];
  if (value1 < 1) goto LAB_004f9ecc;
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x74),value1,(int *)0x0);
  if (*(int *)(value1 + 0xc) == 5) {
    ptr3[2] = arg1[6];
LAB_004f9eb1:
    ptr3[7] = 1;
  }
  else {
    value4 = Building_GetLevelFromType(value1);
    ptr3[2] = value4;
    if (value4 == -1) {
      ptr3[2] = arg1[5];
    }
    if (*(int *)(value1 + 0xc) == 6) goto LAB_004f9eb1;
  }
  Game_ComputePrice(value1,value2);
  lvalue5 = __ftol();
  ptr3[1] = (intptr_t)lvalue5;
LAB_004f9ecc:
  List_Add((void *)arg1[3],ptr3);
  return;
}
