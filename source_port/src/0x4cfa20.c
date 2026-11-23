// BranchScreen_UpdateTabButtons: ported from Pizza Connection 2 at 0x4cfa20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cfa20
#include "pc2_port.h"

void __cdecl BranchScreen_UpdateTabButtons(void *arg1)

{
  int value1;
  void *self;
  int value2;
  int value3;
  uint32_t uvalue4;
  
                    /* Updates the branch screen's nine tab buttons. */
  self = arg1;
  value1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  value2 = *(int *)(value2 + 0xc20 + value3 * 4);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,9,0x3f4);
  Window_GadgetNotify_Button_SetState(arg1,0x3f4,(uint32_t)(value1 == 1));
  Array_ToggleObjectActive(arg1,0x3f4,(uint32_t)(value1 == 1));
  Window_GadgetNotify_Button_SetState(arg1,0x3f5,(uint32_t)(value1 == 2));
  Array_ToggleObjectActive(arg1,0x3f5,(uint32_t)(value1 == 2));
  Window_GadgetNotify_Button_SetState(arg1,0x3f6,(uint32_t)(value1 == 3));
  Array_ToggleObjectActive(arg1,0x3f6,(uint32_t)(value1 == 3));
  Window_GadgetNotify_Button_SetState(arg1,0x3f7,(uint32_t)(value1 == 4));
  Array_ToggleObjectActive(arg1,0x3f7,(uint32_t)(value1 == 4));
  Window_GadgetNotify_Button_SetState(arg1,0x3fe,(uint32_t)(value1 == 5));
  Array_ToggleObjectActive(arg1,0x3fe,(uint32_t)(value1 == 5));
  UI_SetChildVisibleByID(arg1,0x3fe,(uint32_t)(0 < value2));
  Window_GadgetNotify_Button_SetState(arg1,0x3ff,(uint32_t)(value1 == 6));
  Array_ToggleObjectActive(arg1,0x3ff,(uint32_t)(value1 == 6));
  UI_SetChildVisibleByID(arg1,0x3ff,(uint32_t)(1 < value2));
  Window_GadgetNotify_Button_SetState(arg1,0x400,(uint32_t)(value1 == 7));
  Array_ToggleObjectActive(arg1,0x400,(uint32_t)(value1 == 7));
  UI_SetChildVisibleByID(arg1,0x400,(uint32_t)(3 < value2));
  if (*(void **)(DAT_0057c670 + 0x9c) == (void *)0x0) {
    arg1 = (void *)0x0;
  }
  else {
    arg1 = (void *)Game_CountObjectsByType(*(void **)(DAT_0057c670 + 0x9c),1);
  }
  Window_GadgetNotify_Button_SetState(self,0x401,(uint32_t)(value1 == 8));
  Array_ToggleObjectActive(self,0x401,(uint32_t)(value1 == 8));
  if ((value2 < 3) || ((intptr_t)arg1 < 1)) {
    value2 = 0;
  }
  else {
    value2 = 1;
  }
  UI_SetChildVisibleByID(self,0x401,value2);
  uvalue4 = (uint32_t)(value1 == 10);
  Window_GadgetNotify_Button_SetState(self,0x3fd,uvalue4);
  Array_ToggleObjectActive(self,0x3fd,uvalue4);
  UI_SetChildVisibleByID(self,0x3fd,uvalue4);
  return;
}
