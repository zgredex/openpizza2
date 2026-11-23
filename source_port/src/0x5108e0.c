// Recipe_LoadFromStream: ported from Pizza Connection 2 at 0x5108e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5108e0
#include "pc2_port.h"


void __thiscall Recipe_LoadFromStream(void *self,int *arg1)

{
  int value1;
  int *this_00;
  uint32_t *uptr2;
  void *pvVar3;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  this_00 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a446;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(arg1,(intptr_t)self + 4,0x40);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x44,4);
  CRT_Istream_Read(this_00,&local_14,4);
  if ((local_14 < 0) || (10000 < local_14)) {
    value1 = *(int *)(*this_00 + 4);
    if (*(int *)((intptr_t)this_00 + value1 + 0x34) < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)this_00 + value1 + 0x38));
    }
    *(uint32_t *)((intptr_t)this_00 + value1 + 8) = 4;
    if (*(int *)((intptr_t)this_00 + value1 + 0x34) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)this_00 + value1 + 0x38));
    }
  }
  else {
    local_18 = 0;
    if (0 < local_14) {
      do {
        arg1 = operator_new(0x1c);
        local_4 = 0;
        if (arg1 == (int *)0x0) {
          uptr2 = (uint32_t *)0x0;
        }
        else {
          uptr2 = RecipeTopping_StreamConstruct(arg1,this_00);
        }
        local_4 = 0xffffffff;
        List_Add((void *)((intptr_t)self + 0x48),uptr2);
        local_18 = local_18 + 1;
      } while (local_18 < local_14);
    }
    CRT_Istream_Read(this_00,(intptr_t)self + 100,0x158);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x1bc,0x1c);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x1d8,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x1dc,1);
    if (DAT_0057c668 < 0x2b) {
      CRT_Istream_Read(this_00,&arg1,1);
    }
    CRT_Istream_Read(this_00,(intptr_t)self + 0x1e0,0x60);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x240,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x244,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x248,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x24c,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x250,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x254,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 600,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x264,0x20);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x284,0x20);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x2a4,0x20);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x2c4,0x20);
    CRT_Istream_Read(this_00,&local_18,4);
    if (local_18 == 0) {
      *(uint32_t *)((intptr_t)self + 0x304) = 0;
    }
    else {
      local_10 = operator_new(0x1c);
      local_4 = 1;
      if (local_10 == (void *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uptr2 = List_Construct(local_10,0);
      }
      *(uint32_t **)((intptr_t)self + 0x304) = uptr2;
      local_4 = 0xffffffff;
      CRT_Istream_Read(this_00,&local_14,4);
      local_18 = 0;
      if (0 < local_14) {
        do {
          pvVar3 = operator_new(0x1c);
          CRT_Istream_Read(this_00,pvVar3,4);
          CRT_Istream_Read(this_00,(intptr_t)pvVar3 + 4,4);
          CRT_Istream_Read(this_00,(intptr_t)pvVar3 + 8,4);
          CRT_Istream_Read(this_00,(intptr_t)pvVar3 + 0xc,4);
          CRT_Istream_Read(this_00,(intptr_t)pvVar3 + 0x10,4);
          CRT_Istream_Read(this_00,(intptr_t)pvVar3 + 0x14,4);
          CRT_Istream_Read(this_00,(intptr_t)pvVar3 + 0x18,4);
          List_Add(*(void **)((intptr_t)self + 0x304),pvVar3);
          local_18 = local_18 + 1;
        } while (local_18 < local_14);
      }
    }
    CRT_Istream_Read(this_00,(intptr_t)self + 0x308,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x30c,4);
  }
  ExceptionList = local_c;
  return;
}
