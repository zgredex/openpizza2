// Glossary_FillPeopleNameList: ported from Pizza Connection 2 at 0x4af5c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4af5c0
#include "pc2_port.h"

void __cdecl Glossary_FillPeopleNameList(void *arg1,int arg2)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  
  uptr2 = (uint32_t *)(&DAT_00583434 + arg2 * 4);
  value3 = 0x3e9;
  do {
    Window_GadgetNotify_Button_SetState
              (arg1,value3,(uint32_t)(value3 + -0x3e9 + arg2 == DAT_0057d664));
    Window_GadgetNotify_Text_SetText(arg1,value3 + 0x36,*uptr2);
    uptr2 = uptr2 + 1;
    value1 = value3 + -1000;
    value3 = value3 + 1;
  } while (value1 < 0xd);
  return;
}
