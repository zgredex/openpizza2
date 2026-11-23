// UI_InfoPanelBranch_InitTabStates: ported from Pizza Connection 2 at 0x4d0040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d0040
#include "pc2_port.h"

void __cdecl UI_InfoPanelBranch_InitTabStates(void *arg1)

{
  int value1;
  int value2;
  int value3;
  
                    /* Sets the branch info-panel tab states. */
  value1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  value2 = *(int *)(value2 + 0xc20 + value3 * 4);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,6,0x3ec);
  Window_GadgetNotify_Button_SetState(arg1,0x3ec,(uint32_t)(value1 == 5));
  Array_ToggleObjectActive(arg1,0x3ec,(uint32_t)(value1 == 5));
  UI_SetChildVisibleByID(arg1,0x3ec,(uint32_t)(0 < value2));
  Window_GadgetNotify_Button_SetState(arg1,0x3e9,(uint32_t)(value1 == 2));
  Array_ToggleObjectActive(arg1,0x3e9,(uint32_t)(value1 == 2));
  Window_GadgetNotify_Button_SetState(arg1,1000,(uint32_t)(value1 == 1));
  Array_ToggleObjectActive(arg1,1000,(uint32_t)(value1 == 1));
  Window_GadgetNotify_Button_SetState(arg1,0x3ea,(uint32_t)(value1 == 3));
  Array_ToggleObjectActive(arg1,0x3ea,(uint32_t)(value1 == 3));
  Window_GadgetNotify_Button_SetState(arg1,0x3eb,(uint32_t)(value1 == 4));
  Array_ToggleObjectActive(arg1,0x3eb,(uint32_t)(value1 == 4));
  Window_GadgetNotify_Button_SetState(arg1,0x3ed,(uint32_t)(value1 == 6));
  Array_ToggleObjectActive(arg1,0x3ed,(uint32_t)(value1 == 6));
  UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18647,0x23,0);
  return;
}
