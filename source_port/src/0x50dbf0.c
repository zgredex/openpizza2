// Object_FindOpposingTarget: ported from Pizza Connection 2 at 0x50dbf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50dbf0
#include "pc2_port.h"


int __fastcall Object_FindOpposingTarget(int arg1)

{
  void *self;
  int value1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int *ptr5;
  uint32_t local_28 [5];
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a338;
  local_c = ExceptionList;
  value4 = 0;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  self = *(void **)(arg1 + 0xfc);
  local_4 = 0;
  if (0 < *(int *)((intptr_t)self + 0x8c)) {
    do {
      value1 = Game_MapRecordToGlobal(self,value4);
      value2 = State_IsMenuState(value1);
      if (value2 != 0) {
        value2 = State_Is2DOr2E(value1);
        if ((value2 == 0) && (*(int *)(value1 + 200) != 0)) {
          if ((*(int *)(arg1 + 0x38) == 0x3b) && (*(int *)(value1 + 0x38) == 0x3a)) {
            List_Add(local_28,value1);
          }
          if ((*(int *)(arg1 + 0x38) == 0x3a) && (*(int *)(value1 + 0x38) == 0x3b)) {
            List_Add(local_28,value1);
          }
        }
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x8c));
  }
  if (local_14 < 1) {
    local_4 = 0xffffffff;
    List_Node_Destroy(local_28);
    ExceptionList = local_c;
    return 0;
  }
  ptr5 = (int *)0x0;
  uvalue3 = Random_RangeFast(0,local_14 - 1);
  value4 = IDMap_Lookup(local_28,uvalue3,ptr5);
  local_4 = 0xffffffff;
  *(uint32_t *)(arg1 + 0x8c) = *(uint32_t *)(value4 + 0x164);
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return value4;
}
