// City_TickSimulation: ported from Pizza Connection 2 at 0x4d8d50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8d50
#include "pc2_port.h"


int __thiscall City_TickSimulation(void *self,int arg1)

{
  bool flag1;
  bool flag2;
  int value3;
  int *ptr4;
  void *pvVar5;
  int value6;
  int value7;
  void *pvVar8;
  uint32_t uvalue9;
  int *ptr10;
  uint32_t uvalue11;
  uint32_t *uptr12;
  uint32_t uvalue13;
  int value14;
  int *ptr15;
  uint32_t unaff_EDI;
  int64_t lvalue16;
  void *local_1c;
  uint32_t local_18;
  void *local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Advances the global city simulation tick. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005591cc;
  local_c = ExceptionList;
  value14 = 0;
  flag1 = false;
  ExceptionList = &local_c;
  if ((0 < *(int *)((intptr_t)self + 0x114c)) &&
     (value3 = *(int *)((intptr_t)self + 0x114c) + -1, ExceptionList = &local_c,
     *(int *)((intptr_t)self + 0x114c) = value3, value3 == 0)) {
    City_SettleAdvertisingCampaign((intptr_t)self);
    if (*(void **)((intptr_t)DAT_0057c670 + 0x25c) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x1860d,0x23,0);
    }
  }
  ptr10 = (int *)((intptr_t)self + 0xc98);
  ptr15 = (int *)((intptr_t)self + 0xc38);
  do {
    value3 = Game_GetPlayerBySlot(DAT_0057c670,value14);
    if (value3 != 0) {
      value3 = 4;
      ptr4 = ptr15;
      do {
        value6 = *ptr4;
        *ptr4 = value6 + 1;
        if (100 < value6 + 1) {
          *ptr4 = 100;
        }
        ptr4 = ptr4 + 1;
        value3 = value3 + -1;
      } while (value3 != 0);
      value3 = Game_GetPlayerBySlot(DAT_0057c670,value14);
      value3 = Game_GetPlayerCity(value3);
      value3 = *(int *)(value3 + 0x60) + *(int *)(value3 + 0x48);
      if (value3 < 0) {
        value3 = 0;
      }
      value6 = *ptr10;
      *ptr10 = value6 + value3;
      if (100 < value6 + value3) {
        *ptr10 = 100;
      }
      if (*ptr10 < 0) {
        *ptr10 = 0;
      }
    }
    value14 = value14 + 1;
    ptr10 = ptr10 + 1;
    ptr15 = ptr15 + 4;
  } while (value14 < 6);
  value14 = *(int *)((intptr_t)self + 0x10c0);
  if (value14 < 1) {
    *(int *)((intptr_t)self + 0x10c0) = value14 + 1;
    if (value14 + 1 == 0) {
      Weather_SelectRandomState((intptr_t)self);
      value14 = 0;
      if (0 < *(int *)((intptr_t)DAT_0057c670 + 0x50)) {
        do {
          pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),value14,(int *)0x0);
          value3 = State_Is2DOr2E((intptr_t)pvVar5);
          if ((value3 == 0) && (flag2 = Object_IsState10((intptr_t)pvVar5), flag2)) {
            Person_ClearCompletedAction(pvVar5);
          }
          value14 = value14 + 1;
        } while (value14 < *(int *)((intptr_t)DAT_0057c670 + 0x50));
      }
    }
  }
  else {
    *(int *)((intptr_t)self + 0x10c0) = value14 + -1;
    if (value14 + -1 == 0) {
      *(uint32_t *)((intptr_t)self + 0x10c0) = 0xfffffffa;
      City_ApplyCrimeWave((intptr_t)self);
    }
  }
  value14 = *(int *)((intptr_t)self + 0xfa8);
  local_1c = (void *)0x0;
  if (0 < *(int *)((intptr_t)self + 0xfc0)) {
    do {
      pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0xfac),(intptr_t)local_1c,(int *)0x0);
      value3 = *(int *)((intptr_t)pvVar5 + 8);
      if ((0 < *(int *)((intptr_t)pvVar5 + 0x38)) &&
         (value6 = *(int *)((intptr_t)pvVar5 + 0x38) + -1, *(int *)((intptr_t)pvVar5 + 0x38) = value6,
         value6 == 0)) {
        if ((*(int *)((intptr_t)DAT_0057c670 + 0x2d8) == 0x14) &&
           ((value6 = Game_GetActiveScreenOrFallback((intptr_t)DAT_0057c670), value6 != 0 &&
            (*(void **)((intptr_t)DAT_0057c670 + 0x218) == pvVar5)))) {
          Game_DestroyRootWindow((intptr_t)DAT_0057c670);
          *(uint32_t *)((intptr_t)DAT_0057c670 + 0x218) = 0;
          pvVar8 = DAT_0057c670;
          *(uint32_t *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x2b8) =
               *(uint32_t *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298);
          *(uint32_t *)((intptr_t)pvVar8 + *(int *)((intptr_t)pvVar8 + 0x290) * 4 + 0x298) = 1;
          local_1c = SubMenu_BuildSelectedPage(DAT_0057c670,(int *)0x0);
          Window_ShowWindowById(DAT_0057c5e0,(intptr_t)local_1c);
          pvVar8 = *(void **)((intptr_t)DAT_0057c670 + 0x260);
          Window_GadgetNotify_Button_SetState(pvVar8,0x3fd,0);
          Array_ToggleObjectActive(pvVar8,0x3fd,0);
          UI_SetChildVisibleByID(pvVar8,0x3fd,0);
        }
        value6 = *(int *)((intptr_t)pvVar5 + 8);
        value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
        if (value6 == value7) {
          Sound_PlaySpeechStatement(DAT_0057ba0c,0x16);
        }
        DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_Es_ist_ein_Haus_fertig_geworden__0056cda4,
                            unaff_EDI);
        switch(*(uint32_t *)((intptr_t)pvVar5 + 0x30)) {
        case 0xf:
          value6 = Game_GetPlayerBySlot(DAT_0057c670,value3);
          if (*(int *)((intptr_t)pvVar5 + 0x2c) == -1) {
            value7 = Player_CreateBranch(*(void **)((intptr_t)DAT_0057c670 + 0x90),
                                        *(int *)((intptr_t)self + 0xc1c),pvVar5,*(int *)(value6 + 0x4c),0,
                                        1);
            local_14 = (void *)IDMap_Lookup((void *)(value6 + 0x148),value7,(int *)0x0);
            if (local_14 != (void *)0x0) {
              lvalue16 = __ftol();
              *(int *)((intptr_t)local_14 + 0x14b0) = (intptr_t)lvalue16;
              value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
              if (value3 == value6) {
                MissionGoal_HandleEvent
                          (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x11,-1,-1);
              }
            }
            goto LAB_004d9383;
          }
          value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
          if (value3 == value7) {
            MissionGoal_HandleEvent
                      (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0xc,-1,-1);
          }
          local_14 = (void *)IDMap_Lookup((void *)(value6 + 0x148),*(int *)((intptr_t)pvVar5 + 0x2c),
                                          (int *)0x0);
          Branch_EndConstructionMode((intptr_t)local_14);
          Branch_RefreshConstructionButtons(local_14);
          if ((*(int *)((intptr_t)local_14 + 0x38) == 2) &&
             (value3 = *(int *)((intptr_t)local_14 + 0x30),
             value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670), value3 == value6)) {
            MissionGoal_HandleEvent
                      (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x10,-1,-1);
          }
          Game_TryBuyCompletedHouse(*(void **)((intptr_t)DAT_0057c670 + 0x90),local_14,0);
          flag1 = true;
          break;
        case 0x10:
          pvVar8 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value3);
          if (*(int *)((intptr_t)pvVar5 + 0x2c) == -1) {
            value6 = Player_BuildStorage(*(int *)((intptr_t)self + 0xc1c),pvVar5,value3,0,1);
            value6 = IDMap_Lookup((void *)((intptr_t)pvVar8 + 0x180),value6,(int *)0x0);
            *(uint8_t *)(value6 + 0x3c) = 1;
            value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
            if (value3 == value6) {
              MissionGoal_HandleEvent
                        (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0xe,-1,-1);
            }
          }
          else {
            value6 = Game_FindRecordByField34(pvVar8,(intptr_t)pvVar5);
            *(int *)(value6 + 0x2c) = *(int *)((intptr_t)pvVar5 + 0x34) + -0x834 >> 2;
            value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
            if (value3 == value6) {
              MissionGoal_HandleEvent
                        (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0xd,-1,-1);
            }
          }
          break;
        case 0x11:
          *(uint32_t *)((intptr_t)pvVar5 + 0xc) = *(uint32_t *)((intptr_t)self + 0x10c4);
          Player_SetSlotFlag18(self,*(int *)((intptr_t)self + 0x10c4));
          City_UpdateSecurityPatrolFrames(self,(intptr_t)pvVar5);
          *(int *)((intptr_t)self + 0x10c4) = *(int *)((intptr_t)self + 0x10c4) + 1;
          value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
          if (value3 == value6) {
            MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0,-1,-1);
          }
          break;
        default:
          Game_RedirectPersonDestination(DAT_0057c670,(intptr_t)pvVar5);
          break;
        case 0x1c:
          value6 = Game_GetPlayerBySlot(DAT_0057c670,value3);
          *(void **)(value6 + 0x1d8) = pvVar5;
          value6 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                               (int *)0x0);
          value6 = *(int *)(value6 + 0xc20 + value3 * 4);
          value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
          if (value3 == value7) {
            if (value6 == 0) {
              value6 = 2;
              pvVar8 = *(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
            }
            else {
              value6 = 1;
              pvVar8 = *(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
            }
            MissionGoal_HandleEvent(pvVar8,value6,-1,-1);
          }
          pvVar8 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                        *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
          Game_IncrementPlayerCounterC20(pvVar8,value3);
          value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
          if ((value3 == value6) && (*(void **)((intptr_t)DAT_0057c670 + 0x25c) != (void *)0x0)) {
            UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x18617,0x23,0);
          }
        }
        MapObject_SetTypeAndSprite(pvVar5,*(int *)((intptr_t)pvVar5 + 0x30),*(int *)((intptr_t)pvVar5 + 0x34))
        ;
        if (flag1) {
          Branch_RefreshConstructionButtons(local_14);
        }
        *(uint32_t *)(value14 + 0xf4) = 1;
      }
