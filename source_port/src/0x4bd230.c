// GuardMenu_FillSummary: ported from Pizza Connection 2 at 0x4bd230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bd230
#include "pc2_port.h"

void __cdecl GuardMenu_FillSummary(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  
  self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value2 = Game_GetPlayerCity((intptr_t)self);
  value1 = *(int *)(value2 + 0x68);
  value2 = *(int *)(value2 + 0x50);
  if (*(void **)((intptr_t)self + 0x1d8) == (void *)0x0) {
    Window_GadgetNotify_Text_SetText(arg1,0x1f59,&DAT_00564220);
  }
  else {
    value3 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)self + 0x1d8),0x17);
    Gadget_SetTextf(arg1,0x1f59,&DAT_005686f4,value3);
  }
  value3 = Game_CountFreeSlots(DAT_0057c670,0x17);
  Gadget_SetTextf(arg1,0x1f7c,&DAT_005686f4,value3);
  value3 = Game_CountActiveObjectsByType(self,0x17);
  Gadget_SetTextf(arg1,0x1f7a,&DAT_005686f4,value3);
  Gadget_SetTextf(arg1,0x1f78,&DAT_005683a4,
                  ((((value1 + value2) * -0x1e + 100) * 500) / 100) * value3);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f4f,*(uint32_t *)(DAT_0057d6fc + 0xa8),0);
  return;
}
