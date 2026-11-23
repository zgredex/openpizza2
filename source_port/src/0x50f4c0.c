// Player_AIState_Init: ported from Pizza Connection 2 at 0x50f4c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f4c0
#include "pc2_port.h"


void __fastcall Player_AIState_Init(int arg1)

{
  void *pvVar1;
  uint32_t *uptr2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a3e6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x250);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = Player_AIState_StreamConstruct(pvVar1,(void *)0x0);
  }
  local_4 = 0xffffffff;
  *(uint32_t **)(arg1 + 0xa8) = uptr2;
  pvVar1 = operator_new(0xd8);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = Player_MissionState_Construct(pvVar1,(void *)0x0);
  }
  *(uint32_t **)(arg1 + 0xac) = uptr2;
  ExceptionList = local_c;
  return;
}
