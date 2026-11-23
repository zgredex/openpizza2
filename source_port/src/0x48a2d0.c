// Game_FindPreviousFreeObjectOfType: ported from Pizza Connection 2 at 0x48a2d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48a2d0
#include "pc2_port.h"


uint32_t __thiscall Game_FindPreviousFreeObjectOfType(void *self,int arg1)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  uint32_t local_28 [5];
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558368;
  local_c = ExceptionList;
  value5 = 0;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  local_4 = 0;
  value4 = *(int *)(arg1 + 0x30);
  if (0 < *(int *)((intptr_t)self + 0x50)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value5,(int *)0x0);
      value2 = State_Is2DOr2E(value1);
      if ((((value2 == 0) && (*(int *)(value1 + 0x30) == value4)) && (*(int *)(value1 + 0x74) == 0)) &&
         (*(int *)(value1 + 0x110) == -1)) {
        List_Add(local_28,value1);
      }
      value5 = value5 + 1;
    } while (value5 < *(int *)((intptr_t)self + 0x50));
  }
  value4 = 0;
  if (0 < local_14) {
    do {
      value5 = IDMap_Lookup(local_28,value4,(int *)0x0);
      if (value5 == arg1) break;
      value4 = value4 + 1;
    } while (value4 < local_14);
    if (value4 != 0) goto LAB_0048a37c;
  }
  value4 = local_14;
LAB_0048a37c:
  uvalue3 = IDMap_Lookup(local_28,value4 + -1,(int *)0x0);
  local_4 = 0xffffffff;
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return uvalue3;
}