LAB_004d9383:
      local_1c = (void *)((intptr_t)local_1c + 1);
    } while ((intptr_t)local_1c < *(int *)((intptr_t)self + 0xfc0));
  }
  City_SpawnResidentInPreferredCity((intptr_t)self);
  value14 = *(int *)((intptr_t)self + 0x10cc) + -1;
  *(int *)((intptr_t)self + 0x10cc) = value14;
  *(int *)((intptr_t)self + 0x10c8) = *(int *)((intptr_t)self + 0x10c8) + -1;
  if (value14 < 1) {
    uvalue9 = Random_RangeFast(0x18,0x60);
    *(uint32_t *)((intptr_t)self + 0x10cc) = uvalue9;
    City_AddRandomBuilding(self,-1,0);
    value3 = 1;
    value14 = Game_GetMostAdvancedCompany((intptr_t)self);
    City_AddRandomBuilding(self,value14,value3);
    value3 = 1;
    value14 = Game_GetLowestValuePlayer((intptr_t)self);
    City_AddRandomBuilding(self,value14,value3);
    uvalue9 = Random_RangeFast(0,7);
    Array_MoveActiveSlotToRandom(self,uvalue9);
    Game_SelectRandomPlayerCompany(self,-1);
    Person_RefreshShopChoices(self);
  }
  if (*(int *)((intptr_t)self + 0x10c8) < 1) {
    uvalue9 = Random_RangeFast(0x30,0xc0);
    *(uint32_t *)((intptr_t)self + 0x10c8) = uvalue9;
    City_SendResidentsToVenue(DAT_0057c670,(uint32_t *)0xa,-1,0);
    Game_ShuffleProductMarketValues(self);
    NoOp_Stub();
  }
  local_18 = 0;
  do {
    value14 = Game_CountObjectsByType2(self,local_18);
    pvVar5 = (void *)(value14 + -10);
    local_1c = pvVar5;
    do {
      if ((intptr_t)pvVar5 < 1) break;
      value14 = *(int *)((intptr_t)self + 0xfdc);
      value3 = 0;
      if (0 < value14) {
        do {
          ptr10 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0xfc8),value3,(int *)0x0);
          value6 = *ptr10;
          if (*(uint8_t *)(value6 + 0x824) == local_18) {
            City_RemovePersonAndMaintainPopulation(self,value6);
            Mem_Free(ptr10);
            Person_RemoveFromStaff(value6);
            local_1c = (void *)((intptr_t)local_1c + -1);
            break;
          }
          value3 = value3 + 1;
        } while (value3 < value14);
        pvVar5 = local_1c;
      }
    } while (value3 != value14);
    local_18 = local_18 + 1;
  } while ((intptr_t)local_18 < 4);
  uvalue9 = 0;
  do {
    value14 = Game_CountObjectsByType2(self,uvalue9);
    if ((value14 < 10) && (uvalue11 = _rand(), (uvalue11 & 1) != 0)) {
      City_SpawnPerson(self,uvalue9);
    }
    uvalue9 = uvalue9 + 1;
  } while ((intptr_t)uvalue9 < 4);
  value14 = arg1 / 3;
  if (arg1 % 3 == 0) {
    value3 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
    value14 = Game_CountFreeSlots(DAT_0057c670,0x17);
    if (0 < value3 * 2 - value14) {
      pvVar5 = operator_new(0x16c);
      local_4 = 0;
      if (pvVar5 == (void *)0x0) {
        uptr12 = (uint32_t *)0x0;
      }
      else {
        uptr12 = Object_Construct(pvVar5,0x17,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      IDMap_GetRandomName(DAT_0057ba10,0,(char *)(uptr12 + 1));
      Game_AddObjectToRegistry(DAT_0057c670,uptr12);
    }
    value6 = 0;
    do {
      uvalue9 = Random_RangeFast(0,2);
      value6 = value6 + 1;
      if (uvalue9 == 0) {
        value14 = Game_CountFreeSlots(DAT_0057c670,0x1d);
        if (0 < value3 * 3 - value14) {
          pvVar5 = operator_new(0x16c);
          local_4 = 1;
          if (pvVar5 == (void *)0x0) {
            uptr12 = (uint32_t *)0x0;
          }
          else {
            uptr12 = Object_Construct(pvVar5,0x1d,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
          }
          uvalue13 = DAT_00582eec;
LAB_004d9722:
          value14 = uptr12[9];
LAB_004d972b:
          local_4 = 0xffffffff;
          Game_FormatObjectName(DAT_0057ba10,value14,(uint8_t *)(uptr12 + 1),uvalue13);
          value14 = Game_AddObjectToRegistry(DAT_0057c670,uptr12);
          ExceptionList = local_c;
          return value14;
        }
      }
      else if (uvalue9 == 1) {
        value14 = Game_CountFreeSlots(DAT_0057c670,0x1e);
        if (0 < value3 * 4 - value14) {
          pvVar5 = operator_new(0x16c);
          local_4 = 2;
          if (pvVar5 == (void *)0x0) {
            uptr12 = (uint32_t *)0x0;
          }
          else {
            uptr12 = Object_Construct(pvVar5,0x1e,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
          }
          value14 = uptr12[9];
          uvalue13 = DAT_00582dd0;
          goto LAB_004d972b;
        }
      }
      else {
        value14 = Game_CountFreeSlots(DAT_0057c670,0x1f);
        if (0 < value3 * 5 - value14) {
          pvVar5 = operator_new(0x16c);
          local_4 = 3;
          if (pvVar5 == (void *)0x0) {
            uptr12 = (uint32_t *)0x0;
            uvalue13 = DAT_00582418;
          }
          else {
            uptr12 = Object_Construct(pvVar5,0x1f,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
            uvalue13 = DAT_00582418;
          }
          goto LAB_004d9722;
        }
      }
    } while (value6 < 9);
  }
  ExceptionList = local_c;
  return value14;
}
