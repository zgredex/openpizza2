// EndResultPoints_FillBuildingTable: ported from Pizza Connection 2 at 0x4c9390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c9390
#include "pc2_port.h"

void __cdecl EndResultPoints_FillBuildingTable(void *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  Window_GadgetNotify_Text_SetText(arg1,0x4d1,DAT_00581774);
  Window_GadgetNotify_Text_SetText(arg1,0x4d2,DAT_00581790);
  Window_GadgetNotify_Text_SetText(arg1,0x4d3,DAT_00582dd4);
  Window_GadgetNotify_Text_SetText(arg1,0x4d4,DAT_005822ac);
  Window_GadgetNotify_Text_SetText(arg1,0x4d5,DAT_00582da0);
  value3 = 0;
  ptr2 = &DAT_0057de18;
  value4 = 0x4fa;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x24,DAT_005823d0);
      Window_GadgetNotify_Text_SetText(arg1,value4,DAT_005823d0);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x24,DAT_00581d50);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x48,DAT_00581250);
      Gadget_SetTextf(arg1,value4 + -0x1f,&DAT_005686f4,*(uint32_t *)(*ptr2 + 4));
      Gadget_SetTextf(arg1,value4 + 5,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0xc));
      Gadget_SetTextf(arg1,value4 + 0x29,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x10));
      Gadget_SetTextf(arg1,value4 + 0x4d,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x18));
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x23,DAT_00581d50);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 1,DAT_00581d50);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x25,DAT_005824cc);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x49,DAT_00582af8);
      Gadget_SetTextf(arg1,value4 + -0x20,&DAT_005686f4,*(uint32_t *)*ptr2);
      Gadget_SetTextf(arg1,value4 + 4,&DAT_005686f4,*(uint32_t *)(*ptr2 + 8));
      Gadget_SetTextf(arg1,value4 + 0x28,&DAT_005683a4,*(uint32_t *)(*ptr2 + 0x14));
      Gadget_SetTextf(arg1,value4 + 0x4c,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x1c));
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x22,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 2,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x26,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x4a,DAT_00581c74);
      Gadget_SetTextf(arg1,value4 + -0x21,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x120));
      Gadget_SetTextf(arg1,value4 + 3,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x124));
      Gadget_SetTextf(arg1,value4 + 0x27,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x128));
      Gadget_SetTextf(arg1,value4 + 0x4b,&DAT_005686f4,*(uint32_t *)(*ptr2 + 300));
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + 1;
    value4 = value4 + 6;
  } while ((intptr_t)ptr2 < 0x57de30);
  return;
}
