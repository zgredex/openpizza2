// Branch_PickRandomActiveCounter: ported from Pizza Connection 2 at 0x480c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480c40
#include "pc2_port.h"


int __fastcall Branch_PickRandomActiveCounter(int arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int *ptr5;
  int local_2c;
  uint32_t local_28 [5];
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005580d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  value3 = *(int *)(arg1 + 0x19ac);
  value4 = 0;
  local_4 = 0;
  if (0 < value3) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x1998),value4,&local_2c);
      if (*(int *)(value1 + 0x1c) != 0) {
        List_Add(local_28,local_2c);
      }
      value4 = value4 + 1;
    } while (value4 < value3);
  }
  if (local_14 < 1) {
    local_4 = 0xffffffff;
    List_Node_Destroy(local_28);
    ExceptionList = local_c;
    return -1;
  }
  ptr5 = (int *)0x0;
  uvalue2 = Random_RangeFast(0,local_14 - 1);
  value3 = IDMap_Lookup(local_28,uvalue2,ptr5);
  local_4 = 0xffffffff;
  local_2c = value3;
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return value3;
}
