// SubMenu_UpdateButtonStatesVariant1: ported from Pizza Connection 2 at 0x4cec60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cec60
#include "pc2_port.h"

void __cdecl SubMenu_UpdateButtonStatesVariant1(void *arg1)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  int value4;
  int value5;
  uint32_t uvalue6;
  
                    /* Updates the menu-mode-1 submenu button group. */
  value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x290) * 4 + 0x298);
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = *(int *)(value1 + 0xc20 + value2 * 4);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,9,0x3f4);
  Window_GadgetNotify_Button_SetState(arg1,0x3f4,(uint32_t)(value5 == 1));
  Array_ToggleObjectActive(arg1,0x3f4,(uint32_t)(value5 == 1));
  Window_GadgetNotify_Button_SetState(arg1,0x3fe,(uint32_t)(value5 == 2));
  Array_ToggleObjectActive(arg1,0x3fe,(uint32_t)(value5 == 2));
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  uptr3 = City_CollectBranchBuildings(value2);
  value2 = uptr3[5];
  if (uptr3 != (uint32_t *)0x0) {
    (**(code **)*uptr3)(1);
  }
  value4 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  uptr3 = City_CollectBusinessBuildings(value4);
  value4 = uptr3[5];
  if (uptr3 != (uint32_t *)0x0) {
    (**(code **)*uptr3)(1);
  }
  Window_GadgetNotify_Button_SetState(arg1,0x402,(uint32_t)(value5 == 0xb));
  Array_ToggleObjectActive(arg1,0x402,(uint32_t)(value5 == 0xb));
  UI_SetChildVisibleByID(arg1,0x402,(uint32_t)(0 < value2 + value4));
  Window_GadgetNotify_Button_SetState(arg1,0x401,(uint32_t)(value5 == 4));
  Array_ToggleObjectActive(arg1,0x401,(uint32_t)(value5 == 4));
  Window_GadgetNotify_Button_SetState(arg1,0x3f8,(uint32_t)(value5 == 5));
  Array_ToggleObjectActive(arg1,0x3f8,(uint32_t)(value5 == 5));
  uvalue6 = (uint32_t)(0 < value1);
  UI_SetChildVisibleByID(arg1,0x3f8,uvalue6);
  value1 = Game_GetPlayerFieldC20
                    (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  if (value1 < 3) {
    Window_GadgetNotify_Button_SetState(arg1,0x3f9,0);
    UI_RemoveObjectByKey(arg1,0x3f9);
  }
  else {
    Window_GadgetNotify_Button_SetState(arg1,0x3f9,(uint32_t)(value5 == 6));
    Array_ToggleObjectActive(arg1,0x3f9,(uint32_t)(value5 == 6));
    UI_SetChildVisibleByID(arg1,0x3f9,uvalue6);
  }
  uvalue6 = (uint32_t)(value5 == 10);
  Window_GadgetNotify_Button_SetState(arg1,0x3fd,uvalue6);
  Array_ToggleObjectActive(arg1,0x3fd,uvalue6);
  UI_SetChildVisibleByID(arg1,0x3fd,uvalue6);
  value1 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
  if (((value1 != 0) && (*(int *)(value1 + 4) == 0x10)) && (*(int *)(value1 + 0x38) == 0)) {
    value2 = *(int *)(value1 + 8);
    value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value2 == value4) {
      Window_GadgetNotify_Button_SetState(arg1,0x404,(uint32_t)(value5 == 7));
      Array_ToggleObjectActive(arg1,0x404,(uint32_t)(value5 == 7));
      UI_SetChildVisibleByID(arg1,0x404,1);
      value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 8));
      value1 = IDMap_Lookup((void *)(value2 + 0x180),*(int *)(value1 + 0x2c),(int *)0x0);
      Window_GadgetNotify_Button_SetState(arg1,0x403,(uint32_t)(value5 == 8));
      Array_ToggleObjectActive(arg1,0x403,(uint32_t)(value5 == 8));
      value5 = Get_Field2C(value1);
      UI_SetChildVisibleByID(arg1,0x403,(uint32_t)(value5 < 2));
      UI_SetChildVisibleByID(arg1,0x3fd,1);
      return;
    }
  }
  UI_EnsureChildInitialized(arg1,0x403);
  UI_SetChildVisibleByID(arg1,0x403,0);
  UI_EnsureChildInitialized(arg1,0x404);
  UI_SetChildVisibleByID(arg1,0x404,0);
  UI_SetChildVisibleByID(arg1,0x3fd,uvalue6);
  return;
}
