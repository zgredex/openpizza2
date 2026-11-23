// Object_AttachBuildingValue: ported from Pizza Connection 2 at 0x47c2b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c2b0
#include "pc2_port.h"


void __thiscall Object_AttachBuildingValue(void *self,int arg1)

{
  void *this_00;
  uint32_t *this_01;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)((intptr_t)self + 0x16f0) = arg1;
  *(uint32_t *)(arg1 + 0x94) = 0;
  this_01 = *(uint32_t **)(*(int *)((intptr_t)self + 0x16f0) + 0x74);
  if (this_01 == (uint32_t *)0x0) {
    this_00 = operator_new(0x20);
    local_4 = 0;
    if (this_00 == (void *)0x0) {
      this_01 = (uint32_t *)0x0;
    }
    else {
      this_01 = BuildingValue_Construct
                          (this_00,*(uint32_t *)((intptr_t)self + 0x38),
                           *(uint32_t *)((intptr_t)self + 0x30));
    }
    local_4 = 0xffffffff;
    *(uint32_t **)(*(int *)((intptr_t)self + 0x16f0) + 0x74) = this_01;
  }
  else {
    Game_SetHQLevel(this_01,*(uint32_t *)((intptr_t)self + 0x38));
    Object_SetField0C(this_01,*(uint32_t *)((intptr_t)self + 0x30));
  }
  this_01[6] = 0;
  this_01[4] = 0;
  this_01[5] = 0;
  Game_FreeSubmapObjects((intptr_t)self);
  ExceptionList = local_c;
  return;
}
