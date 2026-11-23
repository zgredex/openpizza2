// GuardMenu_UpdateOrderPage: ported from Pizza Connection 2 at 0x4be820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4be820
#include "pc2_port.h"

void __cdecl GuardMenu_UpdateOrderPage(void *arg1,char arg2)

{
  void *self;
  int value1;
  uint8_t *uptr2;
  uint8_t *uptr3;
  uint8_t local_80 [128];
  
                    /* Refreshes the guard-service order page. */
  if (arg2 != '\0') {
    Sound_ProcessEvent(DAT_0057ba0c,0x17,0,'\x01');
  }
  value1 = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 0x110));
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f4f,*(uint32_t *)(value1 + 0xa8),0);
  if (*(int *)(value1 + 0xa4) == -1) {
    uptr3 = DAT_00580b7c;
  }
  else {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0x148),*(int *)(value1 + 0x10c),(int *)0x0);
    if (value1 == 0) {
      uptr3 = DAT_00580b7c;
    }
    else {
      String_Format(local_80,DAT_00580d18,value1 + 4);
      uptr3 = local_80;
    }
  }
  Window_GadgetNotify_Text_SetText(arg1,0x1f52,uptr3);
  Window_GadgetNotify_Text_SetText(arg1,0x1f78,(intptr_t)self + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x1f83,(intptr_t)self);
  Gadget_SetTextf(arg1,0x1f7e,(uint8_t *)s__s__d_00568964,DAT_00581044);
  uptr2 = Economy_GetModifier(self,0x17,0);
  Gadget_SetTextf(arg1,0x1f68,&DAT_005686f4,uptr2);
  uptr2 = Economy_GetModifier(self,0x17,1);
  Gadget_SetTextf(arg1,0x1f67,&DAT_005686f4,uptr2);
  uptr2 = Economy_GetModifier(self,0x17,2);
  Gadget_SetTextf(arg1,0x1f54,&DAT_005686f4,uptr2);
  return;
}
