// RecipeRankingPanel_Update: ported from Pizza Connection 2 at 0x49bd90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49bd90
#include "pc2_port.h"


void __cdecl RecipeRankingPanel_Update(void *arg1,char arg2)

{
  void *self;
  uint32_t *uptr1;
  int value2;
  uint32_t unaff_EDI;
  int value3;
  
                    /* Fills the company recipe ranking popup and rating rows. */
  UI_SetPosition(arg1,&LAB_0049b4c0,0);
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uptr1 = (uint32_t *)Game_CountActiveCompanies((intptr_t)self);
  String_Format(&DAT_0057ca4c,DAT_00582e4c,unaff_EDI);
  DAT_0057ca90 = -1;
  Game_ResizeGlobalArray(uptr1);
  value2 = *(int *)(DAT_0057c670 + 0x98);
  if ((value2 != 0) && (*(char *)(value2 + 0x1dc) == '\x01')) {
    DAT_0057ca90 = Game_GetActiveCompanyOrdinal(self,value2);
  }
  UI_ShowChildByID(arg1,0x428);
  UI_ShowChildByID(arg1,0x50c);
  UI_ShowChildByID(arg1,0x50d);
  UI_ShowChildByID(arg1,0x504);
  UI_ShowChildByID(arg1,0x510);
  UI_ShowChildByID(arg1,0x50f);
  UI_ShowChildByID(arg1,0x454);
  value2 = 0x51b;
  value3 = 0;
  do {
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_005689f4 + value3));
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568a14 + value3));
    UI_ShowChildByID(arg1,value2);
    value3 = value3 + 4;
    value2 = value2 + -1;
  } while (0x513 < value2);
  value2 = 0;
  DAT_0057ca40 = (uint32_t *)0x0;
  UI_ShowChildByID(arg1,0x505);
  if (arg2 != '\0') {
    UI_Group_Create(arg1,0,2,0x50c);
  }
  if (uptr1 == (uint32_t *)0x0) {
    value3 = 0x51b;
    do {
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_005689f4 + value2));
      UI_RemoveObjectByKey(arg1,value3);
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568a14 + value2));
      value3 = value3 + -1;
      value2 = value2 + 4;
    } while (0x513 < value3);
    UI_RemoveObjectByKey(arg1,0x428);
    UI_RemoveObjectByKey(arg1,0x50c);
    UI_RemoveObjectByKey(arg1,0x50d);
    UI_RemoveObjectByKey(arg1,0x504);
    UI_RemoveObjectByKey(arg1,0x510);
    UI_RemoveObjectByKey(arg1,0x50f);
    UI_RemoveObjectByKey(arg1,0x454);
    value2 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x4f5,value2,0,0);
      value2 = value2 + 1;
    } while (value2 < 8);
  }
  else {
    if ((intptr_t)uptr1 < 9) {
      UI_RemoveObjectByKey(arg1,0x428);
      value3 = 0;
      if (0 < 8 - (intptr_t)uptr1) {
        do {
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568a10 + value2));
          UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568a30 + value2));
          UI_RemoveObjectByKey(arg1,value3 + 0x514);
          value3 = value3 + 1;
          value2 = value2 + -4;
        } while (value3 < 8 - (intptr_t)uptr1);
      }
    }
    else {
      if (DAT_0057ca90 != -1) {
        DAT_0057ca40 = (uint32_t *)GlobalArray_FindIndex(DAT_0057ca90,(intptr_t)uptr1);
      }
      if ((intptr_t)uptr1 < (intptr_t)(DAT_0057ca40 + 2)) {
        DAT_0057ca40 = uptr1 + -2;
      }
      Window_GadgetNotify_Slider_SetRange(arg1,0x428,0,((intptr_t)uptr1 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(arg1,0x428,(intptr_t)DAT_0057ca40 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x428,1);
    }
    if (DAT_005689f0 == '\0') {
      value2 = 0x50c;
    }
    else {
      value2 = 0x50d;
    }
    Window_GadgetNotify_Button_SetState(arg1,value2,1);
    RankingScreen_UpdateRows(arg1,(intptr_t)DAT_0057ca40);
  }
  if (*(int *)(DAT_0057c670 + 0x98) == 0) {
    value2 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x4f5,value2,0,0);
      value2 = value2 + 1;
    } while (value2 < 8);
    return;
  }
  value2 = 0;
  do {
    value3 = Game_ComputeAverageSkill(self,value2);
    Rating_UpdateBarByKey(arg1,0x4f5,value2,value3,DAT_0058271c);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
