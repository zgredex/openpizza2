// Game_LoadSaveGame: ported from Pizza Connection 2 at 0x488110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488110
#include "pc2_port.h"


uint32_t __thiscall Game_LoadSaveGame(void *self,int *arg1,uint32_t *arg2)

{
  void *pvVar1;
  uint32_t *uptr2;
  int value3;
  int value4;
  uint32_t uvalue5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Deserializes a full save game into the game object. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005582ad;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint32_t *)((intptr_t)self + 0x2e24) = 0;
  *arg2 = s_begin_005682e4;
  Game_ShutdownWorld((intptr_t)self);
  CRT_Istream_Read(arg1,&local_2c,0x20);
  if (local_10 != 0) {
    CRT_Istream_Read(arg1,&DAT_0057c668,4);
    *arg2 = s_version_conflict_005682d0;
    if (0x28 < DAT_0057c668) {
      *arg2 = s_gamedata_005682c4;
      CRT_Istream_Read(arg1,&DAT_0057bb20,0x5b8);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x298,0x20);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2b8,0x20);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2d8,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2dc,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2ec,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2f0,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2f4,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2e8,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2f8,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x33c,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x348,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x34c,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x350,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x344,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x354,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x340,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x364,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x368,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x360,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x358,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x35c,4);
      CRT_Istream_Read(arg1,(intptr_t)self + 0x2d90,4);
      IngredientPanel_Load(arg1);
      CityCompanyList_Load(arg1);
      AdvertisingPanel_Load(arg1);
      CompanyMarketShare_Load(arg1);
      CompanyOverview_Load(arg1);
      StatisticsBalance_Load(arg1);
      StatisticsBranchBalance_Load(arg1);
      Personnel_Load(arg1);
      BranchStats_SeriesFlags_Load(arg1);
      BranchDesign_ColorIndex_Load(arg1);
      BranchMenu_Category_Load(arg1);
      WarehouseProduct_Load(arg1);
      *(uint32_t *)((intptr_t)self + 0x2e24) = 1;
      GameCalendar_Load(*(void **)((intptr_t)self + 0x94),arg1);
      UI_BriefingList_Load((void *)((intptr_t)self + 0x304),arg1);
      World_LoadNameIndexTable(DAT_0057c5cc,arg1);
      CRT_Istream_Read(arg1,&local_3c,4);
      local_40 = 0;
      if (0 < local_3c) {
        do {
          CRT_Istream_Read(arg1,&local_38,4);
          pvVar1 = operator_new(0x10178);
          local_4 = 0;
          if (pvVar1 == (void *)0x0) {
            uptr2 = (uint32_t *)0x0;
          }
          else {
            uptr2 = IsoMap_ConstructFromStream(pvVar1,DAT_0057c5cc,arg1);
          }
          local_4 = 0xffffffff;
          Game_RegisterWorldObject(DAT_0057c5cc,uptr2,local_38);
          Game_UpdateLoadProgress(arg1,local_10);
          local_40 = local_40 + 1;
        } while (local_40 < local_3c);
      }
      *arg2 = s_Fehler_beim_Laden__Character__005682a0;
      value3 = Stream_GetReadPosition(arg1);
      if (((local_28 == value3) && (CRT_Istream_Read(arg1,&local_3c,4), local_3c < 1000000)) &&
         (-1 < local_3c)) {
        local_40 = 0;
        if (0 < local_3c) {
          do {
            CRT_Istream_Read(arg1,&local_38,4);
            pvVar1 = operator_new(0x828);
            local_4 = 1;
            if (pvVar1 == (void *)0x0) {
              uptr2 = (uint32_t *)0x0;
            }
            else {
              uptr2 = Character_StreamConstruct(pvVar1,arg1);
            }
            local_4 = 0xffffffff;
            IDMap_InsertGrow((void *)((intptr_t)self + 0x20),uptr2,local_38);
            if ((*(uint8_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) & 6) != 0) {
              ExceptionList = local_c;
              return 0;
            }
            Game_UpdateLoadProgress(arg1,local_10);
            local_40 = local_40 + 1;
          } while (local_40 < local_3c);
        }
        value3 = Stream_GetReadPosition(arg1);
        if (local_24 == value3) {
          *arg2 = s_Fehler_beim_Laden__City__00568284;
          CRT_Istream_Read(arg1,&local_3c,4);
          local_40 = 0;
          if (0 < local_3c) {
            do {
              pvVar1 = operator_new(0x1158);
              local_4 = 2;
              if (pvVar1 == (void *)0x0) {
                uptr2 = (uint32_t *)0x0;
              }
              else {
                uptr2 = City_Construct(pvVar1,arg1);
              }
              local_4 = 0xffffffff;
              List_Add((void *)((intptr_t)self + 4),uptr2);
              if ((*(uint8_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) & 6) != 0) {
                ExceptionList = local_c;
                return 0;
              }
              Game_UpdateLoadProgress(arg1,local_10);
              local_40 = local_40 + 1;
            } while (local_40 < local_3c);
          }
          value3 = Stream_GetReadPosition(arg1);
          if (local_2c == value3) {
            *arg2 = s_Fehler_beim_Laden__Person__00568264;
            CRT_Istream_Read(arg1,&local_3c,4);
            if ((local_3c < 0x186a1) && (-1 < local_3c)) {
              local_40 = 0;
              if (0 < local_3c) {
                do {
                  CRT_Istream_Read(arg1,&local_38,4);
                  pvVar1 = operator_new(0x16c);
                  local_4 = 3;
                  if (pvVar1 == (void *)0x0) {
                    uptr2 = (uint32_t *)0x0;
                  }
                  else {
                    uptr2 = Person_ConstructFromSave(pvVar1,arg1);
                  }
                  local_4 = 0xffffffff;
                  IDMap_InsertGrow((void *)((intptr_t)self + 0x3c),uptr2,local_38);
                  uptr2[0x59] = local_38;
                  if ((*(uint8_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) & 6) != 0) {
                    ExceptionList = local_c;
                    return 0;
                  }
                  Game_UpdateLoadProgress(arg1,local_10);
                  local_40 = local_40 + 1;
                } while (local_40 < local_3c);
              }
              value3 = Stream_GetReadPosition(arg1);
              if (local_14 == value3) {
                *arg2 = s_Fehler_beim_Laden__Car__00568248;
                CRT_Istream_Read(arg1,&local_3c,4);
                if ((local_3c < 0x186a1) && (-1 < local_3c)) {
                  local_40 = 0;
                  if (0 < local_3c) {
                    do {
                      CRT_Istream_Read(arg1,&local_38,4);
                      pvVar1 = operator_new(0x14);
                      local_4 = 4;
                      if (pvVar1 == (void *)0x0) {
                        uptr2 = (uint32_t *)0x0;
                      }
                      else {
                        uptr2 = Car_ConstructFromSave(pvVar1,arg1);
                      }
                      local_4 = 0xffffffff;
                      IDMap_InsertGrow((void *)((intptr_t)self + 0x58),uptr2,local_38);
                      if ((*(uint8_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) & 6) != 0) {
                        ExceptionList = local_c;
                        return 0;
                      }
                      local_40 = local_40 + 1;
                    } while (local_40 < local_3c);
                  }
                  Game_UpdateLoadProgress(arg1,local_10);
                  value3 = Stream_GetReadPosition(arg1);
                  if (local_1c == value3) {
                    *arg2 = s_Player_00568240;
                    local_40 = 0;
                    do {
                      CRT_Istream_Read(arg1,&local_34,4);
                      if (local_34 == 0) {
                        *(uint32_t *)((intptr_t)self + local_40 * 4 + 0x224) = 0;
                      }
                      else {
                        pvVar1 = operator_new(0xb0);
                        local_4 = 5;
                        if (pvVar1 == (void *)0x0) {
                          uptr2 = (uint32_t *)0x0;
                        }
                        else {
                          uptr2 = Player_Construct(pvVar1,arg1);
                        }
                        local_4 = 0xffffffff;
                        *(uint32_t **)((intptr_t)self + local_40 * 4 + 0x224) = uptr2;
                      }
                      if ((*(uint8_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) & 6) != 0) {
                        ExceptionList = local_c;
                        return 0;
                      }
                      Game_UpdateLoadProgress(arg1,local_10);
                      local_40 = local_40 + 1;
                    } while (local_40 < 6);
                    value3 = Stream_GetReadPosition(arg1);
                    if (local_20 == value3) {
                      local_40 = 0;
                      *arg2 = s_Fehler_beim_Laden__Company__00568220;
                      do {
                        CRT_Istream_Read(arg1,&local_34,4);
                        if (local_34 == 1) {
                          pvVar1 = operator_new(0x1f0);
                          local_4 = 6;
                          if (pvVar1 == (void *)0x0) {
                            uptr2 = (uint32_t *)0x0;
                          }
                          else {
                            uptr2 = Company_Construct(pvVar1,arg1);
                          }
                          local_4 = 0xffffffff;
                          *(uint32_t **)((intptr_t)self + local_40 * 4 + 0x200) = uptr2;
                        }
                        else {
                          *(uint32_t *)((intptr_t)self + local_40 * 4 + 0x200) = 0;
                        }
                        if ((*(uint8_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) & 6) != 0) {
                          ExceptionList = local_c;
                          return 0;
                        }
                        Game_UpdateLoadProgress(arg1,local_10);
                        local_40 = local_40 + 1;
                      } while (local_40 < 6);
                      *arg2 = s_Fehler_beim_Laden__Ki__00568204;
                      AI_CompanySlots_Load(*(void **)((intptr_t)self + 0x90),arg1);
                      CRT_Istream_Read(arg1,&local_38,4);
                      if (local_38 == 1) {
                        CRT_Istream_Read(arg1,&local_38,4);
                        CRT_Istream_Read(arg1,&local_40,4);
                        value3 = local_40;
                        value4 = Game_GetPlayerBySlot(self,local_38);
                        uvalue5 = IDMap_Lookup((void *)(value4 + 0x148),value3,(int *)0x0);
                        *(uint32_t *)((intptr_t)self + 0x9c) = uvalue5;
                      }
                      else {
                        *(uint32_t *)((intptr_t)self + 0x9c) = 0;
                      }
                      SaveGame_DeserializeRuntimeList(self,arg1);
                      CRT_Istream_Read(arg1,&local_30,4);
                      Game_UpdateLoadProgress(arg1,local_10);
                      if (local_30 == 0x2a) {
                        local_40 = 0;
                        do {
                          value3 = Game_GetPlayerBySlot(self,local_40);
                          if (value3 != 0) {
                            value4 = 0;
                            if (0 < *(int *)(value3 + 0x15c)) {
                              do {
                                pvVar1 = (void *)IDMap_Lookup((void *)(value3 + 0x148),value4,
                                                              (int *)0x0);
                                MapObject_RestoreSignLogoAnimations((intptr_t)pvVar1);
                                Game_ClearObjectFlag20((intptr_t)pvVar1);
                                Game_ToggleObjectFlag2(pvVar1);
                                Game_UpdateObjectList2((intptr_t)pvVar1);
                                Game_CheckObjectUpgrade(pvVar1);
                                Stats_ResetAverages(pvVar1);
                                value4 = value4 + 1;
                              } while (value4 < *(int *)(value3 + 0x15c));
                            }
                            Player_RestorePlanTargetAnimations(value3);
                          }
                          local_40 = local_40 + 1;
                        } while (local_40 < 6);
                        if (*(int *)(*(int *)(*(int *)((intptr_t)self + 0x224) + 0xac) + 0xd0) == 0) {
                          Mission_ShowObjectiveDialog(self,'\x01');
                        }
                        else {
                          Game_DestroyEventWindow((intptr_t)self);
                        }
                        Game_InitPlayerSlotTables(*(int *)((intptr_t)self + 0x90));
                        Sound_InitSpeechVoice(DAT_0057ba0c);
                        Map_RefreshObjectSprites((intptr_t)self);
                        Map_DrawMinimap(self);
                        value3 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                             (int *)0x0);
                        Game_RebuildLocalRecordOwners(value3);
                        ExceptionList = local_c;
                        return 1;
                      }
                      *arg2 = s_Fehler_beim_Laden__wrong_file_si_005681dc;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}
