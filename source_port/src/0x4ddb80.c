// Player_AddBranchPlan: ported from Pizza Connection 2 at 0x4ddb80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddb80
#include "pc2_port.h"


int __thiscall Player_AddBranchPlan(void *self,uint32_t arg1)

{
  int value1;
  uint32_t *uptr2;
  void *this_00;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Registers a branch target and its type-2 plan. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005593bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  value1 = List_Add((void *)((intptr_t)self + 0x148),arg1);
  uptr2 = operator_new(0x30);
  this_00 = (void *)0x0;
  local_4 = 0;
  if (uptr2 != (uint32_t *)0x0) {
    this_00 = (void *)GamePlan_Construct(uptr2);
  }
  local_4 = 0xffffffff;
  Game_SetDifficulty(this_00,2);
  *(int *)((intptr_t)this_00 + 0xc) = value1;
  List_Add((void *)((intptr_t)self + 300),this_00);
  ExceptionList = local_c;
  return value1;
}
