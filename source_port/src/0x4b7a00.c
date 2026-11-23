// ProtectionDemand_UpdatePage: ported from Pizza Connection 2 at 0x4b7a00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b7a00
#include "pc2_port.h"

void __cdecl ProtectionDemand_UpdatePage(void *arg1)

{
  bool flag1;
  int value2;
  
                    /* Refreshes the protection-money demand page. */
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x9c) + 0x30));
  value2 = *(int *)(value2 + 0x48);
  Window_GadgetNotify_Slider_SetRange(arg1,0x1fae,1000,5000,0);
  DAT_0057d6b0 = *(int *)(*(int *)((intptr_t)DAT_0057c670 +
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x94 +
                         value2 * 4);
  flag1 = DAT_0057d6b0 < 1;
  if (flag1) {
    DAT_0057d6b0 = 1000;
    Window_GadgetNotify_Slider_SetValue(arg1,0x1fae,1000,0);
    DAT_0057d6b4 = 1;
  }
  else {
    DAT_0057d6b4 = 0;
    Window_GadgetNotify_Slider_SetValue(arg1,0x1fae,DAT_0057d6b0,0);
  }
  Array_SetField14ByKey(arg1,0x1fae,(uint32_t)flag1);
  Gadget_SetTextf(arg1,0x1faf,&DAT_005683a4,5000);
  Gadget_SetTextf(arg1,0x1fad,&DAT_005683a4,1000);
  Window_GadgetNotify_Slider_AttachValueText(arg1,0x1fae,0x1fac,&DAT_005683a4);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1fae,1);
  AttacksPage_FillProtectionMoney(arg1);
  return;
}
