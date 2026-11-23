// Branch_CollectOrdersByCategory: ported from Pizza Connection 2 at 0x47d270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d270
#include "pc2_port.h"


uint32_t * __thiscall Branch_CollectOrdersByCategory(void *self,uint32_t arg1)

{
  uint8_t flag1;
  void *this_00;
  int value2;
  int value3;
  uint32_t *local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557fab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x1c);
  value3 = 0;
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_14 = (uint32_t *)0x0;
  }
  else {
    local_14 = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)((intptr_t)self + 0x170c) < 1) {
    ExceptionList = local_c;
    return local_14;
  }
  do {
    value2 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value3,(int *)0x0);
    flag1 = Game_GetPlayerByte8(value2);
    if (flag1 == arg1) {
      List_Add(local_14,value2);
    }
    value3 = value3 + 1;
  } while (value3 < *(int *)((intptr_t)self + 0x170c));
  ExceptionList = local_c;
  return local_14;
}
