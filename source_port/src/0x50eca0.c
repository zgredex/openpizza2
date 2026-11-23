// Player_Load: ported from Pizza Connection 2 at 0x50eca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50eca0
#include "pc2_port.h"


void __thiscall Player_Load(void *self,int *arg1)

{
  int value1;
  int *this_00;
  uint32_t *uptr2;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  this_00 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a3bc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(arg1,(intptr_t)self + 0x84,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x88,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x2c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x30,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x3c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x40,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x44,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x48,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x4c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x50,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x54,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x58,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x5c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x60,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 100,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x68,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x6c,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x34,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x38,4);
  local_10 = operator_new(0x828);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = Character_StreamConstruct(local_10,this_00);
  }
  *(uint32_t **)((intptr_t)self + 4) = uptr2;
  local_4 = 0xffffffff;
  CRT_Istream_Read(this_00,&local_14,4);
  if ((local_14 < 0) || (10000 < local_14)) {
    value1 = *(int *)(*this_00 + 4);
    if (*(int *)(value1 + 0x34 + (intptr_t)this_00) < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)this_00 + value1 + 0x38));
    }
    *(uint32_t *)((intptr_t)this_00 + value1 + 8) = 4;
    if (*(int *)((intptr_t)this_00 + value1 + 0x34) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)this_00 + value1 + 0x38));
    }
    ExceptionList = local_c;
    return;
  }
  arg1 = (int *)0x0;
  if (0 < local_14) {
    do {
      local_10 = operator_new(0xc);
      local_4 = 1;
      if (local_10 == (void *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uptr2 = Player_Event_StreamConstruct(local_10,this_00);
      }
      local_4 = 0xffffffff;
      List_Add((void *)((intptr_t)self + 0x8c),uptr2);
      arg1 = (int *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_14);
  }
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (int *)0x0) {
    *(uint32_t *)((intptr_t)self + 0xa8) = 0;
  }
  else {
    local_10 = operator_new(0x250);
    local_4 = 2;
    if (local_10 == (void *)0x0) {
      uptr2 = (uint32_t *)0x0;
    }
    else {
      uptr2 = Player_AIState_StreamConstruct(local_10,this_00);
    }
    local_4 = 0xffffffff;
    *(uint32_t **)((intptr_t)self + 0xa8) = uptr2;
  }
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (int *)0x0) {
    *(uint32_t *)((intptr_t)self + 0xac) = 0;
    ExceptionList = local_c;
    return;
  }
  local_10 = operator_new(0xd8);
  local_4 = 3;
  if (local_10 == (void *)0x0) {
    *(uint32_t *)((intptr_t)self + 0xac) = 0;
    ExceptionList = local_c;
    return;
  }
  uptr2 = Player_MissionState_Construct(local_10,this_00);
  *(uint32_t **)((intptr_t)self + 0xac) = uptr2;
  ExceptionList = local_c;
  return;
}
