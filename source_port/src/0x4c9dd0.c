// EndResults_FillAdvertisingPage: ported from Pizza Connection 2 at 0x4c9dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c9dd0
#include "pc2_port.h"

void __cdecl EndResults_FillAdvertisingPage(void *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  Window_GadgetNotify_Text_SetText(arg1,0x4d1,DAT_00580ba8);
  Window_GadgetNotify_Text_SetText(arg1,0x4d2,DAT_005811ac);
  Window_GadgetNotify_Text_SetText(arg1,0x4d3,DAT_00581c9c);
  Window_GadgetNotify_Text_SetText(arg1,0x4d4,DAT_00580eb0);
  Window_GadgetNotify_Text_SetText(arg1,0x4d5,DAT_0058226c);
  value3 = 0;
  ptr2 = &DAT_0057de18;
  value4 = 0x4fa;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x24,DAT_00581cfc);
      Window_GadgetNotify_Text_SetText(arg1,value4,DAT_00581cfc);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x24,DAT_00581cfc);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x48,DAT_00581cfc);
      Gadget_SetTextf(arg1,value4 + -0x1f,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x7c));
      Gadget_SetTextf(arg1,value4 + 5,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x84));
      Gadget_SetTextf(arg1,value4 + 0x29,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x8c));
      Gadget_SetTextf(arg1,value4 + 0x4d,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x94));
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x23,DAT_00582f7c);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 1,DAT_00582f7c);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x25,DAT_00582f7c);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x49,DAT_00582f7c);
      Gadget_SetTextf(arg1,value4 + -0x20,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x80));
      Gadget_SetTextf(arg1,value4 + 4,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x88));
      Gadget_SetTextf(arg1,value4 + 0x28,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x90));
      Gadget_SetTextf(arg1,value4 + 0x4c,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x98));
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x22,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 2,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x26,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x4a,DAT_00581c74);
      Gadget_SetTextf(arg1,value4 + -0x21,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x160));
      Gadget_SetTextf(arg1,value4 + 3,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x164));
      Gadget_SetTextf(arg1,value4 + 0x27,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x168));
      Gadget_SetTextf(arg1,value4 + 0x4b,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x16c));
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + 1;
    value4 = value4 + 6;
  } while ((intptr_t)ptr2 < 0x57de30);
  return;
}
