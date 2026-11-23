// SubMenu_UpdateButtonStatesVariant2: ported from Pizza Connection 2 at 0x4cefe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cefe0
#include "pc2_port.h"

void __cdecl SubMenu_UpdateButtonStatesVariant2(void *arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t *uptr4;
  int value5;
  uint32_t uvalue6;
  
                    /* Updates the menu-mode-2 submenu button group. */
  value1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  value2 = *(int *)(value2 + 0xc20 + value3 * 4);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,10,0x3f4);
  Window_GadgetNotify_Button_SetState(arg1,0x3f4,(uint32_t)(value1 == 1));
  Array_ToggleObjectActive(arg1,0x3f4,(uint32_t)(value1 == 1));
  Window_GadgetNotify_Button_SetState(arg1,0x3fe,(uint32_t)(value1 == 2));
  Array_ToggleObjectActive(arg1,0x3fe,(uint32_t)(value1 == 2));
  value3 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  uptr4 = City_CollectBranchBuildings(value3);
  value3 = uptr4[5];
  if (uptr4 != (uint32_t *)0x0) {
    (**(code **)*uptr4)(1);
  }
  value5 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  uptr4 = City_CollectBusinessBuildings(value5);
  value5 = uptr4[5];
  if (uptr4 != (uint32_t *)0x0) {
    (**(code **)*uptr4)(1);
  }
  Window_GadgetNotify_Button_SetState(arg1,0x406,(uint32_t)(value1 == 0xb));
  Array_ToggleObjectActive(arg1,0x406,(uint32_t)(value1 == 0xb));
  UI_SetChildVisibleByID(arg1,0x406,(uint32_t)(0 < value3 + value5));
  Window_GadgetNotify_Button_SetState(arg1,0x400,(uint32_t)(value1 == 4));
  Array_ToggleObjectActive(arg1,0x400,(uint32_t)(value1 == 4));
  Window_GadgetNotify_Button_SetState(arg1,0x401,(uint32_t)(value1 == 5));
  Array_ToggleObjectActive(arg1,0x401,(uint32_t)(value1 == 5));
  UI_SetChildVisibleByID(arg1,0x401,(uint32_t)(0 < value2));
  value3 = Game_GetPlayerFieldC20
                    (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
  if (value3 < 3) {
    Window_GadgetNotify_Button_SetState(arg1,0x3f9,0);
    UI_RemoveObjectByKey(arg1,0x3f9);
  }
  else {
    Window_GadgetNotify_Button_SetState(arg1,0x3f9,(uint32_t)(value1 == 6));
    Array_ToggleObjectActive(arg1,0x3f9,(uint32_t)(value1 == 6));
    UI_SetChildVisibleByID(arg1,0x3f9,(uint32_t)(0 < value2));
  }
  if ((*(int *)(DAT_0057c670 + 0x218) == 0) ||
     (*(int *)(*(int *)(DAT_0057c670 + 0x218) + 4) != 0x1c)) {
    UI_SetChildVisibleByID(arg1,0x403,0);
    UI_SetChildVisibleByID(arg1,0x405,0);
    UI_SetChildVisibleByID(arg1,0x402,0);
    UI_SetChildVisibleByID(arg1,0x3fd,0);
    return;
  }
  Window_GadgetNotify_Button_SetState(arg1,0x403,(uint32_t)(value1 == 7));
  Array_ToggleObjectActive(arg1,0x403,(uint32_t)(value1 == 7));
  if (*(int *)(DAT_0057c670 + 0x2e4) == 0x14) {
    uvalue6 = 0;
  }
  else {
    uvalue6 = (uint32_t)(3 < value2);
  }
  UI_SetChildVisibleByID(arg1,0x403,uvalue6);
  Window_GadgetNotify_Button_SetState(arg1,0x405,(uint32_t)(value1 == 8));
  Array_ToggleObjectActive(arg1,0x405,(uint32_t)(value1 == 8));
  if (*(int *)(DAT_0057c670 + 0x2e4) == 0x14) {
    uvalue6 = 0;
  }
  else {
    uvalue6 = (uint32_t)(1 < value2);
  }
  UI_SetChildVisibleByID(arg1,0x405,uvalue6);
  Window_GadgetNotify_Button_SetState(arg1,0x402,(uint32_t)(value1 == 9));
  Array_ToggleObjectActive(arg1,0x402,(uint32_t)(value1 == 9));
  if ((*(int *)(DAT_0057c670 + 0x2e4) == 0x14) ||
     (*(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x1d8) == 0)) {
    uvalue6 = 0;
  }
  else {
    uvalue6 = (uint32_t)(value2 < 6);
  }
  UI_SetChildVisibleByID(arg1,0x402,uvalue6);
  Window_GadgetNotify_Button_SetState(arg1,0x3fd,(uint32_t)(value1 == 10));
  UI_SetChildVisibleByID(arg1,0x3fd,1);
  return;
}
