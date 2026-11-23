// RecipeEditorIngredients_Update: ported from Pizza Connection 2 at 0x49e940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49e940
#include "pc2_port.h"

void __cdecl RecipeEditorIngredients_Update(void *arg1)

{
  int value1;
  uint32_t *uptr2;
  int *ptr3;
  int *ptr4;
  int value5;
  double fVar6;
  uint64_t uvalue7;
  uint8_t local_20 [32];
  
                    /* Fills the edited recipe's ingredient list and totals. */
  value1 = 0;
  ptr4 = &DAT_0057cc40;
  ptr3 = (int *)((intptr_t)DAT_0057cda0 + 100);
  do {
    if (*ptr3 != 0) {
      *ptr4 = value1;
      ptr4 = ptr4 + 1;
    }
    value1 = value1 + 1;
    ptr3 = ptr3 + 1;
  } while (value1 < 0x56);
  DAT_0057cc3c = 0;
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,2,0x1f43);
  if (DAT_00568bdc == 0) {
    uvalue7 = 0x100001f44;
  }
  else {
    uvalue7 = 0x100001f43;
  }
  Window_GadgetNotify_Button_SetState(arg1,(intptr_t)uvalue7,(intptr_t)((uint64_t)uvalue7 >> 0x20));
  uptr2 = (uint32_t *)Game_CountActiveStats((intptr_t)DAT_0057cda0);
  Save_LoadOrInit2(uptr2);
  PlayerStats_Reset((intptr_t)DAT_0057cda0);
  value1 = Game_CountActiveStats((intptr_t)DAT_0057cda0);
  if (value1 == 0) {
    value1 = 0;
    do {
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568be0 + value1));
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568c0c + value1));
      value1 = value1 + 4;
    } while (value1 < 0x2c);
    UI_RemoveObjectByKey(arg1,0x428);
    UI_RemoveObjectByKey(arg1,0x440);
    UI_RemoveObjectByKey(arg1,0x4f0);
    UI_RemoveObjectByKey(arg1,0x507);
    UI_RemoveObjectByKey(arg1,0x452);
    UI_RemoveObjectByKey(arg1,0x1f41);
    UI_RemoveObjectByKey(arg1,0x1f42);
    UI_RemoveObjectByKey(arg1,0x1f43);
    UI_RemoveObjectByKey(arg1,0x1f44);
    value1 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x4e7,value1,0,0);
      value1 = value1 + 1;
    } while (value1 < 8);
    return;
  }
  value1 = 0;
  do {
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568be0 + value1));
    UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568c0c + value1));
    value1 = value1 + 4;
  } while (value1 < 0x2c);
  UI_ShowChildByID(arg1,0x428);
  UI_ShowChildByID(arg1,0x440);
  UI_ShowChildByID(arg1,0x4f0);
  UI_ShowChildByID(arg1,0x1f41);
  UI_ShowChildByID(arg1,0x1f42);
  UI_ShowChildByID(arg1,0x1f43);
  UI_ShowChildByID(arg1,0x1f44);
  if (*(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4) == 10) {
    UI_RemoveObjectByKey(arg1,0x507);
  }
  else {
    UI_ShowChildByID(arg1,0x507);
  }
  UI_ShowChildByID(arg1,0x452);
  value1 = Game_CountActiveStats((intptr_t)DAT_0057cda0);
  if (value1 < 0xc) {
    UI_RemoveObjectByKey(arg1,0x428);
    value1 = 0xb - value1;
    if (0 < value1) {
      value5 = 0;
      do {
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568c08 + value5));
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568c34 + value5));
        value5 = value5 + -4;
        value1 = value1 + -1;
      } while (value1 != 0);
    }
  }
  else {
    if (value1 < DAT_0057cc3c + 0xb) {
      DAT_0057cc3c = value1 + -0xb;
    }
    Window_GadgetNotify_Slider_SetRange(arg1,0x428,0,(value1 * 5 + -0x37) * 0x14,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x428,DAT_0057cc3c * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x428,1);
  }
  RecipePreview_FillNutritionRows(arg1,DAT_0057cc3c);
  fVar6 = Game_GetPlayerWeightedStat((intptr_t)DAT_0057cda0);
  String_Format(local_20,(uint8_t *)s__0_2f__005688b8,SUB84((double)fVar6,0));
  Window_GadgetNotify_Text_SetText(arg1,0x1f42,local_20);
  value1 = 0;
  do {
    value5 = Game_MapInputIndex(DAT_0057cda0,value1);
    Rating_UpdateBarByKey(arg1,0x4e7,value1,value5,DAT_0058155c);
    value1 = value1 + 1;
  } while (value1 < 8);
  return;
}
