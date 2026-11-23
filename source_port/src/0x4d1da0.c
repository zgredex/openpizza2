// MapObject_Load: ported from Pizza Connection 2 at 0x4d1da0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d1da0
#include "pc2_port.h"


void __thiscall MapObject_Load(void *self,void *arg1)

{
  void *this_00;
  uint32_t *uptr1;
  int value2;
  int local_18;
  uint32_t local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  this_00 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558d2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(arg1,(intptr_t)self + 4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x4c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x50,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x2c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x30,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x34,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x38,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x3c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x94,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10,0x10);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x20,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x24,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x40,8);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x48,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x54,4);
  CRT_Istream_Read(this_00,(int *)((intptr_t)self + 0x28),4);
  if (*(int *)((intptr_t)self + 0x28) == -1) {
    NoOp_Stub();
  }
  CRT_Istream_Read(this_00,&arg1,4);
  Game_UpdateIDMapEntry(DAT_0057c5cc,(intptr_t)arg1);
  CRT_Istream_Read(this_00,&local_18,4);
  value2 = 0;
  if (0 < local_18) {
    do {
      CRT_Istream_Read(this_00,&arg1,4);
      List_Add((void *)((intptr_t)self + 0x58),arg1);
      value2 = value2 + 1;
    } while (value2 < local_18);
  }
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (void *)0x1) {
    local_10 = operator_new(0x20);
    local_4 = 0;
    if (local_10 == (void *)0x0) {
      local_4 = 0xffffffff;
      *(uint32_t *)((intptr_t)self + 0x74) = 0;
    }
    else {
      uptr1 = BuildingValue_StreamConstruct(local_10,this_00);
      local_4 = 0xffffffff;
      *(uint32_t **)((intptr_t)self + 0x74) = uptr1;
    }
  }
  else {
    *(uint32_t *)((intptr_t)self + 0x74) = 0;
  }
  CRT_Istream_Read(this_00,&local_18,4);
  arg1 = (void *)0x0;
  if (0 < local_18) {
    do {
      CRT_Istream_Read(this_00,&local_14,4);
      List_Add((void *)((intptr_t)self + 0x78),local_14);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_18);
  }
  ExceptionList = local_c;
  return;
}
