// Recipe_AppendSalesRecord: ported from Pizza Connection 2 at 0x50ff80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ff80
#include "pc2_port.h"


void __thiscall Recipe_AppendSalesRecord(void *self,int arg1)

{
  void *this_00;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a41b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)((intptr_t)self + 0x304) == 0) {
    ExceptionList = &local_c;
    this_00 = operator_new(0x1c);
    local_4 = 0;
    if (this_00 == (void *)0x0) {
      uptr1 = (uint32_t *)0x0;
    }
    else {
      uptr1 = List_Construct(this_00,0);
    }
    *(uint32_t **)((intptr_t)self + 0x304) = uptr1;
  }
  local_4 = 0xffffffff;
  uptr1 = operator_new(0x1c);
  uptr1[5] = *(uint32_t *)(arg1 + 0x28);
  uptr1[6] = *(uint32_t *)(arg1 + 0x2c);
  uptr1[4] = *(uint32_t *)(arg1 + 0x24);
  *uptr1 = *(uint32_t *)(arg1 + 0x14);
  uptr1[1] = *(uint32_t *)(arg1 + 0x18);
  uptr1[2] = *(uint32_t *)(arg1 + 0x1c);
  uptr1[3] = *(uint32_t *)(arg1 + 0x20);
  List_Add(*(void **)((intptr_t)self + 0x304),uptr1);
  ExceptionList = local_c;
  return;
}
