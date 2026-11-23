// FreePlaySetup_FillCityTable: ported from Pizza Connection 2 at 0x4cb6e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb6e0
#include "pc2_port.h"

void __cdecl FreePlaySetup_FillCityTable(void *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  uint32_t uvalue4;
  uint8_t local_20 [32];
  
  String_Format(local_20,&DAT_005686f8,DAT_0057bcd8);
  Window_GadgetNotify_Text_SetText(arg1,0x453,local_20);
  value3 = 0x45a;
  ptr2 = &DAT_0057bd9c;
  do {
    String_Format(local_20,&DAT_005686f8,ptr2[-1]);
    Window_GadgetNotify_Text_SetText(arg1,value3 + 1,local_20);
    value1 = *ptr2;
    String_Format(local_20,&DAT_005686f4,value1);
    if (value1 == 0) {
      uvalue4 = 0;
    }
    else if (value1 < 0) {
      uvalue4 = 0xff;
    }
    else {
      uvalue4 = 0xa000;
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,value3,uvalue4);
    Window_GadgetNotify_Text_SetText(arg1,value3,local_20);
    ptr2 = ptr2 + 0x30;
    value3 = value3 + 8;
  } while ((intptr_t)ptr2 < 0x57c15c);
  return;
}
