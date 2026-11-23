// SubMenu_UpdateMenuPlanPage: ported from Pizza Connection 2 at 0x4a6c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a6c20
#include "pc2_port.h"

void __cdecl SubMenu_UpdateMenuPlanPage(void *arg1)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  int *ptr4;
  int value5;
  int value6;
  int64_t lvalue7;
  uint32_t uvalue8;
  int *local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120 [8];
  char local_100 [256];
  
                    /* Updates the menu-plan page's groups, sliders, and recipe panels. */
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  value5 = 0;
  value6 = 0;
  ptr4 = local_120;
  do {
    value2 = Game_CountObjectsByState(DAT_0057c670,value6);
    value5 = value5 + value2;
    *ptr4 = value2;
    value6 = value6 + 1;
    ptr4 = ptr4 + 1;
  } while (value6 < 8);
  value6 = 0;
  ptr4 = local_120;
  do {
    String_Format(local_100,&DAT_005686f4,(*ptr4 * 100) / value5);
    Window_GadgetNotify_Text_SetText(arg1,value6 + 0x452,local_100);
    value6 = value6 + 1;
    ptr4 = ptr4 + 1;
  } while (value6 < 8);
  uvalue8 = 0;
  lvalue7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x432,(intptr_t)lvalue7,uvalue8);
  uvalue8 = 0;
  lvalue7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x431,(intptr_t)lvalue7,uvalue8);
  uvalue8 = 0;
  lvalue7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x42f,(intptr_t)lvalue7,uvalue8);
  uvalue8 = 0;
  lvalue7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x435,(intptr_t)lvalue7,uvalue8);
  uvalue8 = 0;
  lvalue7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x434,(intptr_t)lvalue7,uvalue8);
  uvalue8 = 0;
  lvalue7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x433,(intptr_t)lvalue7,uvalue8);
  value5 = 0x437;
  do {
    UI_RemoveObjectByKey(arg1,value5);
    value5 = value5 + 1;
  } while (value5 < 0x449);
  ptr4 = (int *)(value1 + 200);
  value5 = 0;
  do {
    if (*ptr4 == 0) {
      value6 = *(int *)((intptr_t)&DAT_0056918c + value5);
    }
    else if (*ptr4 == 1) {
      value6 = *(int *)(value5 + 0x5691a4);
    }
    else {
      value6 = *(int *)(value5 + 0x5691bc);
    }
    UI_ShowChildByID(arg1,value6);
    value5 = value5 + 4;
    ptr4 = ptr4 + 1;
  } while (value5 < 0x18);
  local_12c = 200000;
  local_130 = &DAT_005691d4;
  ptr4 = (int *)(value1 + 0xfe4);
  while( true ) {
    UI_GetWindowObject(arg1,*local_130);
    Array_GetPairByKey(arg1,*local_130,&local_124,&local_128);
    value5 = 0;
    value1 = local_12c + 6;
    do {
      String_Format(local_100,(uint8_t *)s_zutaten_zmi__02d_a_spr_005691f4,*ptr4 + 1);
      UI_AddSprite(arg1,local_12c,local_124 + value5,local_128,local_100);
      UI_SetObjectTextByKey(arg1,local_12c,(char *)(&DAT_00583544)[*ptr4]);
      value5 = value5 + 0x15;
      local_12c = local_12c + 1;
      ptr4 = ptr4 + 1;
    } while (value5 < 0x7e);
    local_130 = local_130 + 1;
    if (0x5691f3 < (intptr_t)local_130) break;
    local_12c = value1;
  }
  uptr3 = City_CollectVacantLots((intptr_t)DAT_0057c670);
  Gadget_SetTextf(arg1,0x1f4b,&DAT_005686f4,uptr3[5]);
  if (uptr3 != (uint32_t *)0x0) {
    (**(code **)*uptr3)(1);
  }
  UI_SetObjectTextByKey(arg1,0x1f4d,DAT_005822c8);
  UI_SetObjectTextByKey(arg1,0x1f50,DAT_0058235c);
  UI_SetObjectTextByKey(arg1,0x1f4f,DAT_00582344);
  UI_SetObjectTextByKey(arg1,0x1f4e,DAT_00582334);
  UI_SetObjectTextByKey(arg1,0x1f52,DAT_00582318);
  UI_SetObjectTextByKey(arg1,0x1f4c,DAT_00582488);
  UI_SetObjectTextByKey(arg1,0x1f53,DAT_00582480);
  UI_SetObjectTextByKey(arg1,0x1f51,DAT_00582478);
  return;
}
