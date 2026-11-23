// Company_Load: ported from Pizza Connection 2 at 0x4e0f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0f90
#include "pc2_port.h"


void __thiscall Company_Load(void *self,int *arg1)

{
  int *this_00;
  int value1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  void *pvVar4;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  this_00 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559452;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(arg1,(intptr_t)self + 8,0x40);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x48,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x4c,4);
  CRT_Istream_Read(this_00,&arg1,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x5c,2);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x50,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x54,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1dc,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x108,8);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1e4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1e0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 100,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x68,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x6c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x70,0x24);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x94,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xac,6);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xcc,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xb4,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xf0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xf4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xf8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xe4,10);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x60,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x58,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1e8,4);
  if (DAT_0057c668 < 0x2d) {
    *(uint32_t *)((intptr_t)self + 0xfc) = 0;
    *(uint32_t *)((intptr_t)self + 0x100) = 0;
  }
  else {
    CRT_Istream_Read(this_00,(intptr_t)self + 0xfc,4);
    CRT_Istream_Read(this_00,(intptr_t)self + 0x100,4);
  }
  CRT_Istream_Read(this_00,&local_14,4);
  if (local_14 == -1) {
    *(uint32_t *)((intptr_t)self + 0x1d8) = 0;
  }
  else {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    uvalue2 = IDMap_Lookup((void *)(value1 + 0xfac),local_14,(int *)0x0);
    *(uint32_t *)((intptr_t)self + 0x1d8) = uvalue2;
  }
  CRT_Istream_Read(this_00,&local_18,4);
  value1 = 0;
  if (0 < local_18) {
    do {
      local_10 = operator_new(0x30);
      local_4 = 0;
      if (local_10 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = GamePlan_StreamConstruct(local_10,this_00);
      }
      local_4 = 0xffffffff;
      List_Add((void *)((intptr_t)self + 300),uptr3);
      value1 = value1 + 1;
    } while (value1 < local_18);
  }
  CRT_Istream_Read(this_00,&local_18,4);
  if ((local_18 < 0) || (10000 < local_18)) {
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
    value1 = 0;
    if (0 < local_18) {
      do {
        CRT_Istream_Read(this_00,&local_14,4);
        local_10 = operator_new(0x330);
        local_4 = 1;
        if (local_10 == (void *)0x0) {
          uptr3 = (uint32_t *)0x0;
        }
        else {
          uptr3 = Recipe_Construct(local_10,this_00,'\x01');
        }
        local_4 = 0xffffffff;
        IDMap_InsertGrow((void *)((intptr_t)self + 0x110),uptr3,local_14);
        value1 = value1 + 1;
      } while (value1 < local_18);
    }
    CRT_Istream_Read(this_00,&local_14,4);
    if (local_14 == 1) {
      local_10 = operator_new(0x330);
      local_4 = 2;
      if (local_10 == (void *)0x0) {
        local_4 = 0xffffffff;
        *(uint32_t *)((intptr_t)self + 0x1d4) = 0;
      }
      else {
        uptr3 = Recipe_Construct(local_10,this_00,'\x01');
        local_4 = 0xffffffff;
        *(uint32_t **)((intptr_t)self + 0x1d4) = uptr3;
      }
    }
    else {
      *(uint32_t *)((intptr_t)self + 0x1d4) = 0;
    }
    CRT_Istream_Read(this_00,&local_18,4);
    value1 = 0;
    if (0 < local_18) {
      do {
        CRT_Istream_Read(this_00,&local_14,4);
        local_10 = operator_new(0x1a3c);
        local_4 = 3;
        if (local_10 == (void *)0x0) {
          uptr3 = (uint32_t *)0x0;
        }
        else {
          uptr3 = Branch_ConstructFromStream(local_10,this_00,self);
        }
        local_4 = 0xffffffff;
        IDMap_InsertGrow((void *)((intptr_t)self + 0x148),uptr3,local_14);
        value1 = value1 + 1;
      } while (value1 < local_18);
    }
    CRT_Istream_Read(this_00,&local_18,4);
    value1 = 0;
    if (0 < local_18) {
      do {
        local_10 = operator_new(0x35c);
        local_4 = 4;
        if (local_10 == (void *)0x0) {
          uptr3 = (uint32_t *)0x0;
        }
        else {
          uptr3 = StatsPeriodReport_StreamConstruct(local_10,this_00);
        }
        local_4 = 0xffffffff;
        List_Add((void *)((intptr_t)self + 0x164),uptr3);
        value1 = value1 + 1;
      } while (value1 < local_18);
    }
    CRT_Istream_Read(this_00,&local_18,4);
    value1 = 0;
    if (0 < local_18) {
      do {
        CRT_Istream_Read(this_00,&local_14,4);
        local_10 = operator_new(0x150);
        local_4 = 5;
        if (local_10 == (void *)0x0) {
          uptr3 = (uint32_t *)0x0;
        }
        else {
          uptr3 = Storage_Construct(local_10,this_00);
        }
        local_4 = 0xffffffff;
        IDMap_InsertGrow((void *)((intptr_t)self + 0x180),uptr3,local_14);
        value1 = value1 + 1;
      } while (value1 < local_18);
    }
    CRT_Istream_Read(this_00,&local_18,4);
    value1 = 0;
    if (0 < local_18) {
      do {
        pvVar4 = operator_new(8);
        CRT_Istream_Read(this_00,&local_14,4);
        CRT_Istream_Read(this_00,pvVar4,8);
        IDMap_InsertGrow((void *)((intptr_t)self + 0x1b8),pvVar4,local_14);
        value1 = value1 + 1;
      } while (value1 < local_18);
    }
    CRT_Istream_Read(this_00,&local_18,4);
    value1 = 0;
    if (0 < local_18) {
      do {
        pvVar4 = operator_new(0x1a0);
        CRT_Istream_Read(this_00,pvVar4,0x1a0);
        List_Add((void *)((intptr_t)self + 0x19c),pvVar4);
        value1 = value1 + 1;
      } while (value1 < local_18);
    }
    Company_InvalidateAllBranchRatings((intptr_t)self);
  }
  ExceptionList = local_c;
  return;
}
