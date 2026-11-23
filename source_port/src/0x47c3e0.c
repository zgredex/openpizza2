// Company_AssignEmployee: ported from Pizza Connection 2 at 0x47c3e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c3e0
#include "pc2_port.h"

int __thiscall Company_AssignEmployee(void *self,int *arg1,uint32_t arg2,int arg3)

{
  void *this_00;
  uint32_t uvalue1;
  int value2;
  void *this_01;
  void *this_02;
  uint32_t *this_03;
  uint32_t uvalue3;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  uint32_t extraout_EDX_01;
  uint32_t uvalue4;
  int64_t lvalue5;
  int *ptr6;
  int local_c;
  uint32_t local_4;
  
                    /* Assigns a city person to a company branch. */
  local_c = 200;
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  *(uint32_t *)(*arg1 + 0x820) = *(uint32_t *)((intptr_t)self + 0x3c);
  *(uint32_t *)(*arg1 + 0x81c) = *(uint32_t *)((intptr_t)self + 0x30);
  Game_GetPlayerCity(value2);
  lvalue5 = Rating_GetCompositeTruncated(*arg1);
  Person_SetPerformance((void *)*arg1,(intptr_t)lvalue5);
  arg1[1] = arg3;
  this_01 = (void *)Game_GetRecordByField814(*arg1);
  this_02 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x34),
                                 (int *)0x0);
  this_00 = *(void **)((intptr_t)this_02 + 0xfa8);
  do {
    value2 = Array_GetRecord28(this_00,1,*(int *)(*(int *)((intptr_t)self + 0x16f0) + 0x54));
    this_03 = City_FindFreePlotsNearPoint(this_02,this_00,0,value2,local_c,0);
    value2 = this_03[5];
    uvalue3 = extraout_EDX;
    if (value2 != 0) {
      ptr6 = (int *)0x0;
      uvalue3 = Random_RangeFast(0,value2 - 1);
      local_4 = IDMap_Lookup(this_03,uvalue3,ptr6);
      uvalue3 = extraout_EDX_00;
    }
    local_c = local_c + 100;
    if (this_03 != (uint32_t *)0x0) {
      (**(code **)*this_03)(1);
      uvalue3 = extraout_EDX_01;
    }
  } while (value2 == 0);
  *(uint32_t *)((intptr_t)this_01 + 0xcc) = local_4;
  *(uint32_t *)((intptr_t)this_01 + 0x7c) = 0xff;
  Person_SetAtWork((intptr_t)this_01,uvalue3,(intptr_t)self,'\x01');
  uvalue4 = 0xffffffff;
  Object_SetFieldA4Locked(this_01,0xffffffff);
  *(uint32_t *)((intptr_t)this_01 + 0x88) = 0xffffffff;
  switch(arg2) {
  case 0:
    uvalue4 = 0x11;
    break;
  case 1:
    uvalue4 = 0x12;
    break;
  case 2:
    uvalue4 = 0x13;
    break;
  case 3:
    uvalue4 = 0x14;
    break;
  default:
    goto switchD_0047c509_default;
  }
  *(uint32_t *)((intptr_t)this_01 + 0x78) = uvalue4;
switchD_0047c509_default:
  Person_TruncatePathToCurrentStep((intptr_t)this_01);
  value2 = List_Add((void *)((intptr_t)self + 0x1500),arg1);
  Game_ToggleObjectFlag2(self);
  Stats_ResetAverages(self);
  uvalue1 = *(uint32_t *)((intptr_t)this_01 + 0x30);
  *(uint32_t *)((intptr_t)this_01 + 0x30) = uvalue4;
  Object_SetBuildingRecordForAllCompanies(this_01,0,*(int *)((intptr_t)this_01 + 0xcc));
  *(uint32_t *)((intptr_t)this_01 + 0x30) = uvalue1;
  return value2;
}
