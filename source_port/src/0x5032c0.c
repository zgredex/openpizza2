// MissionGoal_ApplyCompletionEffects: ported from Pizza Connection 2 at 0x5032c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5032c0
#include "pc2_port.h"

void __fastcall MissionGoal_ApplyCompletionEffects(int arg1)

{
  void *pvVar1;
  void *pvVar2;
  int value3;
  uint32_t *uptr4;
  int value5;
  int value6;
  int value7;
  int value8;
  int value9;
  int local_4;
  
                    /* Applies a mission goal's completion effects and increments counters. */
  value5 = *(int *)(arg1 + 0x50);
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
  case 0x10:
  case 0x13:
  case 0x17:
  case 0x19:
  case 0x1c:
  case 0x1d:
  case 0x21:
  case 0x25:
  case 0x26:
  case 0x31:
  case 0x32:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
    value6 = *(int *)(arg1 + 0x88 + value5 * 4);
    goto LAB_005039d0;
  case 4:
  case 0x30:
    *(uint32_t *)(arg1 + 0x88 + value5 * 4) = 0x30;
    break;
  case 9:
    Company_AddLedgerAmount
              (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               10000.0,0xffffffff,'\x01');
    break;
  case 10:
    Company_AddLedgerAmount
              (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               50000.0,0xffffffff,'\x01');
    break;
  case 0xb:
    Company_AddLedgerAmount
              (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               99999.0,1,'\0');
    break;
  case 0xc:
    *(uint32_t *)(arg1 + 0x88 + value5 * 4) = 4;
    break;
  case 0xf:
    value6 = *(int *)(arg1 + 0x88 + value5 * 4) + 0x30;
    goto LAB_005039d1;
  case 0x11:
    local_4 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value5 + 0x148),local_4,(int *)0x0);
        value8 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value3 = 0;
        if (0 < value8) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value3,(int *)0x0);
            pvVar1 = (void *)*uptr4;
            if (*(char *)((intptr_t)pvVar1 + 0x824) == '\x02') {
              value9 = (*(int *)((intptr_t)pvVar1 + 4) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetSkill(pvVar1,value9);
              value9 = (*(int *)((intptr_t)*uptr4 + 8) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetSpeed((void *)*uptr4,value9);
              value9 = (*(int *)((intptr_t)*uptr4 + 0xc) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetMotivation((void *)*uptr4,value9);
              value9 = (*(int *)((intptr_t)*uptr4 + 0x10) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetHealth((void *)*uptr4,value9);
            }
            value3 = value3 + 1;
          } while (value3 < value8);
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
        value8 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value3 = 0;
        if (0 < value8) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value3,(int *)0x0);
            pvVar1 = (void *)*uptr4;
            if (*(char *)((intptr_t)pvVar1 + 0x824) == '\0') {
              value9 = (*(int *)((intptr_t)pvVar1 + 4) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetSkill(pvVar1,value9);
              value9 = (*(int *)((intptr_t)*uptr4 + 8) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetSpeed((void *)*uptr4,value9);
              value9 = (*(int *)((intptr_t)*uptr4 + 0xc) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetMotivation((void *)*uptr4,value9);
              value9 = (*(int *)((intptr_t)*uptr4 + 0x10) * 0xb) / 10;
              if (100 < value9) {
                value9 = 100;
              }
              Person_SetHealth((void *)*uptr4,value9);
            }
            value3 = value3 + 1;
          } while (value3 < value8);
        }
        local_4 = local_4 + 1;
      } while (local_4 < value6);
    }
    break;
  case 0x14:
    value8 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value5 + 0x148),value8,(int *)0x0);
        value3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value9 = 0;
        if (0 < value3) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value9,(int *)0x0);
            Person_SetPerformance((void *)*uptr4,(*(int *)((intptr_t)*uptr4 + 0x3c) << 3) / 10);
            value9 = value9 + 1;
          } while (value9 < value3);
        }
        value8 = value8 + 1;
      } while (value8 < value6);
    }
    break;
  case 0x15:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2d:
  case 0x2e:
    value6 = *(int *)(arg1 + 0x88 + value5 * 4) + 5;
    goto LAB_005039d1;
  case 0x16:
    value6 = *(int *)(arg1 + 0x88 + value5 * 4) + 10;
    goto LAB_005039d1;
  case 0x18:
    *(int *)(arg1 + 0x88 + value5 * 4) = *(int *)(arg1 + 0x88 + value5 * 4) + 1;
    Company_InvalidateAllBranchRatings
              (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
    break;
  case 0x1a:
    value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    *(uint32_t *)(value5 + 0xd40 + value6 * 4) = 100;
    break;
  case 0x1b:
    value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    *(uint32_t *)(value5 + 0xc98 + value6 * 4) = 100;
    break;
  case 0x1e:
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value6 = 1;
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    City_AddRandomBuilding(pvVar2,value5,value6);
    break;
  case 0x1f:
    value8 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        value3 = IDMap_Lookup((void *)(value5 + 0x148),value8,(int *)0x0);
        if (*(int *)(value3 + 0x14b4) < 5) {
          *(int *)(value3 + 0x14b4) = *(int *)(value3 + 0x14b4) + 1;
        }
        value8 = value8 + 1;
      } while (value8 < value6);
    }
    if (*(void **)((intptr_t)DAT_0057c670 + 0x25c) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x18614,0x23,0);
    }
    break;
  case 0x20:
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value5 = 0;
    uptr4 = (uint32_t *)((intptr_t)pvVar2 + 0xcc8);
    do {
      Game_SetCompanyAdvancementScore(pvVar2,value5,0);
      *uptr4 = 0x3c;
      value5 = value5 + 1;
      uptr4 = uptr4 + 1;
    } while (value5 < 6);
    break;
  case 0x22:
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    Game_RecordPlayerStat(pvVar2,value5);
    break;
  case 0x23:
    value6 = *(int *)(arg1 + 0x88 + value5 * 4);
    if (value6 == 0) {
      value5 = Game_GetMostCommonTypeIndex
                        (*(int *)((intptr_t)DAT_0057c670 +
                                 *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      if (-1 < value5) {
        *(int *)(arg1 + 0x88 + *(int *)(arg1 + 0x50) * 4) = (value5 * 5 + 5) * 20000;
      }
      break;
    }
LAB_005039d0:
    value6 = value6 + 1;
LAB_005039d1:
    *(int *)(arg1 + 0x88 + value5 * 4) = value6;
    break;
  case 0x24:
    value8 = -1;
    value6 = 0x14;
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    Game_ApplyPercentChange(DAT_0057c670,value5,value6,value8);
    break;
  case 0x27:
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    Game_SelectRandomPlayerCompany(pvVar2,value5);
    break;
  case 0x28:
    value6 = 1;
    value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    City_SendResidentsToVenue(DAT_0057c670,(uint32_t *)0xa,value5,value6);
    break;
  case 0x2c:
    *(uint32_t *)(arg1 + 0x88 + value5 * 4) = 0x60;
    break;
  case 0x2f:
    value8 = 0;
    value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value6 = *(int *)(value5 + 0x15c);
    if (0 < value6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(value5 + 0x148),value8,(int *)0x0);
        value3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        value9 = 0;
        if (0 < value3) {
          do {
            uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x1500),value9,(int *)0x0);
            value7 = (*(int *)((intptr_t)*uptr4 + 0xc) * 0xc) / 10;
            if (100 < value7) {
              value7 = 100;
            }
            Person_SetMotivation((void *)*uptr4,value7);
            value9 = value9 + 1;
          } while (value9 < value3);
        }
        value8 = value8 + 1;
      } while (value8 < value6);
    }
  }
  value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  *(int *)(value5 + 0xfc) = *(int *)(value5 + 0xfc) + 1;
  value5 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                     *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  *(int *)(value5 + 0x2c) = *(int *)(value5 + 0x2c) + 1;
  if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18616,0x23,0);
  }
  return;
}
