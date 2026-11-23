// BranchWindow_InitCostPanel: ported from Pizza Connection 2 at 0x4c54d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c54d0
#include "pc2_port.h"

void __cdecl BranchWindow_InitCostPanel(void *arg1)

{
  int value1;
  uint32_t uvalue2;
  void *self;
  void *this_00;
  int value3;
  int value4;
  uint8_t *uptr5;
  bool flag6;
  
                    /* Fills the branch cost panel and type-0x12 counters. */
  self = arg1;
  value4 = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  Sound_ProcessEvent(DAT_0057ba0c,0x17,0,'\x01');
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f4f,*(uint32_t *)(value4 + 0xa8),0);
  flag6 = *(int *)(value4 + 0xa4) == 0x12;
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value4 + 0x110));
  value3 = Game_GetPlayerCity((intptr_t)this_00);
  value1 = *(int *)(value3 + 0x68);
  value3 = *(int *)(value3 + 0x50);
  arg1 = (void *)0x1b58;
  uvalue2 = (uint32_t)flag6;
  do {
    UI_SetChildVisibleByID(self,(intptr_t)arg1,uvalue2);
    arg1 = (void *)((intptr_t)arg1 + 1);
  } while ((intptr_t)arg1 < 0x1b64);
  UI_SetChildVisibleByID(self,0x1f4a,uvalue2);
  UI_SetChildVisibleByID(self,0x1f52,uvalue2);
  value1 = (((value1 + value3) * -0x1e + 100) * 500) / 100;
  if (flag6) {
    value4 = IDMap_Lookup((void *)((intptr_t)this_00 + 0x148),*(int *)(value4 + 0x10c),(int *)0x0);
    Window_GadgetNotify_Text_SetText(self,0x1f52,value4 + 4);
    Window_GadgetNotify_Text_SetText(self,0x1b63,value4 + 4);
    Gadget_SetTextf(self,0x1b5d,&DAT_005686f4,*(uint32_t *)(value4 + 0x1884));
    Gadget_SetTextf(self,0x1b5e,&DAT_005686f4,*(uint32_t *)(value4 + 0x1888));
    Gadget_SetTextf(self,0x1b61,&DAT_005686f4,*(uint32_t *)(value4 + 0x188c));
    Gadget_SetTextf(self,0x1b62,&DAT_005686f4,*(uint32_t *)(value4 + 0x1890));
    value4 = Game_CountObjectsForOwner(this_00,value4,0x17);
    Gadget_SetTextf(self,0x1b59,&DAT_005683a4,value4 * value1);
  }
  Gadget_SetTextf(self,0x1b65,&DAT_005683a4,value1);
  Gadget_SetTextf(self,0x1f76,(uint8_t *)s__s__d_00568964,DAT_00581044);
  uptr5 = Economy_GetModifier(this_00,0x17,0);
  Gadget_SetTextf(self,0x1f68,&DAT_005686f4,uptr5);
  uptr5 = Economy_GetModifier(this_00,0x17,1);
  Gadget_SetTextf(self,0x1f67,&DAT_005686f4,uptr5);
  uptr5 = Economy_GetModifier(this_00,0x17,2);
  Gadget_SetTextf(self,0x1f54,&DAT_005686f4,uptr5);
  return;
}
