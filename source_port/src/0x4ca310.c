// EndResults_FillSyndicatePage: ported from Pizza Connection 2 at 0x4ca310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ca310
#include "pc2_port.h"

void __cdecl EndResults_FillSyndicatePage(void *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  uint32_t uvalue5;
  
  Window_GadgetNotify_Text_SetText(arg1,0x4d1,DAT_00581a5c);
  Window_GadgetNotify_Text_SetText(arg1,0x4d2,DAT_005829d4);
  Window_GadgetNotify_Text_SetText(arg1,0x4d3,DAT_005824ac);
  Window_GadgetNotify_Text_SetText(arg1,0x4d4,DAT_005827d0);
  Window_GadgetNotify_Text_SetText(arg1,0x4d5,DAT_00581e00);
  value3 = 0;
  ptr2 = &DAT_0057de18;
  value4 = 0x4fa;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x24,DAT_005812fc);
      Window_GadgetNotify_Text_SetText(arg1,value4,DAT_005812fc);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x24,DAT_005812fc);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x48,DAT_00582f10);
      Gadget_SetTextf(arg1,value4 + -0x1f,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0xbc));
      Gadget_SetTextf(arg1,value4 + 5,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0xc4));
      Gadget_SetTextf(arg1,value4 + 0x29,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0xcc));
      Gadget_SetTextf(arg1,value4 + 0x4d,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0xd4));
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x23,DAT_00582eb0);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 1,DAT_00582eb0);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x25,DAT_00582eb0);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x49,DAT_00580ca8);
      if (*(int *)(*ptr2 + 0xc0) == 1) {
        uvalue5 = DAT_00582a0c;
      }
      else {
        uvalue5 = DAT_005817a4;
      }
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x20,uvalue5);
      if (*(int *)(*ptr2 + 200) == 1) {
        uvalue5 = DAT_00582a0c;
      }
      else {
        uvalue5 = DAT_005817a4;
      }
      Window_GadgetNotify_Text_SetText(arg1,value4 + 4,uvalue5);
      if (*(int *)(*ptr2 + 0xd0) == 1) {
        uvalue5 = DAT_00582a0c;
      }
      else {
        uvalue5 = DAT_005817a4;
      }
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x28,uvalue5);
      Gadget_SetTextf(arg1,value4 + 0x4c,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0xd8));
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x22,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 2,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x26,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x4a,DAT_00581c74);
      Gadget_SetTextf(arg1,value4 + -0x21,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x180));
      Gadget_SetTextf(arg1,value4 + 3,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x184));
      Gadget_SetTextf(arg1,value4 + 0x27,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x188));
      Gadget_SetTextf(arg1,value4 + 0x4b,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x18c));
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + 1;
    value4 = value4 + 6;
  } while ((intptr_t)ptr2 < 0x57de30);
  return;
}
