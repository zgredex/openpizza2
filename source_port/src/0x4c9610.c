// EndResultPoints_FillMissionTable: ported from Pizza Connection 2 at 0x4c9610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c9610
#include "pc2_port.h"

void __cdecl EndResultPoints_FillMissionTable(void *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  uint32_t uvalue5;
  
  Window_GadgetNotify_Text_SetText(arg1,0x4d1,DAT_00581258);
  Window_GadgetNotify_Text_SetText(arg1,0x4d2,DAT_00581c10);
  Window_GadgetNotify_Text_SetText(arg1,0x4d3,DAT_005816dc);
  Window_GadgetNotify_Text_SetText(arg1,0x4d4,DAT_00582d74);
  Window_GadgetNotify_Text_SetText(arg1,0x4d5,DAT_00580d00);
  value3 = 0;
  ptr2 = &DAT_0057de18;
  value4 = 0x4fa;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x24,DAT_00581660);
      Window_GadgetNotify_Text_SetText(arg1,value4,DAT_00582bdc);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x24,DAT_00582e74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x48,DAT_00582924);
      Gadget_SetTextf(arg1,value4 + -0x1f,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x20));
      if (*(int *)(*ptr2 + 0x28) < 1) {
        uvalue5 = DAT_005817a4;
      }
      else {
        uvalue5 = DAT_00582a0c;
      }
      Window_GadgetNotify_Text_SetText(arg1,value4 + 5,uvalue5);
      Gadget_SetTextf(arg1,value4 + 0x29,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x30));
      if (*(int *)(*ptr2 + 0x38) == 0) {
        uvalue5 = DAT_005817a4;
      }
      else {
        uvalue5 = DAT_00582a0c;
      }
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x4d,uvalue5);
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x23,DAT_00582920);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 1,DAT_005824cc);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x25,DAT_00582a84);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x49,DAT_00582914);
      Gadget_SetTextf(arg1,value4 + -0x20,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x24));
      Gadget_SetTextf(arg1,value4 + 4,&DAT_005683a4,*(uint32_t *)(*ptr2 + 0x2c));
      Gadget_SetTextf(arg1,value4 + 0x28,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x34));
      if (*(int *)(*ptr2 + 0x38) == 0) {
        uvalue5 = DAT_005817a4;
      }
      else {
        uvalue5 = DAT_00582a0c;
      }
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x4c,uvalue5);
      Window_GadgetNotify_Text_SetText(arg1,value4 + -0x22,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 2,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x26,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 0x4a,DAT_00581c74);
      Gadget_SetTextf(arg1,value4 + -0x21,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x130));
      Gadget_SetTextf(arg1,value4 + 3,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x134));
      Gadget_SetTextf(arg1,value4 + 0x27,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x138));
      Gadget_SetTextf(arg1,value4 + 0x4b,&DAT_005686f4,*(uint32_t *)(*ptr2 + 0x13c));
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + 1;
    value4 = value4 + 6;
  } while ((intptr_t)ptr2 < 0x57de30);
  return;
}
