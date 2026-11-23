// Action_AddBestRecipeToBranchMenu: ported from Pizza Connection 2 at 0x509580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509580
#include "pc2_port.h"

int __thiscall Action_AddBestRecipeToBranchMenu(void *self,int arg1)

{
  int *ptr1;
  void *pvVar2;
  void *this_00;
  int value3;
  int value4;
  int *ptr5;
  uint32_t uvalue6;
  int value7;
  int value8;
  uint32_t extraout_EDX;
  int *ptr9;
  double fVar10;
  uint64_t uvalue11;
  int local_330;
  int local_328;
  int *local_324;
  int local_320 [200];
  
                    /* Chooses and adds the best recipe to a branch menu. */
  if (arg1 == 0) {
    arg1 = *(int *)((intptr_t)self + 0xf4);
  }
  value4 = *(int *)(arg1 + 8);
  value3 = *(int *)(arg1 + 0x2c);
  pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value4);
  this_00 = (void *)Game_GetPlayerSubmapValue(DAT_0057c670,value4,value3);
  local_328 = 0;
  value3 = Game_CountActiveCompanies((intptr_t)pvVar2);
  value4 = local_328;
  if (-1 < value3) {
    local_324 = local_320 + 1;
    do {
      value4 = Game_CountActiveCompanies((intptr_t)pvVar2);
      if (local_328 == value4) {
        value3 = *(int *)((intptr_t)this_00 + 0x14dc);
        value4 = local_328;
        if (value3 == 0) break;
      }
      else {
        value3 = Game_GetActiveCompanyById(pvVar2,local_328);
      }
      ptr5 = operator_new(0x30);
      *ptr5 = value3;
      fVar10 = Branch_ComputeRecipePrice(value3,(intptr_t)this_00,-999);
      ptr5[1] = (intptr_t)(float)fVar10;
      local_324[-1] = (intptr_t)ptr5;
      value4 = Game_ComputeObjectDetails
                        (self,arg1,ptr5,0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
      *local_324 = value4;
      local_328 = local_328 + 1;
      local_324 = local_324 + 2;
      value3 = Game_CountActiveCompanies((intptr_t)pvVar2);
      value4 = local_328;
    } while (local_328 <= value3);
  }
  while (value4 = value4 + -1, 0 < value4) {
    ptr5 = local_320;
    local_330 = value4;
    do {
      if (ptr5[1] < ptr5[3]) {
        value3 = *ptr5;
        value7 = ptr5[1];
        *ptr5 = ptr5[2];
        ptr5[1] = ptr5[3];
        ptr5[2] = value3;
        ptr5[3] = value7;
      }
      ptr5 = ptr5 + 2;
      local_330 = local_330 + -1;
    } while (local_330 != 0);
  }
  uvalue6 = 0xffffffff;
  if (local_328 < 4) {
    if (local_328 < 1) goto LAB_00509702;
  }
  else {
    uvalue6 = Random_RangeFast(1,100);
    if (0x32 < (intptr_t)uvalue6) {
      uvalue6 = 0;
      goto LAB_00509702;
    }
    if (0x14 < (intptr_t)uvalue6) {
      uvalue6 = 1;
      goto LAB_00509702;
    }
    if (5 < (intptr_t)uvalue6) {
      uvalue6 = 2;
      goto LAB_00509702;
    }
  }
  uvalue6 = Random_RangeFast(0,local_328 - 1);
LAB_00509702:
  ptr5 = (int *)0x0;
  local_324 = (int *)0x0;
  if (uvalue6 == 0xffffffff) {
    *(short *)((intptr_t)this_00 + 0x16da) = *(short *)((intptr_t)this_00 + 0x16da) + 1;
  }
  else {
    ptr5 = (int *)local_320[uvalue6 * 2];
    ptr5[3] = local_320[uvalue6 * 2 + 1];
    ptr5[2] = *(int *)((intptr_t)self + 0x34);
    ptr5[4] = *(int *)((intptr_t)self + 0x164);
    local_324 = (int *)Branch_ProcessCustomerOrder(this_00,ptr5,1);
    if (local_324 == (int *)0x0) {
      *(short *)((intptr_t)this_00 + 0x16d4) = *(short *)((intptr_t)this_00 + 0x16d4) + 1;
    }
    else {
      Index_Map8To5((void *)*ptr5,*(int *)((intptr_t)self + 0x34));
      Stats_Increment2D(this_00,*(int *)((intptr_t)self + 0x34),*(uint32_t *)((intptr_t)self + 0x24) & 1);
      value4 = *(int *)((intptr_t)self + 0x34);
      uvalue6 = Game_GetTimeSegment((intptr_t)DAT_0057c670);
      value4 = uvalue6 + value4 * 9;
      *(int *)((intptr_t)this_00 + value4 * 4 + 0x44) = *(int *)((intptr_t)this_00 + value4 * 4 + 0x44) + 1;
      value4 = *(int *)((intptr_t)self + 0x144);
      local_330 = 0;
      if (0 < value4) {
        do {
          value3 = IDMap_Lookup((void *)((intptr_t)self + 0x130),local_330,(int *)0x0);
          if (*(int *)(value3 + 4) == 0xf) {
            value7 = *(int *)(value3 + 0x2c);
            value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value3 + 8));
            pvVar2 = (void *)IDMap_Lookup((void *)(value3 + 0x148),value7,(int *)0x0);
            if (((pvVar2 != (void *)0x0) && (pvVar2 != this_00)) &&
               (*(int *)((intptr_t)pvVar2 + 0x30) != *(int *)((intptr_t)this_00 + 0x30))) {
              value3 = *(int *)((intptr_t)this_00 + 0x30) + (*(int *)((intptr_t)self + 0x34) * 3 + 0x31b) * 2;
              *(int *)((intptr_t)pvVar2 + value3 * 4) = *(int *)((intptr_t)pvVar2 + value3 * 4) + 1;
              *(int *)((intptr_t)pvVar2 + *(int *)((intptr_t)self + 0x34) * 4 + 0x1364) =
                   *(int *)((intptr_t)pvVar2 + *(int *)((intptr_t)self + 0x34) * 4 + 0x1364) + 1;
              value3 = *(int *)((intptr_t)this_00 + 0x30);
              value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
              if (value3 == value7) {
                UI_AppendCommandIfActive
                          (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x22,1);
                MissionGoal_HandleEvent
                          (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x22,-1,-1);
              }
            }
          }
          local_330 = local_330 + 1;
        } while (local_330 < value4);
      }
      List_Node_Reset((intptr_t)self + 0x130);
      uvalue11 = Game_ComputeObjectDetails
                         (self,arg1,ptr5,1,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
      ptr5[3] = (intptr_t)uvalue11;
      value4 = Branch_ComputeBuildingRating
                        (this_00,(intptr_t)((uint64_t)uvalue11 >> 0x20),*(int *)((intptr_t)self + 0x34));
      value3 = Stats_GetAverage8(this_00,*(int *)((intptr_t)self + 0x34));
      value7 = Branch_GetMenuRating(this_00,*(int *)((intptr_t)self + 0x34));
      value8 = Rating_ComputeBuildingScore(this_00,*(int *)((intptr_t)self + 0x34));
      value4 = value3 + value7 + value4 + ptr5[3];
      value8 = ((intptr_t)(value4 + (value4 >> 0x1f & 3U)) >> 2) + value8;
      value4 = *(int *)((intptr_t)this_00 + 0x30);
      value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (((value4 == value3) && (0x4f < value8)) && (*(int *)((intptr_t)self + 0x30) == 7)) {
        Array_SearchSet(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac),6);
      }
      value4 = *(int *)((intptr_t)self + 0x30);
      if (((value4 != 0xb) && (value4 != 0xf)) && (value4 != 0x21)) {
        *(int *)((intptr_t)self + *(int *)((intptr_t)this_00 + 0x30) * 4 + 0x14c) =
             *(int *)((intptr_t)self + *(int *)((intptr_t)this_00 + 0x30) * 4 + 0x14c) + 1;
        *(int *)((intptr_t)self + *(int *)((intptr_t)this_00 + 0x30) * 4 + 0xac) = value8;
        value4 = *(int *)((intptr_t)this_00 + 0x30);
        value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
        if (value4 == value3) {
          UI_AppendCommandIfActive
                    (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x16,
                     *(int *)((intptr_t)self + 0x164));
          MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x16,-1,-1)
          ;
        }
      }
      Object_SyncChildState(self,(intptr_t)this_00,value8);
      Branch_ComputeBuildingRating
                (this_00,*(uint32_t *)((intptr_t)self + 0x34),*(uint32_t *)((intptr_t)self + 0x34));
      Branch_ComputeAdvisorTipId((intptr_t)self,extraout_EDX,this_00,(void *)*ptr5,value8);
      *ptr5 = 0;
      Game_AddRecordTo19C4(this_00,ptr5);
    }
  }
  if (0 < local_328) {
    ptr9 = local_320;
    do {
      ptr1 = (int *)*ptr9;
      if ((ptr1 != (int *)0x0) && (ptr1 != ptr5)) {
        Mem_Free(ptr1);
      }
      ptr9 = ptr9 + 2;
      local_328 = local_328 + -1;
    } while (local_328 != 0);
  }
  return (intptr_t)local_324;
}
