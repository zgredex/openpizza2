// FreePlaySubmenu_FillSaveGameRows: ported from Pizza Connection 2 at 0x4ce3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ce3c0
#include "pc2_port.h"

void __cdecl FreePlaySubmenu_FillSaveGameRows(void *arg1,int arg2)

{
  int value1;
  int value2;
  int local_4;
  
  local_4 = *(int *)((intptr_t)DAT_0057df88 + 0x14);
  if (local_4 < 0x14) {
    arg2 = 0;
  }
  else {
    local_4 = 0x13;
  }
  if (0 < local_4) {
    value2 = 2000;
    do {
      value1 = IDMap_Lookup(DAT_0057df88,value2 + -2000 + arg2,(int *)0x0);
      Window_GadgetNotify_Text_SetTextColor(arg1,value2,*(uint32_t *)(value1 + 0x54));
      Window_GadgetNotify_Text_SetText(arg1,value2,value1 + 4);
      if (*(char **)(value1 + 0x44) != (char *)0x0) {
        UI_SetObjectTextByKey(arg1,value2 + 100,*(char **)(value1 + 0x44));
      }
      value1 = value2 + -1999;
      value2 = value2 + 1;
    } while (value1 < local_4);
  }
  return;
}
