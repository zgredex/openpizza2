// RestaurantInfoPanel_UpdateTabButtons: ported from Pizza Connection 2 at 0x4cf690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cf690
#include "pc2_port.h"

void __cdecl RestaurantInfoPanel_UpdateTabButtons(void *arg1)

{
  uint32_t *uptr1;
  void *self;
  int value2;
  bool flag3;
  int value4;
  int value5;
  uint32_t uvalue6;
  
                    /* Updates the restaurant info panel's ten tab buttons. */
  flag3 = false;
  self = *(void **)(DAT_0057c670 + 0x9c);
  if ((*(int *)((intptr_t)self + 0x2c) != 0) || (*(char *)((intptr_t)self + 0x16f5) != '\0')) {
    uptr1 = (uint32_t *)(DAT_0057c670 + 0x2a8);
    *(uint32_t *)(DAT_0057c670 + 0x2c8) = *(uint32_t *)(DAT_0057c670 + 0x2a8);
    flag3 = true;
    *uptr1 = 9;
  }
  value2 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value5 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  value4 = *(int *)(value4 + 0xc20 + value5 * 4);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,10,0x3f4);
  Window_GadgetNotify_Button_SetState(arg1,0x3f4,(uint32_t)(value2 == 1));
  Array_ToggleObjectActive(arg1,0x3f4,(uint32_t)(value2 == 1));
  uvalue6 = (uint32_t)!flag3;
  UI_SetChildVisibleByID(arg1,0x3f4,uvalue6);
  if ((value2 == 2) || (value2 == 0xb)) {
    value5 = 1;
  }
  else {
    value5 = 0;
  }
  Window_GadgetNotify_Button_SetState(arg1,0x3f5,value5);
  if ((value2 == 2) || (value2 == 0xb)) {
    value5 = 1;
  }
  else {
    value5 = 0;
  }
  Array_ToggleObjectActive(arg1,0x3f5,value5);
  UI_SetChildVisibleByID(arg1,0x3f5,uvalue6);
  Window_GadgetNotify_Button_SetState(arg1,0x3f6,(uint32_t)(value2 == 3));
  Array_ToggleObjectActive(arg1,0x3f6,(uint32_t)(value2 == 3));
  UI_SetChildVisibleByID(arg1,0x3f6,uvalue6);
  Window_GadgetNotify_Button_SetState(arg1,0x3f7,(uint32_t)(value2 == 4));
  Array_ToggleObjectActive(arg1,0x3f7,(uint32_t)(value2 == 4));
  UI_SetChildVisibleByID(arg1,0x3f7,uvalue6);
  Window_GadgetNotify_Button_SetState(arg1,0x3f8,(uint32_t)(value2 == 5));
  Array_ToggleObjectActive(arg1,0x3f8,(uint32_t)(value2 == 5));
  if ((value4 < 1) || (flag3)) {
    value5 = 0;
  }
  else {
    value5 = 1;
  }
  UI_SetChildVisibleByID(arg1,0x3f8,value5);
  Window_GadgetNotify_Button_SetState(arg1,0x3f9,(uint32_t)(value2 == 6));
  Array_ToggleObjectActive(arg1,0x3f9,(uint32_t)(value2 == 6));
  if ((value4 < 1) || (flag3)) {
    value5 = 0;
  }
  else {
    value5 = 1;
  }
  UI_SetChildVisibleByID(arg1,0x3f9,value5);
  Window_GadgetNotify_Button_SetState(arg1,0x3fa,(uint32_t)(value2 == 7));
  Array_ToggleObjectActive(arg1,0x3fa,(uint32_t)(value2 == 7));
  if ((value4 < 1) || (flag3)) {
    value5 = 0;
  }
  else {
    value5 = 1;
  }
  UI_SetChildVisibleByID(arg1,0x3fa,value5);
  value5 = Game_CountObjectsByType(self,1);
  Window_GadgetNotify_Button_SetState(arg1,0x3fb,(uint32_t)(value2 == 8));
  Array_ToggleObjectActive(arg1,0x3fb,(uint32_t)(value2 == 8));
  if (((value4 < 3) || (flag3)) || (value5 < 1)) {
    value5 = 0;
  }
  else {
    value5 = 1;
  }
  UI_SetChildVisibleByID(arg1,0x3fb,value5);
  if (*(int *)((intptr_t)self + 0x38) < 2) {
    Window_GadgetNotify_Button_SetState(arg1,0x3fe,(uint32_t)(value2 == 9));
    Array_ToggleObjectActive(arg1,0x3fe,(uint32_t)(value2 == 9));
    UI_SetChildVisibleByID(arg1,0x3fe,(uint32_t)(0 < value4));
  }
  else {
    Window_GadgetNotify_Button_SetState(arg1,0x3fe,0);
    UI_RemoveObjectByKey(arg1,0x3fe);
  }
  uvalue6 = (uint32_t)(value2 == 10);
  Window_GadgetNotify_Button_SetState(arg1,0x3fd,uvalue6);
  Array_ToggleObjectActive(arg1,0x3fd,uvalue6);
  UI_SetChildVisibleByID(arg1,0x3fd,uvalue6);
  return;
}
