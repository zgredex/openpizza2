// Company_ProcessHourlyTick: ported from Pizza Connection 2 at 0x4e0200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0200
#include "pc2_port.h"

void __thiscall Company_ProcessHourlyTick(void *self,int arg1)

{
  double dVar1;
  int value2;
  void *pvVar3;
  int value4;
  uint32_t uvalue5;
  int *ptr6;
  int value7;
  uint8_t *bptr8;
  void *pvVar9;
  int value10;
  uint32_t unaff_EDI;
  bool flag11;
  int64_t lvalue12;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_14;
  
                    /* Runs a company's hourly economy tick. */
  value2 = Game_GetPlayerCity((intptr_t)self);
  *(int *)(*(int *)(value2 + 4) + 0x40) = *(int *)(*(int *)(value2 + 4) + 0x40) + 1;
  Game_UpdateCompanyAccount(*(void **)((intptr_t)DAT_0057c670 + 0x90),(intptr_t)self);
  if (*(double *)((intptr_t)self + 0x108) < 0.0) {
    *(int *)((intptr_t)self + 0x1e8) = *(int *)((intptr_t)self + 0x1e8) + 1;
    Game_CanAffordWithCurrency
              (self,0x16,
               (float)-((double)*(double *)((intptr_t)self + 0x108) * (double)0.004000000189989805),
               '\0',0xffffffff);
    flag11 = self == *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)
    ;
    value2 = *(int *)((intptr_t)self + 0x1e8);
    if (value2 < 0x31) {
      if (value2 == 0x24) {
        if (!flag11) goto LAB_004e02f6;
        bptr8 = DAT_00582d80;
      }
      else {
        if ((value2 != 0x18) || (!flag11)) goto LAB_004e02f6;
        bptr8 = DAT_00582de4;
      }
      UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,5,-1,-1,0,DAT_00581fd8,bptr8,unaff_EDI);
    }
    else if (flag11) {
      UI_QueueChildCommand(DAT_0057c5e0,-0x18683,0);
    }
    else {
      AI_LiquidateBankruptCompany(*(void **)((intptr_t)DAT_0057c670 + 0x90),self);
    }
  }
