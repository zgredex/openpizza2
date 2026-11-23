// City_FindFreePlotsNearPoint: ported from Pizza Connection 2 at 0x4d8470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8470
#include "pc2_port.h"


uint32_t * __thiscall
City_FindFreePlotsNearPoint
          (void *self,uint32_t arg1,int arg2,int arg3,int arg4,int arg5)

{
  int value1;
  int value2;
  void *this_00;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  uint32_t *local_20;
  int local_1c;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  value2 = arg3;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055910b;
  local_c = ExceptionList;
  local_1c = 9999999;
  ExceptionList = &local_c;
  this_00 = operator_new(0x1c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_20 = (uint32_t *)0x0;
  }
  else {
    local_20 = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  if (arg4 != 0) {
    local_1c = arg4 * arg4 * 4;
  }
  arg3 = 0;
  value1 = *(int *)(value2 + 0xc);
  value2 = *(int *)(value2 + 0x10);
  if (*(int *)((intptr_t)self + 0xfc0) < 1) {
    ExceptionList = local_c;
    return local_20;
  }
  do {
    value3 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),arg3,(int *)0x0);
    if (((*(int *)(value3 + 0x48) != -1) &&
        ((arg5 == 0 ||
         ((value4 = Game_CanShowObject(value3), value4 != 0 && (*(int *)(value3 + 0x38) < 1)))))) &&
       ((*(int *)(value3 + 4) == arg2 || (arg2 == -1)))) {
      value4 = Game_GetObjectCenterY(value3);
      value4 = value4 - value1;
      value5 = Game_GetObjectBottom(value3);
      value5 = value5 - value2;
      if (arg4 == 0) {
        if (*(int *)(value3 + 0x74) == 0) {
          value7 = -1;
        }
        else {
          value7 = Game_GetAdjustedValue(*(int *)(value3 + 0x74));
        }
        if (*(int *)(value3 + 0x74) == 0) {
          value6 = -1;
        }
        else {
          value6 = Game_GetAdjustedValue(*(int *)(value3 + 0x74));
        }
        local_1c = value6 * value7 * 4;
      }
      if (value4 * value4 + value5 * value5 * 4 < local_1c) {
        List_Add(local_20,value3);
      }
    }
    arg3 = arg3 + 1;
  } while (arg3 < *(int *)((intptr_t)self + 0xfc0));
  ExceptionList = local_c;
  return local_20;
}
