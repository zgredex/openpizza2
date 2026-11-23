// LoadGameMenu_UpdateSlotRows: ported from Pizza Connection 2 at 0x4a1a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a1a10
#include "pc2_port.h"

void __cdecl LoadGameMenu_UpdateSlotRows(void *arg1,int arg2)

{
  int value1;
  int value2;
  int local_4;
  
  local_4 = *(int *)((intptr_t)DAT_0057cfc8 + 0x14);
  if (local_4 < 0xe) {
    arg2 = 0;
  }
  else {
    local_4 = 0xd;
  }
  if (0 < local_4) {
    value2 = 0x1f6a;
    do {
      value1 = IDMap_Lookup(DAT_0057cfc8,value2 + -0x1f6a + arg2,(int *)0x0);
      Window_GadgetNotify_Text_SetTextColor(arg1,value2,*(uint32_t *)(value1 + 0x54));
      Window_GadgetNotify_Text_SetText(arg1,value2,value1 + 4);
      if (*(char **)(value1 + 0x44) != (char *)0x0) {
        UI_SetObjectTextByKey(arg1,value2 + -0xd,*(char **)(value1 + 0x44));
      }
      value1 = value2 + -0x1f69;
      value2 = value2 + 1;
    } while (value1 < local_4);
  }
  return;
}
