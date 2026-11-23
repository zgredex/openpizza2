// Company_Construct: ported from Pizza Connection 2 at 0x4ddab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddab0
#include "pc2_port.h"

uint32_t * __thiscall Company_Construct(void *self,int *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005593a2;
  local_c = ExceptionList;
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
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),6);
  *(uint8_t ***)self = &PTR_Company_Delete_0055c568;
  Company_Load(self,arg1);
  ExceptionList = local_c;
  return self;
}