LAB_004e02f6:
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if ((value2 == *(int *)((intptr_t)self + 0x48)) && (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 5)) {
    if ((*(uint8_t *)((intptr_t)self + 0x5c) & 0x10) != 0) {
      Company_OpenBranchInHomeCity(*(void **)((intptr_t)DAT_0057c670 + 0x90),*(int *)((intptr_t)self + 0x4c));
    }
    if ((*(uint8_t *)((intptr_t)self + 0x5c) & 0x20) != 0) {
      Game_AutoFillCompanyMenu(*(void **)((intptr_t)DAT_0057c670 + 0x90),*(int *)((intptr_t)self + 0x4c));
    }
  }
  ptr6 = (int *)((intptr_t)self + 0xcc);
  local_30 = 0;
  do {
    if (*(char *)((intptr_t)self + local_30 + 0xac) != '\0') {
      pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_30);
      value2 = ptr6[-0xe];
      Game_CanAffordWithCurrency(pvVar3,0x17,(float)value2 * 0.041666668,'\0',0xffffffff);
      Company_AddLedgerAmount(self,0x19,(float)value2 * 0.041666668,0xffffffff,'\0');
      *ptr6 = *ptr6 + 1;
      lvalue12 = __ftol();
      ptr6[-6] = ptr6[-6] + (intptr_t)lvalue12;
      value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (*(int *)((intptr_t)self + 0x48) == value2) {
        pvVar3 = *(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
        Array_SetSlot(pvVar3,0x1a,*(int *)((intptr_t)pvVar3 + 0x78) + (intptr_t)lvalue12);
      }
    }
    local_30 = local_30 + 1;
    ptr6 = ptr6 + 1;
  } while (local_30 < 6);
  flag11 = false;
  value2 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  local_2c = *(int *)(value2 + 0xec);
  local_28 = *(int *)(value2 + 0x1d0);
  value2 = *(int *)((intptr_t)self + 0x140);
  local_30 = 0;
  if (0 < value2) {
    do {
      pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 300),local_30,(int *)0x0);
      if (*(int *)((intptr_t)pvVar3 + 4) != 0) {
        GamePlan_SetActiveEffect(pvVar3,1,*(int *)((intptr_t)self + 0x48));
        value10 = *(int *)((intptr_t)pvVar3 + 8);
        pvVar9 = (void *)0x0;
        if (value10 == 1) {
          Game_CanAffordWithCurrency
                    (self,0xf,(float)*(int *)((intptr_t)pvVar3 + 0x20) * 0.041666668,'\0',0xffffffff);
          local_24 = *(int *)((intptr_t)self + 0x15c);
        }
        else if (value10 == 2) {
          local_24 = *(int *)((intptr_t)pvVar3 + 0x20);
          value10 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
          if (*(int *)((intptr_t)self + 0x48) == value10) {
            if (local_2c < 1) {
              if (0 < local_28) {
                local_24 = (local_24 * 0xf) / 10;
                local_28 = local_28 + -1;
              }
            }
            else {
              local_2c = local_2c + -1;
              local_24 = 0;
            }
          }
          pvVar9 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),*(int *)((intptr_t)pvVar3 + 0xc),
                                        (int *)0x0);
          Game_CanAfford(pvVar9,0x10,(float)local_24 * 0.041666668,'\0',-1);
          local_24 = 1;
        }
        else if (value10 == 3) {
          pvVar9 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),*(int *)((intptr_t)pvVar3 + 0xc),
                                        (int *)0x0);
          Game_CanAfford(pvVar9,0x11,(float)*(int *)((intptr_t)pvVar3 + 0x20) * 0.041666668,'\0',-1);
          local_24 = 2;
        }
        if (*(int *)((intptr_t)pvVar3 + 8) == 2) {
          dVar1 = (double)*(int *)((intptr_t)pvVar3 + 0x28);
          if (dVar1 < -10.0) {
            flag11 = true;
          }
          Value_Approach(*(void **)(*(int *)((intptr_t)pvVar9 + 0x16f0) + 0x74),
                         dVar1 * 0.027777777777777776,dVar1);
        }
        else if (*(int *)((intptr_t)pvVar3 + 8) == 1) {
          value10 = *(int *)((intptr_t)self + 0x15c);
          value7 = 0;
          if (0 < value10) {
            do {
              value4 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value7,(int *)0x0);
              dVar1 = (double)*(int *)((intptr_t)pvVar3 + 0x28);
              if (dVar1 < -10.0) {
                flag11 = true;
              }
              Value_Approach(*(void **)(*(int *)(value4 + 0x16f0) + 0x74),
                             dVar1 * 0.027777777777777776,dVar1);
              value7 = value7 + 1;
            } while (value7 < value10);
          }
          if ((arg1 % 3 == 0) && (0 < *(int *)((intptr_t)pvVar3 + 0x18))) {
            local_20 = 0;
            do {
              value10 = GamePlan_ComputeCategoryEffect(pvVar3,*(int *)((intptr_t)self + 0x48),local_20);
              if ((0x3c < value10) && (0 < local_24)) {
                local_14 = local_24;
                do {
                  uvalue5 = Random_RangeFast(1,100);
                  if ((intptr_t)uvalue5 < ((value10 * 5 + -300) * 5) / 10) {
                    value7 = *(int *)((intptr_t)pvVar3 + 0x18);
                    pvVar9 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
                    Player_TrackRecentEntry(pvVar9,local_20,value7 + -1);
                  }
                  local_14 = local_14 + -1;
                } while (local_14 != 0);
              }
              local_20 = local_20 + 1;
            } while (local_20 < 8);
          }
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < value2);
    if (((flag11) &&
        (value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670),
        *(int *)((intptr_t)self + 0x48) == value2)) &&
       (value2 = Game_HasQueuedEventType(DAT_0057c670,2), value2 == 0)) {
      value2 = UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,5,-1,-1,0,DAT_005825b8,DAT_00582860,unaff_EDI)
      ;
      Game_SetMessageField34(DAT_0057c670,value2,2);
    }
  }
  value2 = *(int *)((intptr_t)self + 0x15c);
  value10 = 0;
  if (0 < value2) {
    do {
      pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),value10,(int *)0x0);
      Branch_ProcessHour(pvVar3,arg1);
      Game_DecayCityDateBonus(*(int *)(*(int *)((intptr_t)pvVar3 + 0x16f0) + 0x74));
      value10 = value10 + 1;
    } while (value10 < value2);
  }
  value2 = *(int *)((intptr_t)self + 0x194);
  value10 = 0;
  if (0 < value2) {
    do {
      pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x180),value10,(int *)0x0);
      Game_DecayProductValues(pvVar3,arg1);
      value10 = value10 + 1;
    } while (value10 < value2);
  }
  value2 = *(int *)((intptr_t)self + 0x1cc);
  value10 = 0;
  if (0 < value2) {
    do {
      ptr6 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value10,(int *)0x0);
      if (ptr6[1] == 0x17) {
        value7 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*ptr6,(int *)0x0);
        *(int *)(value7 + 0xa8) = *(int *)(value7 + 0xa8) + 5;
        if (100 < *(int *)(value7 + 0xa8)) {
          *(uint32_t *)(value7 + 0xa8) = 100;
        }
      }
      value10 = value10 + 1;
    } while (value10 < value2);
  }
  return;
}
