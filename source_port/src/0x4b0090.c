// StatisticsBackdrop_InitCompanyRows: ported from Pizza Connection 2 at 0x4b0090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b0090
#include "pc2_port.h"


void __cdecl StatisticsBackdrop_InitCompanyRows(void *arg1)

{
  void *self;
  int value1;
  int value2;
  uint32_t unaff_EDI;
  int value3;
  char local_40 [64];
  
                    /* Builds the statistics backdrop company rows and chart. */
  self = arg1;
  Game_BuildPlayerRankingData(DAT_0057c670,&DAT_0057d66c);
  UI_SetPosition(arg1,&LAB_004b0000,0);
  if (DAT_0057d684 != 0) {
    UI_ReleaseRefCount(DAT_0057c5e0,DAT_0057d684);
  }
  DAT_0057d684 = UI_LoadFontByName(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  value3 = 0x401;
  arg1 = (void *)0x0;
  value2 = 0x3fa;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value2 + -0x3fa);
    if (value1 == 0) {
      UI_RemoveObjectByKey(self,value2);
      UI_RemoveObjectByKey(self,value3);
      UI_RemoveObjectByKey(self,value3 + 1);
      UI_RemoveObjectByKey(self,value3 + 2);
      UI_RemoveObjectByKey(self,*(int *)((intptr_t)arg1 + 0x56a654));
      (&DAT_0056a24a)[value2] = 0;
    }
    else {
      UI_ShowChildByID(self,value2);
      UI_ShowChildByID(self,value3);
      UI_ShowChildByID(self,value3 + 1);
      UI_ShowChildByID(self,value3 + 2);
      UI_ShowChildByID(self,*(int *)((intptr_t)arg1 + 0x56a654));
      String_Format(local_40,(uint8_t *)s_LOGOS__0_d_spr_00568eb8,*(int *)(value1 + 0x1e0) + 1);
      UI_SetButtonSpriteByName(self,*(int *)((intptr_t)arg1 + 0x56a654),local_40);
      Window_GadgetNotify_Text_SetText(self,value3,value1 + 8);
      Window_GadgetNotify_Button_SetState(self,value2,(uint32_t)(uint8_t)(&DAT_0056a24a)[value2]);
      String_Format(local_40,&DAT_005686f4,
                    *(uint32_t *)(*(int *)((intptr_t)arg1 + 0x57d66c) + 0x11c));
      Window_GadgetNotify_Text_SetText(self,value3 + 2,local_40);
      Window_GadgetNotify_Text_SetTextColor(self,value3,*(uint32_t *)(value1 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(self,value3 + 1,*(uint32_t *)(value1 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(self,value3 + 2,*(uint32_t *)(value1 + 0x1dc));
    }
    value3 = value3 + 3;
    arg1 = (void *)((intptr_t)arg1 + 4);
    value1 = value2 + -0x3f9;
    value2 = value2 + 1;
  } while (value1 < 6);
  Gadget_SetButtonState(self,0x1f41,1);
  String_Format(local_40,DAT_00582e4c,unaff_EDI);
  Window_GadgetNotify_Text_SetText(self,0x414,local_40);
  Window_GadgetNotify_Text_SetText(self,0x415,local_40);
  StatisticsBackdrop_DrawCompanyBarChart(self);
  StatisticsBackdrop_RestoreCategorySelection(self);
  return;
}
