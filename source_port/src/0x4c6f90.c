// CharacterSelect_FillAttributes: ported from Pizza Connection 2 at 0x4c6f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c6f90
#include "pc2_port.h"

void __cdecl CharacterSelect_FillAttributes(void *arg1)

{
  int *ptr1;
  int value2;
  uint32_t uvalue3;
  uint8_t local_20 [32];
  
  value2 = 0x418;
  ptr1 = &DAT_0057dd48;
  do {
    String_Format(local_20,&DAT_005686f4,*ptr1);
    if (*ptr1 < 0) {
      uvalue3 = 0xff;
    }
    else if (*ptr1 < 1) {
      uvalue3 = 0;
    }
    else {
      uvalue3 = 0xa000;
    }
    Window_GadgetNotify_Text_SetTextColor(arg1,value2,uvalue3);
    Window_GadgetNotify_Text_SetText(arg1,value2,local_20);
    ptr1 = ptr1 + 1;
    value2 = value2 + 1;
  } while ((intptr_t)ptr1 < 0x57dd60);
  String_Format(local_20,&DAT_005686f4,DAT_0057ddb4);
  if (DAT_0057ddb4 < 1) {
    uvalue3 = 0;
  }
  else {
    uvalue3 = 0xa000;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x41e,uvalue3);
  Window_GadgetNotify_Text_SetText(arg1,0x41e,local_20);
  return;
}
