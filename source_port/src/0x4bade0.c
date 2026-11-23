// BranchPage_UpdateInfoPanel: ported from Pizza Connection 2 at 0x4bade0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bade0
#include "pc2_port.h"

void __cdecl BranchPage_UpdateInfoPanel(void *arg1,char arg2)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t local_c [3];
  
  local_c[0] = DAT_00581fe8;
  local_c[1] = DAT_00582aec;
  local_c[2] = DAT_00582fbc;
  if (arg2 != '\0') {
    Sound_ProcessEvent(DAT_0057ba0c,10,0,'\x01');
  }
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  value4 = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  value1 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value3 = *(int *)((intptr_t)self + *(int *)(value1 + 0x48) * 4 + 0xd40);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1fa8,value3,0);
  value3 = (100 - value3) / 3;
  if (value3 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x1fb0,&DAT_00569308);
  }
  else {
    Gadget_SetTextf(arg1,0x1fb0,(uint8_t *)s___d____00569300,value3);
  }
  value1 = Stats_GetPlayerSharePercent(self,*(int *)(value1 + 0x48));
  Gadget_SetTextf(arg1,0x1fac,(uint8_t *)s__d____00568834,value1);
  value1 = *(int *)(value4 + 0xa4);
  value3 = *(int *)(value4 + 0xfc);
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value3 + 8));
  if (value2 != 0) {
    value3 = IDMap_Lookup((void *)(value2 + 0x148),*(int *)(value3 + 0x2c),(int *)0x0);
    if ((value3 != 0) && (value1 == 0xc)) {
      Window_GadgetNotify_Text_SetText(arg1,0x1fef,local_c[*(int *)(value4 + 0x10c)]);
      Window_GadgetNotify_Text_SetText(arg1,0x1fbc,value3 + 4);
      if (*(int *)(value4 + 0x108) == 2) {
        uvalue5 = DAT_00580ebc;
      }
      else {
        uvalue5 = DAT_00582220;
      }
      value4 = 0x1fed;
      goto LAB_004baf87;
    }
  }
  Window_GadgetNotify_Text_SetText(arg1,0x1fed,DAT_00582adc);
  Window_GadgetNotify_Text_SetText(arg1,0x1fbc,DAT_00582adc);
  value4 = 0x1fef;
  uvalue5 = DAT_00580b7c;
LAB_004baf87:
  Window_GadgetNotify_Text_SetText(arg1,value4,uvalue5);
  Gadget_SetTextf(arg1,0x1fd9,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd58));
  Gadget_SetTextf(arg1,0x1fda,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd5c));
  Gadget_SetTextf(arg1,0x1fdc,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd60));
  Gadget_SetTextf(arg1,0x1fdd,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd64));
  Gadget_SetTextf(arg1,0x1fdf,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd68));
  Gadget_SetTextf(arg1,0x1fe0,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd6c));
  Gadget_SetTextf(arg1,0x1fe2,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd70));
  Gadget_SetTextf(arg1,0x1fe3,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd74));
  Gadget_SetTextf(arg1,0x1fe5,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd78));
  Gadget_SetTextf(arg1,0x1fe6,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd7c));
  Gadget_SetTextf(arg1,0x1fe8,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd80));
  Gadget_SetTextf(arg1,0x1fe9,&DAT_005686f4,*(uint32_t *)((intptr_t)self + 0xd84));
  return;
}
