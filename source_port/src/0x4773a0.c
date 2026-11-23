// Branch_ProcessHour: ported from Pizza Connection 2 at 0x4773a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4773a0
#include "pc2_port.h"

void __thiscall Branch_ProcessHour(void *self,int arg1)

{
  char cVar1;
  int *ptr2;
  uint8_t uvalue3;
  uint32_t uvalue4;
  int value5;
  uint32_t extraout_var;
  void *pvVar6;
  uint32_t extraout_var_00;
  uint32_t *uptr7;
  int value8;
  int value9;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  uint32_t extraout_EDX_01;
  uint32_t extraout_EDX_02;
  uint32_t uvalue10;
  uint32_t unaff_ESI;
  uint64_t uvalue11;
  int local_8;
  
                    /* Runs a branch's hourly staff and construction tick. */
  uvalue4 = Game_GetTimeSegment((intptr_t)DAT_0057c670);
  if (arg1 % 3 == 0) {
    Branch_AdvanceWeekStatistics(self,arg1);
  }
  if (*(char *)((intptr_t)self + 0x16f5) == '\0') {
    cVar1 = *(char *)((intptr_t)self + 0x1a1f);
    value5 = 0x17;
    for (value9 = 0x1e; (cVar1 != '\0' && (0 < value9)); value9 = value9 + -1) {
      value5 = value5 + 1;
      if (0x17 < value5) {
        value5 = 0;
      }
      cVar1 = *(char *)(value5 + 0x1a08 + (intptr_t)self);
    }
    cVar1 = *(char *)(value5 + 0x1a08 + (intptr_t)self);
    while (cVar1 == '\0') {
      if (value9 < 1) goto LAB_00477452;
      value5 = value5 + 1;
      if (0x17 < value5) {
        value5 = 0;
      }
      value9 = value9 + -1;
      cVar1 = *(char *)(value5 + 0x1a08 + (intptr_t)self);
    }
    if ((0 < value9) && (value5 == arg1)) {
      uptr7 = (uint32_t *)((intptr_t)self + 0x1898);
      for (value5 = 0x10; value5 != 0; value5 = value5 + -1) {
        *uptr7 = 0;
        uptr7 = uptr7 + 1;
      }
      uptr7 = (uint32_t *)((intptr_t)self + 0x18d8);
      for (value5 = 0x30; value5 != 0; value5 = value5 + -1) {
        *uptr7 = 0;
        uptr7 = uptr7 + 1;
      }
    }
LAB_00477452:
    if (*(char *)(arg1 + 0x1a08 + (intptr_t)self) == '\0') {
      value5 = arg1 + 1;
      if (0x17 < value5) {
        value5 = 0;
      }
      if (*(char *)(value5 + 0x1a08 + (intptr_t)self) == '\0') {
        value5 = value5 + 1;
        if (0x17 < value5) {
          value5 = 0;
        }
        if (*(char *)(value5 + 0x1a08 + (intptr_t)self) == '\0') {
          Branch_ApplyProductSales(*(void **)((intptr_t)DAT_0057c670 + 0x90),self);
        }
      }
    }
    Branch_SpawnWalkInCustomer(self);
    Branch_UpdateActiveConstruction(self);
    uvalue3 = Game_GetHourlyValue(self,0);
    if (CONCAT31(extraout_var,uvalue3) == 0) {
      value5 = Game_FindMapRecordByTypeE((intptr_t)self);
      if ((value5 == 0) && (value5 = Get_Field19F4((intptr_t)self), 0 < value5)) {
        pvVar6 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                      *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
        City_SpawnPersonAtRandomCell(pvVar6,(intptr_t)self);
      }
    }
    else {
      uvalue3 = Game_GetHourlyValue(self,0);
      if ((CONCAT31(extraout_var_00,uvalue3) != 0) &&
         (value5 = Game_FindMapRecordByTypeE((intptr_t)self), value5 != 0)) {
        *(uint8_t *)(value5 + 0x81) = 1;
      }
    }
    value5 = *(int *)((intptr_t)self + 0x1514);
    local_8 = 0;
    if (0 < value5) {
      do {
        uptr7 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),local_8,(int *)0x0);
        ptr2 = (int *)*uptr7;
        if (ptr2 != (int *)0x0) {
          uvalue11 = Game_GetRecordByField814((intptr_t)ptr2);
          uvalue10 = (uint32_t)((uint64_t)uvalue11 >> 0x20);
          pvVar6 = (void *)uvalue11;
          value9 = uptr7[1];
          if (value9 != -1) {
            if (*(char *)((intptr_t)pvVar6 + 0x80) == '\0') {
              if ((*(char *)((intptr_t)pvVar6 + 0x104) != '\0') && (*(int *)((intptr_t)pvVar6 + 0x7c) == 0xff)
                 ) {
                Person_SetAtWork((intptr_t)pvVar6,uvalue10,0,'\x01');
                uvalue10 = extraout_EDX;
              }
              if (*(char *)((intptr_t)pvVar6 + 0x80) != '\0') goto LAB_0047758b;
LAB_0047768e:
              if (*(int *)((intptr_t)pvVar6 + 0x74) != 0) goto LAB_00477695;
            }
            else {
LAB_0047758b:
              if (*(int *)((intptr_t)pvVar6 + 0x7c) != 0xff) goto LAB_0047768e;
              if (*(int *)((intptr_t)pvVar6 + 0x74) == 0) {
                value8 = AI_IsDirectionOnRoute(self,ptr2,(arg1 + 2) / 3 & 7);
                uvalue10 = extraout_EDX_00;
                if (value8 != 0) {
                  if (*(int *)((intptr_t)pvVar6 + 0x108) != 1) {
                    Person_SetAtWork((intptr_t)pvVar6,extraout_EDX_00,(intptr_t)self,'\0');
                    Object_SetDestinationAndTarget(pvVar6,1,*(int *)((intptr_t)self + 0x16f0));
                    DebugConsole_Printf(DAT_0057c1e0,0xa000,(uint8_t *)s__s_geht_zur_Arbeit_00567bac,
                                        (intptr_t)pvVar6 + 4);
                    *(uint32_t *)((intptr_t)pvVar6 + 0x7c) = value9 + 3U & 7;
                    switch((char)ptr2[0x209]) {
                    case '\0':
                      Game_CanAfford(self,6,(float)ptr2[0xf],'\0',-1);
                      break;
                    case '\x01':
                      Game_CanAfford(self,8,(float)ptr2[0xf],'\0',-1);
                      break;
                    case '\x02':
                      Game_CanAfford(self,7,(float)ptr2[0xf],'\0',-1);
                      break;
                    case '\x03':
                      Game_CanAfford(self,0xd,(float)ptr2[0xf],'\0',-1);
                    }
                  }
                  goto switchD_00477623_default;
                }
                goto LAB_0047768e;
              }
LAB_00477695:
              value9 = AI_IsDirectionOnRoute(self,ptr2,uvalue4 & 7);
              uvalue10 = extraout_EDX_01;
              if (value9 == 0) {
                value9 = AI_IsDirectionOnRoute(self,ptr2,uvalue4 + 1 & 7);
                uvalue10 = extraout_EDX_02;
                if (value9 == 0) {
                  Person_SetAtWork((intptr_t)pvVar6,extraout_EDX_02,(intptr_t)self,'\x01');
                  uvalue10 = uvalue4 + 1 & 0x80000007;
                  if ((intptr_t)uvalue10 < 0) {
                    uvalue10 = (uvalue10 - 1 | 0xfffffff8) + 1;
                  }
                  *(uint32_t *)((intptr_t)pvVar6 + 0x7c) = uvalue10;
                  Sound_ProcessEventForSelectedObject
                            (DAT_0057ba0c,(intptr_t)self,*(int *)((intptr_t)pvVar6 + 0x30),5,
                             *(int *)((intptr_t)pvVar6 + 0x24) == 0);
                  goto switchD_00477623_default;
                }
              }
            }
            if (*(uint32_t *)((intptr_t)pvVar6 + 0x7c) == uvalue4) {
              if (*(char *)((intptr_t)pvVar6 + 0x80) == '\0') {
                Person_SetAtWork((intptr_t)pvVar6,uvalue10,(intptr_t)self,'\x01');
              }
              else if (*(uint32_t *)((intptr_t)pvVar6 + 0x7c) != uvalue4) goto switchD_00477623_default;
              *(uint32_t *)((intptr_t)pvVar6 + 0x7c) = 0xff;
            }
          }
        }
switchD_00477623_default:
        local_8 = local_8 + 1;
      } while (local_8 < value5);
    }
  }
  if (*(int *)((intptr_t)self + 0x187c) == 0) {
    *(uint32_t *)((intptr_t)self + 0x14bc) = 0;
  }
  else {
    *(int *)((intptr_t)self + 0x14bc) = *(int *)((intptr_t)self + 0x14bc) + 1;
  }
  value5 = Game_CountFreeResidentialBuildings((intptr_t)self);
  if (value5 == 0) {
    *(uint32_t *)((intptr_t)self + 0x14b8) = 0;
  }
  else {
    *(int *)((intptr_t)self + 0x14b8) = *(int *)((intptr_t)self + 0x14b8) + 1;
  }
  value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (*(int *)((intptr_t)self + 0x30) == value5) {
    if ((*(int *)((intptr_t)self + 0x14bc) == 0x18) &&
       (value5 = Game_HasQueuedEventType(DAT_0057c670,3), value5 == 0)) {
      value5 = UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,5,4,10,*(int *)((intptr_t)self + 0x16f0),
                                 DAT_00582944,DAT_00581ff0,unaff_ESI);
      Game_SetMessageField34(DAT_0057c670,value5,3);
    }
    if ((*(int *)((intptr_t)self + 0x14b8) == 0x18) &&
       (value5 = Game_HasQueuedEventType(DAT_0057c670,4), value5 == 0)) {
      value5 = UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,5,4,10,*(int *)((intptr_t)self + 0x16f0),
                                 DAT_0058112c,DAT_00580ee8,unaff_ESI);
      Game_SetMessageField34(DAT_0057c670,value5,4);
    }
  }
  Stats_ResetAverages(self);
  return;
}
