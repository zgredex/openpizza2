// AI_Action_AnnoyRival: ported from Pizza Connection 2 at 0x4fd610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fd610
#include "pc2_port.h"

/* WARNING: Switch with 1 destination removed at 0x004fd78e */

uint32_t __thiscall AI_Action_AnnoyRival(void *self,int arg1)

{
  int value1;
  void *pvVar2;
  int value3;
  uint32_t uvalue4;
  void *pvVar5;
  uint32_t unaff_EDI;
  char *cptr6;
  uint32_t uvalue7;
  uint8_t *bptr8;
  
                    /* Runs an AI annoyance/sabotage action against a rival. */
  value1 = Game_GetDateField0C((intptr_t)DAT_0057c670);
  if (value1 < *(int *)((intptr_t)self + arg1 * 0x168 + 0x48)) {
    return 1;
  }
  *(int *)((intptr_t)self + arg1 * 0x168 + 0x48) =
       (100 - *(short *)((intptr_t)self + arg1 * 0x168 + 0x130) >> 1) + 1 + value1;
  pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + arg1 * 0x168 + 0x40));
  value3 = Game_GetPlayerFieldC20((intptr_t)pvVar2);
  if (value3 == 0) {
    return 1;
  }
  if (*(int *)((intptr_t)self + arg1 * 0x168 + 0x11c) == -1) {
    uvalue4 = Game_GetPlayerFieldC20((intptr_t)pvVar2);
    uvalue4 = Random_RangeFast(1,uvalue4);
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x11c) = uvalue4;
    switch(uvalue4) {
    case 1:
      uvalue4 = _rand();
      *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120) = uvalue4 & 3;
      break;
    case 2:
    case 3:
    case 5:
      uvalue4 = _rand();
      *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120) = uvalue4 & 1;
      break;
    case 4:
      uvalue4 = _rand();
      if ((uvalue4 & 1) == 0) {
        value3 = _rand();
        *(int *)((intptr_t)self + arg1 * 0x168 + 0x120) = value3 % 3;
      }
      else {
        *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120) = 3;
      }
      break;
    case 6:
      *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120) = 0;
    }
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x124) = 0;
  }
  uvalue4 = 0;
  pvVar5 = (void *)Game_PickRandomIdleObject(self,arg1);
  if (pvVar5 == (void *)0x0) goto switchD_004fd863_switchD;
  switch(*(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x11c)) {
  case 1:
    uvalue4 = AI_TryTakeOverRivalBranch(pvVar2,arg1,pvVar5);
    goto LAB_004fd783;
  case 2:
    value3 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x120);
    if (value3 == 0) {
      uvalue4 = AI_SendGraffitiPunk(pvVar2,(intptr_t)pvVar5);
    }
    else {
      if (value3 != 1) break;
      uvalue4 = AI_SendTroublePunks(pvVar2,(intptr_t)pvVar5);
    }
    goto LAB_004fd783;
  case 3:
    value3 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x120);
    if (value3 == 0) {
      uvalue7 = 0x1b;
    }
    else {
      if (value3 != 1) break;
      uvalue7 = 0x1c;
    }
    goto LAB_004fd77a;
  case 4:
    switch(*(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120)) {
    case 0:
      uvalue7 = 0x1a;
      goto LAB_004fd77a;
    case 1:
      uvalue7 = 0x2d;
LAB_004fd77a:
      uvalue4 = AI_Annoy_HireHarasser(self,pvVar2,(intptr_t)pvVar5,uvalue7);
      break;
    case 2:
      uvalue4 = AI_Annoy_SendGangsterGroup(self,pvVar2,(intptr_t)pvVar5);
      break;
    case 3:
      uvalue4 = AI_StartAdvertisingCampaign(pvVar2,(intptr_t)pvVar5);
      break;
    default:
      goto switchD_004fd72f_default;
    }
LAB_004fd783:
    if (uvalue4 < 5) break;
    bptr8 = &DAT_00568310;
    goto LAB_004fd852;
  case 5:
    if (*(int *)((intptr_t)self + arg1 * 0x168 + 0x120) == 0) {
      AI_AssignBuilderToConstructionSite(pvVar2,pvVar5);
    }
    break;
  case 6:
    if (*(int *)((intptr_t)self + arg1 * 0x168 + 0x120) == 0) {
      AI_Annoy_SendThugsToHeadquarters(self,pvVar2,(intptr_t)pvVar5);
    }
  }
switchD_004fd72f_default:
  bptr8 = &DAT_005721cc;
LAB_004fd852:
  DebugConsole_Printf(DAT_0057c1e0,0xff00ff,bptr8,unaff_EDI);
  if (4 < uvalue4) {
switchD_004fd863_caseD_2:
    cptr6 = s_KI__KIAnnoy___Undefinied_return___00572194;
    uvalue7 = 0xc000;
LAB_004fd92c:
    DebugConsole_Printf(DAT_0057c1e0,uvalue7,(uint8_t *)cptr6,uvalue4);
    return 1;
  }
switchD_004fd863_switchD:
  switch(uvalue4) {
  default:
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x11c) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120) = 0xffffffff;
    *(int *)((intptr_t)self + arg1 * 0x168 + 0x48) = value1;
    return 3;
  case 1:
    Object_AdjustShortPercent(self,arg1,-3);
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x11c) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120) = 0xffffffff;
    return 1;
  case 2:
    goto switchD_004fd863_caseD_2;
  case 3:
    *(int *)((intptr_t)self + arg1 * 0x168 + 0x124) =
         *(int *)((intptr_t)self + arg1 * 0x168 + 0x124) + 1;
    uvalue4 = Random_RangeFast(0,10);
    if (*(int *)((intptr_t)self + arg1 * 0x168 + 0x124) <= (intptr_t)uvalue4) {
      *(int *)((intptr_t)self + arg1 * 0x168 + 0x48) = value1 + 1;
      return 1;
    }
    uvalue4 = 3;
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x11c) = 0xffffffff;
    cptr6 = s_Cancel_action_005721bc;
    *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x120) = 0xffffffff;
    uvalue7 = 0xff00ff;
    goto LAB_004fd92c;
  case 4:
    *(int *)((intptr_t)self + arg1 * 0x168 + 0x48) = value1 + 1;
    return 1;
  }
}
