// Game_SelectBuilding: ported from Pizza Connection 2 at 0x4a9320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a9320
#include "pc2_port.h"

void __cdecl Game_SelectBuilding(int arg1,int arg2)

{
  int value1;
  void *pvVar2;
  int value3;
  uint32_t uvalue4;
  
                    /* Selects a clicked building and opens the matching view. */
  if (*(int *)(arg1 + 4) == 0x19) {
    if (*(int *)((intptr_t)DAT_0057c670 + 0x2e4) != 0xc) {
      *(int *)((intptr_t)DAT_0057c670 + 0x218) = arg1;
      Game_CenterViewOnObject(arg1);
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2e4) = 0xc;
      pvVar2 = DAT_0057c670;
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2c4) = *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2a4);
      *(uint32_t *)((intptr_t)pvVar2 + 0x2a4) = 0xc;
      Game_SetViewMode(DAT_0057c670,3,0);
      value3 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
      if ((*(int *)(value3 + 0xd0) == 0) && (*(int *)(value3 + 0xd4) == 2)) {
        *(uint32_t *)(value3 + 0xd4) = 3;
        Mission_ShowObjectiveDialog(DAT_0057c670,'\0');
        return;
      }
    }
  }
  else {
    if ((*(int *)(arg1 + 4) == 0x1c) &&
       (value3 = *(int *)(arg1 + 8), value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670),
       value3 == value1)) {
      if (*(int *)((intptr_t)DAT_0057c670 + 0x2e4) == 10) {
        return;
      }
      *(int *)((intptr_t)DAT_0057c670 + 0x218) = arg1;
      pvVar2 = DAT_0057c670;
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x21c) = 0;
      *(uint32_t *)((intptr_t)pvVar2 + 0x2da8) = 1;
      Game_CenterViewOnObject(arg1);
      if ((char)arg2 == '\0') {
        *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2e4) = 10;
        pvVar2 = DAT_0057c670;
        *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2c0) = *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2a0);
        *(uint32_t *)((intptr_t)pvVar2 + 0x2a0) = 10;
        Game_SetViewMode(DAT_0057c670,2,0);
        return;
      }
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2e4) = 8;
      pvVar2 = DAT_0057c670;
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2c0) = *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2a0);
      *(uint32_t *)((intptr_t)pvVar2 + 0x2a0) = 8;
      Game_SetViewMode(DAT_0057c670,2,0);
      return;
    }
    if ((*(int *)(arg1 + 0x4c) != 0) && (*(int *)(arg1 + 8) == -1)) {
      *(int *)((intptr_t)DAT_0057c670 + 0x218) = arg1;
      pvVar2 = DAT_0057c670;
      *(uint32_t *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x2b8) =
           *(uint32_t *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298);
      *(uint32_t *)((intptr_t)pvVar2 + *(int *)((intptr_t)pvVar2 + 0x290) * 4 + 0x298) = 0xb;
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x260),-0x18621,0x23,0);
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x2e4) = 0;
      Game_DestroyRootWindow((intptr_t)DAT_0057c670);
      pvVar2 = SubMenu_BuildSelectedPage(DAT_0057c670,(int *)0x1);
      Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar2);
      return;
    }
    if (*(int *)(arg1 + 4) == 0x17) {
      value3 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (*(int *)(value3 + 0xc20 + value1 * 4) < 3) {
        uvalue4 = DAT_005829b4;
        goto LAB_004a95b1;
      }
    }
    if ((*(int *)(arg1 + 4) == 0x1b) && (*(int *)(arg1 + 8) == -1)) {
      value3 = Game_GetPlayerFieldC20
                        (*(int *)((intptr_t)DAT_0057c670 +
                                 *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      if (value3 < 2) {
        uvalue4 = DAT_005829b0;
LAB_004a95b1:
        Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_005825a4,uvalue4,0);
        return;
      }
      if (*(int *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                  0x15c) == 0) {
        Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_005825a4,DAT_0058191c,0);
        return;
      }
    }
    value3 = SubMenu_SetSelection(DAT_0057c670,arg1,0,0,0);
    if (value3 == 0xf) {
      value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 8));
      value1 = 0;
      if (0 < *(int *)(value3 + 0x15c)) {
        do {
          arg2 = IDMap_Lookup((void *)(value3 + 0x148),value1,(int *)0x0);
          if (*(int *)(arg2 + 0x16f0) == arg1) break;
          value1 = value1 + 1;
        } while (value1 < *(int *)(value3 + 0x15c));
      }
      *(int *)((intptr_t)DAT_0057c670 + 0x9c) = arg2;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
      Game_SetViewMode(DAT_0057c670,4,0);
    }
  }
  return;
}
