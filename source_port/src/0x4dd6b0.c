// Company_ConstructDefault: ported from Pizza Connection 2 at 0x4dd6b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd6b0
#include "pc2_port.h"

uint32_t * __thiscall Company_ConstructDefault(void *self,uint32_t arg1)

{
  void *this_00;
  uint32_t *uptr1;
  int value2;
  void *this_01;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs a company with default state and seven lists. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005592f8;
  local_c = ExceptionList;
  this_01 = (void *)0x0;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x110),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 300),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x148),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x164),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x180),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x19c),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1b8),0);
  *(uint32_t *)((intptr_t)self + 0x48) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x50) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x4c) = arg1;
  *(uint32_t *)((intptr_t)self + 0x1e4) = 1;
  *(uint32_t *)((intptr_t)self + 100) = 1;
  *(uint32_t *)((intptr_t)self + 0x68) = 1;
  *(uint32_t *)((intptr_t)self + 0x6c) = 1;
  *(uint32_t *)((intptr_t)self + 0x108) = 0;
  *(uint32_t *)((intptr_t)self + 0xf0) = 100;
  *(uint32_t *)((intptr_t)self + 0xf4) = 100;
  *(uint32_t *)((intptr_t)self + 0xf8) = 100;
  *(uint8_t ***)self = &PTR_Company_Delete_0055c568;
  *(uint16_t *)((intptr_t)self + 0x5c) = 0;
  *(uint32_t *)((intptr_t)self + 0x1d4) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x10c) = 0;
  *(uint32_t *)((intptr_t)self + 0x1e0) = 0;
  *(uint32_t *)((intptr_t)self + 0x1d8) = 0;
  *(uint32_t *)((intptr_t)self + 0x60) = 0;
  *(uint32_t *)((intptr_t)self + 0x1e8) = 0;
  *(uint32_t *)((intptr_t)self + 0x58) = 0;
  *(uint32_t *)((intptr_t)self + 0xfc) = 0;
  *(uint32_t *)((intptr_t)self + 0x100) = 0;
  uptr1 = (uint32_t *)((intptr_t)self + 0x70);
  for (value2 = 9; value2 != 0; value2 = value2 + -1) {
    *uptr1 = 0;
    uptr1 = uptr1 + 1;
  }
  uptr1 = (uint32_t *)((intptr_t)self + 0x94);
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *uptr1 = 0;
    uptr1 = uptr1 + 1;
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  *(uint32_t *)((intptr_t)self + 0xac) = 0;
  *(uint16_t *)((intptr_t)self + 0xb0) = 0;
  uptr1 = (uint32_t *)((intptr_t)self + 0xcc);
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *uptr1 = 0;
    uptr1 = uptr1 + 1;
  }
  uptr1 = (uint32_t *)((intptr_t)self + 0xb4);
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *uptr1 = 0;
    uptr1 = uptr1 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0xe4) = 0;
  *(uint32_t *)((intptr_t)self + 0xe8) = 0;
  *(uint16_t *)((intptr_t)self + 0xec) = 0;
  this_00 = operator_new(0x35c);
  local_4 = (local_4 & ~(0x0u << 8)) | (((7) & 0x0u) << 8);
  if (this_00 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Stats_Report_Construct
                       (this_00,(uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10),
                        (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4),(intptr_t)self);
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  List_Add((void *)((intptr_t)self + 0x164),uptr1);
  uptr1 = operator_new(0x30);
  local_4 = (local_4 & ~(0x0u << 8)) | (((8) & 0x0u) << 8);
  if (uptr1 != (uint32_t *)0x0) {
    this_01 = (void *)GamePlan_Construct(uptr1);
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),6);
  Game_SetDifficulty(this_01,1);
  List_Add((void *)((intptr_t)self + 300),this_01);
  ExceptionList = local_c;
  return self;
}
