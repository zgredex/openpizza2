// RecipeKitchen_UpdateTabButtons: ported from Pizza Connection 2 at 0x4cfc80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cfc80
#include "pc2_port.h"

void __cdecl RecipeKitchen_UpdateTabButtons(void *arg1)

{
  int value1;
  void *self;
  int value2;
  int value3;
  uint32_t uvalue4;
  
                    /* Updates the recipe-kitchen panel's tab buttons. */
  value1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  value2 = *(int *)(value2 + 0xc20 + value3 * 4);
  value3 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x50);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,9,0x3f4);
  Window_GadgetNotify_Button_SetState(arg1,0x3f4,(uint32_t)(value1 == 1));
  Array_ToggleObjectActive(arg1,0x3f4,(uint32_t)(value1 == 1));
  Window_GadgetNotify_Button_SetState(arg1,0x3fe,(uint32_t)(value1 == 2));
  Array_ToggleObjectActive(arg1,0x3fe,(uint32_t)(value1 == 2));
  Window_GadgetNotify_Button_SetState(arg1,0x3ff,(uint32_t)(value1 == 3));
  Array_ToggleObjectActive(arg1,0x3ff,(uint32_t)(value1 == 3));
  Window_GadgetNotify_Button_SetState(arg1,0x400,(uint32_t)(value1 == 4));
  Array_ToggleObjectActive(arg1,0x400,(uint32_t)(value1 == 4));
  Window_GadgetNotify_Button_SetState(arg1,0x401,(uint32_t)(value1 == 5));
  Array_ToggleObjectActive(arg1,0x401,(uint32_t)(value1 == 5));
  UI_SetChildVisibleByID(arg1,0x401,(uint32_t)(0 < value2));
  Window_GadgetNotify_Button_SetState(arg1,0x403,(uint32_t)(value1 == 6));
  Array_ToggleObjectActive(arg1,0x403,(uint32_t)(value1 == 6));
  uvalue4 = (uint32_t)(0 < value3 + 1);
  UI_SetChildVisibleByID(arg1,0x403,uvalue4);
  Window_GadgetNotify_Button_SetState(arg1,0x404,(uint32_t)(value1 == 7));
  Array_ToggleObjectActive(arg1,0x404,(uint32_t)(value1 == 7));
  UI_SetChildVisibleByID(arg1,0x404,uvalue4);
  Window_GadgetNotify_Button_SetState(arg1,0x405,(uint32_t)(value1 == 8));
  Array_ToggleObjectActive(arg1,0x405,(uint32_t)(value1 == 8));
  UI_SetChildVisibleByID(arg1,0x405,uvalue4);
  uvalue4 = (uint32_t)(value1 == 10);
  Window_GadgetNotify_Button_SetState(arg1,0x402,uvalue4);
  Array_ToggleObjectActive(arg1,0x402,uvalue4);
  UI_SetChildVisibleByID(arg1,0x402,uvalue4);
  self = *(void **)(DAT_0057c670 + 0x25c);
  if (value1 != 10) {
    value2 = Game_FindCompanyIndex
                      (*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                       *(int *)(DAT_0057c670 + 0x98));
    if ((value2 == -1) && ((value1 < 6 || (8 < value1)))) {
      UI_QueueControlCommand(self,-0x18671,0x23,-1);
    }
  }
  if ((value1 == 2) || (value1 == 7)) {
    UI_SetChildLabelText(arg1,0x3f4,1,(char *)0x0);
    UI_SetChildLabelText(arg1,0x3fe,1,(char *)0x0);
    UI_SetChildLabelText(arg1,0x3ff,1,(char *)0x0);
    UI_SetChildLabelText(arg1,0x400,1,(char *)0x0);
    UI_SetChildLabelText(arg1,0x401,1,(char *)0x0);
    UI_SetChildLabelText(arg1,0x403,1,(char *)0x0);
    UI_SetChildLabelText(arg1,0x404,1,(char *)0x0);
    UI_SetChildLabelText(arg1,0x405,1,(char *)0x0);
    UI_ShowChildByID(self,0x42e);
    UI_ShowChildByID(self,0x42f);
    UI_ShowChildByID(self,0x430);
    Array_SetField14ByKey(self,0x43a,1);
    Array_SetField14ByKey(self,0x438,1);
    UI_SetChildLabelText(self,0x438,1,(char *)0x0);
    return;
  }
  UI_RemoveObjectByKey(self,0x42e);
  UI_RemoveObjectByKey(self,0x42f);
  UI_RemoveObjectByKey(self,0x430);
  Array_SetField14ByKey(self,0x43a,0);
  Array_SetField14ByKey(self,0x438,0);
  UI_SetChildLabelText(self,0x438,0,(char *)0x0);
  DAT_0057ca2c = 0;
  return;
}
