// MissionGoal_ApplyFailureEffects: ported from Pizza Connection 2 at 0x503b20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x503b20
#include "pc2_port.h"

void __fastcall MissionGoal_ApplyFailureEffects(int arg1)

{
  void *pvVar1;
  void *pvVar2;
  int value3;
  uint32_t *uptr4;
  int value5;
  int value6;
  int value7;
  int value8;
  int local_4;
  
                    /* Applies a mission goal's failure effects. */
  value5 = *(int *)(arg1 + 0x54);
  switch(value5) {
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
  case 8:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x13:
  case 0x17:
  case 0x19:
  case 0x1d:
  case 0x25:
  case 0x31:
  case 0x32:
  case 0x34:
  case 0x37:
  case 0x38:
    value6 = *(int *)(arg1 + 0x16c + value5 * 4);
    goto LAB_0050429c;
  case 4:
  case 0x30:
    *(uint32_t *)(arg1 + 0x16c + value5 * 4) = 0x30;
    break;
  case 9:
    Game_CanAffordWithCurrency
              (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               5000.0,'\0',(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
    break;
  case 10:
    Game_CanAffordWithCurrency
              (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               25000.0,'\0',(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
    break;
  case 0xb:
    Game_CanAffordWithCurrency
              (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               50000.0,'\0',(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
    break;
  case 0xc:
    Game_CanAffordWithCurrency
              (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               100000.0,'\0',(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
    break;
  case 0x10:
    value6 = *(int *)(arg1 + 0x16c + value5 * 4) + 0x30;
    goto LAB_0050429d;
  case 0x11:
    local_4 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value5 + 0x148),local_4,(int *)0x0);
        value7 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value3 = 0;
        if (0 < value7) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value3,(int *)0x0);
            pvVar1 = (void *)*uptr4;
            if (*(char *)((intptr_t)pvVar1 + 0x824) == '\x02') {
              Person_SetSkill(pvVar1,(*(int *)((intptr_t)pvVar1 + 4) * 0x5f) / 100);
              Person_SetSpeed((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 8) * 0x5f) / 100);
              Person_SetMotivation((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 0xc) * 0x5f) / 100);
              Person_SetHealth((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 0x10) * 0x5f) / 100);
            }
            value3 = value3 + 1;
          } while (value3 < value7);
        }
        local_4 = local_4 + 1;
      } while (local_4 < value6);
    }
    break;
  case 0x12:
    local_4 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value5 + 0x148),local_4,(int *)0x0);
        value7 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value3 = 0;
        if (0 < value7) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value3,(int *)0x0);
            pvVar1 = (void *)*uptr4;
            if (*(char *)((intptr_t)pvVar1 + 0x824) == '\0') {
              Person_SetSkill(pvVar1,(*(int *)((intptr_t)pvVar1 + 4) * 0x5f) / 100);
              Person_SetSpeed((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 8) * 0x5f) / 100);
              Person_SetMotivation((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 0xc) * 0x5f) / 100);
              Person_SetHealth((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 0x10) * 0x5f) / 100);
            }
            value3 = value3 + 1;
          } while (value3 < value7);
        }
        local_4 = local_4 + 1;
      } while (local_4 < value6);
    }
    break;
  case 0x14:
    value7 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value5 + 0x148),value7,(int *)0x0);
        value3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value8 = 0;
        if (0 < value3) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value8,(int *)0x0);
            Person_SetPerformance((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 0x3c) * 0xb) / 10);
            value8 = value8 + 1;
          } while (value8 < value3);
        }
        value7 = value7 + 1;
      } while (value7 < value6);
    }
    break;
  case 0x15:
  case 0x16:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2d:
  case 0x2e:
    value6 = *(int *)(arg1 + 0x16c + value5 * 4) + 5;
    goto LAB_0050429d;
  case 0x18:
    *(int *)(arg1 + 0x16c + value5 * 4) = *(int *)(arg1 + 0x16c + value5 * 4) + 1;
    Company_InvalidateAllBranchRatings
              (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
    break;
  case 0x1a:
    value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value5 = *(int *)(value5 + 0xd40 + value6 * 4);
    value6 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    *(int *)(value6 + 0xd40 + value7 * 4) = (value5 << 3) / 10;
    break;
  case 0x1b:
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    value5 = Game_GetPlayerSupplyScore(pvVar2,value5);
    value6 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    *(int *)(value6 + 0xc98 + value7 * 4) = (value5 << 3) / 10;
    break;
  case 0x1c:
    value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (0x19 < *(int *)(value5 + 0xcc8 + value6 * 4)) {
      value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      *(uint32_t *)(value5 + 0xcc8 + value6 * 4) = 0x19;
    }
    break;
  case 0x1e:
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value6 = 0;
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    City_AddRandomBuilding(pvVar2,value5,value6);
    break;
  case 0x1f:
    value7 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        value3 = IDMap_Lookup((void *)(value5 + 0x148),value7,(int *)0x0);
        if (0 < *(int *)(value3 + 0x14b4)) {
          *(int *)(value3 + 0x14b4) = *(int *)(value3 + 0x14b4) + -1;
        }
        value7 = value7 + 1;
      } while (value7 < value6);
    }
    if (*(void **)((intptr_t)DAT_0057c670 + 0x25c) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x18614,0x23,0);
    }
    break;
  case 0x22:
  case 0x27:
    value7 = 4;
    value6 = -0x28;
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    Game_ApplyPercentChange(DAT_0057c670,value5,value6,value7);
    value6 = 1;
    value5 = -0x28;
    goto LAB_0050418e;
  case 0x23:
    value6 = *(int *)(arg1 + 0x16c + value5 * 4);
    if (value6 == 0) {
      value5 = Game_GetMostCommonTypeIndex
                        (*(int *)((intptr_t)DAT_0057c670 +
                                 *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      if (-1 < value5) {
        *(int *)(arg1 + 0x16c + *(int *)(arg1 + 0x54) * 4) = (value5 * 5 + 5) * 20000;
      }
      break;
    }
LAB_0050429c:
    value6 = value6 + 1;
LAB_0050429d:
    *(int *)(arg1 + 0x16c + value5 * 4) = value6;
    break;
  case 0x24:
    value6 = -1;
    value5 = -0x14;
LAB_0050418e:
    value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    Game_ApplyPercentChange(DAT_0057c670,value7,value5,value6);
    break;
  case 0x28:
    value6 = -1;
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    City_SendResidentsToVenue(DAT_0057c670,(uint32_t *)0xa,value5,value6);
    break;
  case 0x2c:
    value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    *(uint32_t *)(value5 + 0xc98 + value6 * 4) = 0;
    break;
  case 0x2f:
    value7 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value5 + 0x148),value7,(int *)0x0);
        value3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value8 = 0;
        if (0 < value3) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value8,(int *)0x0);
            Person_SetMotivation((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 0xc) * 9) / 10);
            value8 = value8 + 1;
          } while (value8 < value3);
        }
        value7 = value7 + 1;
      } while (value7 < value6);
    }
  }
  value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  *(int *)(value5 + 0x100) = *(int *)(value5 + 0x100) + 1;
  value5 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                     *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  *(int *)(value5 + 0x2c) = *(int *)(value5 + 0x2c) + 1;
  if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18615,0x23,0);
  }
  return;
}
