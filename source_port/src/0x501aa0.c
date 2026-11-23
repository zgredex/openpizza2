// Player_AIState_StreamConstruct: ported from Pizza Connection 2 at 0x501aa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501aa0
#include "pc2_port.h"


uint32_t * __thiscall Player_AIState_StreamConstruct(void *self,void *arg1)

{
  uint32_t uvalue1;
  int value2;
  uint32_t *uptr3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a1eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x68),0);
  local_4 = 0;
  *(uint8_t ***)self = &PTR_Player_AIState_Delete_0055c664;
  if (arg1 != (void *)0x0) {
    Player_AIState_Load(self,arg1);
    ExceptionList = local_c;
    return self;
  }
  BuildingProject_ResetState((intptr_t)self);
  uptr3 = (uint32_t *)((intptr_t)self + 0xc);
  for (value2 = 0xd; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0x88);
  for (value2 = 0x39; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0x16c);
  for (value2 = 0x39; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uvalue1 = Random_RangeFast(0xd,0x16);
  *(uint32_t *)((intptr_t)self + 0x5c) = uvalue1;
  ExceptionList = local_c;
  return self;
}
