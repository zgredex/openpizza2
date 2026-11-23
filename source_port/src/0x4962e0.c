// CityBuildingListPage_Update: ported from Pizza Connection 2 at 0x4962e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4962e0
#include "pc2_port.h"


void __cdecl CityBuildingListPage_Update(void *arg1,char arg2)

{
  void *pvVar1;
  uint32_t uvalue2;
  int value3;
  int *ptr4;
  int value5;
  double fVar6;
  uint8_t *uptr7;
  uint8_t local_40 [64];
  
                    /* Updates the city building-list page and selection. */
  if (arg2 != '\0') {
    UI_Group_Create(arg1,0,4,0x4f8);
  }
  Window_GadgetNotify_Button_SetState(arg1,DAT_0057c708 + 0x4f8,1);
  value3 = 0;
  UI_SetPosition(arg1,&LAB_00495f80,0);
  pvVar1 = *(void **)(DAT_0057c670 + 0x9c);
  DAT_0057c700 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  DAT_0057c6f8 = 0;
  DAT_0057c704 = Game_CountActiveCompanies((intptr_t)DAT_0057c700);
  DAT_0057c70c = -1;
  City_RebuildBuildingSortIndexByMode();
  value5 = *(int *)(DAT_0057c670 + 0x98);
  if ((value5 != 0) && (*(char *)(value5 + 0x1dc) == '\x01')) {
    DAT_0057c70c = Game_GetActiveCompanyOrdinal(DAT_0057c700,value5);
  }
  ptr4 = &DAT_005687dc;
  value5 = 0x512;
  do {
    UI_ShowChildByID(arg1,value3 + 0x502);
    UI_ShowChildByID(arg1,value5);
    UI_ShowChildByID(arg1,*ptr4);
    value3 = value3 + 1;
    value5 = value5 + -1;
    ptr4 = ptr4 + 1;
  } while (0x50c < value5);
  UI_ShowChildByID(arg1,0x428);
  uvalue2 = *(uint32_t *)((intptr_t)pvVar1 + 0x14a8);
  Window_GadgetNotify_Slider_SetRange(arg1,0x42c,0,500,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x42c,uvalue2,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x42c,1);
  String_Format(local_40,(uint8_t *)s____d____005687f4,uvalue2);
  Window_GadgetNotify_Text_SetText(arg1,0x4f1,local_40);
  String_Format(local_40,&DAT_005683a4,*(uint32_t *)((intptr_t)pvVar1 + 0x14ac));
  Window_GadgetNotify_Text_SetText(arg1,0x1f43,local_40);
  UI_DisableButton(arg1,0x1f42);
  UI_DisableButton(arg1,0x1f44);
  value5 = *(int *)((intptr_t)pvVar1 + 0x14dc);
  if (value5 == 0) {
    Gadget_SetText(arg1,0x4f7,DAT_005822cc);
    uptr7 = DAT_00582e4c;
  }
  else {
    Gadget_SetText(arg1,0x4f7,value5 + 4);
    fVar6 = Branch_ComputeRecipePrice(value5,(intptr_t)pvVar1,-999);
    String_Format(local_40,(uint8_t *)s__0_2f_005685f4,SUB84((double)fVar6,0));
    uptr7 = local_40;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x51d,uptr7);
  if (DAT_0057c704 == 0) {
    value5 = 0;
    ptr4 = &DAT_005687dc;
    value3 = 0x512;
    do {
      UI_RemoveObjectByKey(arg1,value5 + 0x502);
      UI_RemoveObjectByKey(arg1,value3);
      UI_RemoveObjectByKey(arg1,*ptr4);
      value5 = value5 + 1;
      value3 = value3 + -1;
      ptr4 = ptr4 + 1;
    } while (0x50c < value3);
    UI_RemoveObjectByKey(arg1,0x428);
    value5 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x4e8,value5,0,0);
      value5 = value5 + 1;
    } while (value5 < 8);
    return;
  }
  if (DAT_0057c704 < 7) {
    UI_RemoveObjectByKey(arg1,0x428);
    value5 = 0;
    if (0 < 6 - DAT_0057c704) {
      value3 = 0x507;
      ptr4 = &DAT_005687f0;
      do {
        UI_RemoveObjectByKey(arg1,*ptr4);
        UI_RemoveObjectByKey(arg1,value5 + 0x50d);
        UI_RemoveObjectByKey(arg1,value3);
        value5 = value5 + 1;
        ptr4 = ptr4 + -1;
        value3 = value3 + -1;
      } while (value5 < 6 - DAT_0057c704);
    }
  }
  else {
    if (DAT_0057c70c != -1) {
      DAT_0057c6f8 = SaveList_FindIndex(DAT_0057c70c);
    }
    if (DAT_0057c704 < DAT_0057c6f8 + 6) {
      DAT_0057c6f8 = DAT_0057c704 + -6;
    }
    Window_GadgetNotify_Slider_SetRange(arg1,0x428,0,(DAT_0057c704 * 5 + -0x1e) * 0x14,0);
    Window_GadgetNotify_Slider_SetValue(arg1,0x428,DAT_0057c6f8 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x428,1);
  }
  CompareScreen_UpdateRows(arg1,DAT_0057c6f8,1000);
  CompareScreen_UpdateMenuRatingBars(arg1,pvVar1);
  return;
}
