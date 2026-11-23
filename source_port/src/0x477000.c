// Branch_ConstructFromStream: ported from Pizza Connection 2 at 0x477000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477000
#include "pc2_port.h"

uint32_t * __thiscall Branch_ConstructFromStream(void *self,void *arg1,uint32_t *arg2)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557eee;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x14e4),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x1500),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x16f8),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1728),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1744),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1760),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x1998),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x19c4),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((7) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x19e0),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),8);
  *(uint8_t ***)self = &PTR_Branch_Delete_0055c30c;
  *(uint32_t *)((intptr_t)self + 0x1a28) = 0;
  Branch_Load(self,arg1,arg2);
  ExceptionList = local_c;
  return self;
}
