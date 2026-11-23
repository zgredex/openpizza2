// BuildingValue_CreateDefault: ported from Pizza Connection 2 at 0x4d2a00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2a00
#include "pc2_port.h"


void __thiscall BuildingValue_CreateDefault(void *self,uint32_t arg1)

{
  void *this_00;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558d6b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x20);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = BuildingValue_ConstructDefault(this_00,arg1);
  }
  *(uint32_t **)((intptr_t)self + 0x74) = uptr1;
  ExceptionList = local_c;
  return;
}
