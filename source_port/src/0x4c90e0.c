// EndResultPoints_FillOverview: ported from Pizza Connection 2 at 0x4c90e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c90e0
#include "pc2_port.h"

void __cdecl EndResultPoints_FillOverview(void *arg1)

{
  uint32_t uvalue1;
  void *self;
  int value2;
  int *ptr3;
  int value4;
  
  self = arg1;
  Window_GadgetNotify_Text_SetText(arg1,0x4d1,DAT_00581a58);
  Window_GadgetNotify_Text_SetText(arg1,0x4d2,DAT_00581b6c);
  Window_GadgetNotify_Text_SetText(arg1,0x4d3,DAT_0058100c);
  Window_GadgetNotify_Text_SetText(arg1,0x4d4,DAT_00581930);
  Window_GadgetNotify_Text_SetText(arg1,0x4d5,DAT_00581d60);
  arg1 = (void *)0x0;
  ptr3 = &DAT_0057de18;
  value4 = 0x4db;
  do {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,(intptr_t)arg1);
    if (value2 != 0) {
      uvalue1 = *(uint32_t *)(*ptr3 + 0x11c);
      Window_GadgetNotify_Text_SetText(self,value4 + -5,DAT_005818d8);
      Gadget_SetTextf(self,value4,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0xfc));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x1f,DAT_00581648);
      Gadget_SetTextf(self,value4 + 0x24,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x108));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x43,DAT_00580fe0);
      Gadget_SetTextf(self,value4 + 0x48,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x114));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x67,DAT_00582be4);
      Gadget_SetTextf(self,value4 + 0x6c,&DAT_005686f4,uvalue1);
      Window_GadgetNotify_Text_SetText(self,value4 + -4,DAT_00582710);
      Gadget_SetTextf(self,value4 + -1,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x100));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x20,DAT_00580c88);
      Gadget_SetTextf(self,value4 + 0x23,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x10c));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x44,DAT_00581a5c);
      Gadget_SetTextf(self,value4 + 0x47,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x118));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x68,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(self,value4 + 0x6b,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(self,value4 + -3,DAT_00582350);
      Gadget_SetTextf(self,value4 + -2,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x104));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x21,DAT_00580c04);
      Gadget_SetTextf(self,value4 + 0x22,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x110));
      Window_GadgetNotify_Text_SetText(self,value4 + 0x45,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(self,value4 + 0x46,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(self,value4 + 0x69,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(self,value4 + 0x6a,DAT_00582e4c);
    }
    ptr3 = ptr3 + 1;
    arg1 = (void *)((intptr_t)arg1 + 1);
    value4 = value4 + 6;
  } while ((intptr_t)ptr3 < 0x57de30);
  return;
}
