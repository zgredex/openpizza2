// CompanyData_Save: ported from Pizza Connection 2 at 0x4e1540.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1540
#include "pc2_port.h"

void __thiscall CompanyData_Save(void *self,void *arg1)

{
  void *this_00;
  void *pvVar1;
  void *this_01;
  uint32_t uvalue2;
  int value3;
  uint8_t local_5;
  int local_4;
  
  this_00 = arg1;
  local_5 = 0;
  CRT_Ostream_Write(arg1,(intptr_t)self + 8,0x40);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x48,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x4c,4);
  CRT_Ostream_Write(this_00,&local_5,1);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x5c,2);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x50,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x54,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1dc,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x108,8);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1e4,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1e0,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 100,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x68,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x6c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x70,0x24);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x94,0x18);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xac,6);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xcc,0x18);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xb4,0x18);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xf0,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xf4,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xf8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xe4,10);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x60,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x58,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1e8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xfc,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x100,4);
  pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  local_4 = Array_FindIndexByPtr(pvVar1,*(int *)((intptr_t)self + 0x1d8));
  CRT_Ostream_Write(this_00,&local_4,4);
  arg1 = *(void **)((intptr_t)self + 0x140);
  CRT_Ostream_Write(this_00,&arg1,4);
  value3 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = this_00;
      this_01 = (void *)IDMap_Lookup((void *)((intptr_t)self + 300),value3,(int *)0x0);
      GamePlan_SaveRecord(this_01,pvVar1);
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1);
  }
  arg1 = *(void **)((intptr_t)self + 0x124);
  CRT_Ostream_Write(this_00,&arg1,4);
  value3 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x110),value3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      Recipe_SaveToStream(pvVar1,this_00,'\x01');
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1);
  }
  value3 = 0;
  if (*(int *)((intptr_t)self + 0x1d4) == 0) {
    local_4 = 0;
    CRT_Ostream_Write(this_00,&local_4,4);
  }
  else {
    local_4 = 1;
    CRT_Ostream_Write(this_00,&local_4,4);
    Recipe_SaveToStream(*(void **)((intptr_t)self + 0x1d4),this_00,'\x01');
  }
  arg1 = *(void **)((intptr_t)self + 0x15c);
  CRT_Ostream_Write(this_00,&arg1,4);
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),value3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      Branch_Save(pvVar1,this_00);
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1);
  }
  arg1 = *(void **)((intptr_t)self + 0x178);
  CRT_Ostream_Write(this_00,&arg1,4);
  value3 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x164),value3,(int *)0x0);
      StatsPeriodReport_Save(pvVar1,this_00);
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1);
  }
  arg1 = *(void **)((intptr_t)self + 0x194);
  CRT_Ostream_Write(this_00,&arg1,4);
  value3 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x180),value3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      Storage_SaveRecord(pvVar1,this_00);
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1);
  }
  arg1 = *(void **)((intptr_t)self + 0x1cc);
  CRT_Ostream_Write(this_00,&arg1,4);
  value3 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      uvalue2 = IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value3,&local_4);
      CRT_Ostream_Write(this_00,&local_4,4);
      CRT_Ostream_Write(this_00,uvalue2,8);
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1);
  }
  arg1 = *(void **)((intptr_t)self + 0x1b0);
  CRT_Ostream_Write(this_00,&arg1,4);
  value3 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      uvalue2 = IDMap_Lookup((void *)((intptr_t)self + 0x19c),value3,(int *)0x0);
      CRT_Ostream_Write(this_00,uvalue2,0x1a0);
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1);
  }
  return;
}
