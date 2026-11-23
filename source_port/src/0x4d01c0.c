// Screen_OptionsSidebar_SelectPage: ported from Pizza Connection 2 at 0x4d01c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d01c0
#include "pc2_port.h"

void __cdecl Screen_OptionsSidebar_SelectPage(void *arg1)

{
  int value1;
  
                    /* Rebuilds the options sidebar group and selects the active page button. */
  value1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,5,0x3f1);
  Window_GadgetNotify_Button_SetState(arg1,0x3f1,(uint32_t)(value1 == 1));
  Array_ToggleObjectActive(arg1,0x3f1,(uint32_t)(value1 == 1));
  Window_GadgetNotify_Button_SetState(arg1,0x3f4,(uint32_t)(value1 == 2));
  Array_ToggleObjectActive(arg1,0x3f4,(uint32_t)(value1 == 2));
  Window_GadgetNotify_Button_SetState(arg1,0x3f3,(uint32_t)(value1 == 3));
  Array_ToggleObjectActive(arg1,0x3f3,(uint32_t)(value1 == 3));
  Window_GadgetNotify_Button_SetState(arg1,0x3f0,(uint32_t)(value1 == 4));
  Array_ToggleObjectActive(arg1,0x3f0,(uint32_t)(value1 == 4));
  Window_GadgetNotify_Button_SetState(arg1,0x3f5,(uint32_t)(value1 == 5));
  Array_ToggleObjectActive(arg1,0x3f5,(uint32_t)(value1 == 5));
  return;
}
