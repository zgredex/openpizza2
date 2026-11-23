// AIStatus_UpdateCompanyPanel: ported from Pizza Connection 2 at 0x4c5e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c5e80
#include "pc2_port.h"

void __cdecl AIStatus_UpdateCompanyPanel(void *arg1)

{
  int value1;
  int value2;
  int value3;
  
                    /* Refreshes the AI-status company panel. */
  value1 = *(int *)((intptr_t)DAT_0057c670 + DAT_0057dd00 * 4 + 0x224);
  value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 8));
  value2 = *(int *)((intptr_t)DAT_0057c670 + 0x90);
  Personnel_SetEmployeePhotoByKey(arg1,0x1f4f,value3);
  Window_GadgetNotify_Text_SetText(arg1,0x1f4c,value3 + 8);
  Window_GadgetNotify_Button_SetState(arg1,0x1f53,*(int *)(value2 + 0x114 + DAT_0057dd00 * 0x168))
  ;
  Gadget_SetTextf(arg1,0x1f56,(uint8_t *)s___2lf_0056b0d4,(intptr_t)*(uint64_t *)(value3 + 0x108));
  Window_GadgetNotify_Slider_SetValue
            (arg1,0x1f55,(intptr_t)*(short *)(value2 + 0x128 + DAT_0057dd00 * 0x168),0);
  Window_GadgetNotify_Slider_SetValue
            (arg1,0x1f62,(intptr_t)*(short *)(value2 + 0x130 + DAT_0057dd00 * 0x168),0);
  Gadget_SetTextf(arg1,0x1f5e,&DAT_005686f4,DAT_0057dd00);
  Gadget_SetTextf(arg1,0x1f5f,&DAT_005686f4,*(uint32_t *)(value1 + 8));
  if (*(int *)(value2 + 300 + DAT_0057dd00 * 0x168) == 0x18) {
    Gadget_SetText(arg1,0x1f5a,s_reset_0056b0cc);
    return;
  }
  Gadget_SetText(arg1,0x1f5a,&DAT_00566cd8);
  return;
}
