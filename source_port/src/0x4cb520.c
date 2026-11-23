// ListDialog_FillRows: ported from Pizza Connection 2 at 0x4cb520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb520
#include "pc2_port.h"

void __cdecl ListDialog_FillRows(int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value1 = *(int *)((intptr_t)DAT_0057de68 + 0x14);
  if (value1 < 0x14) {
    arg1 = 0;
  }
  else {
    value1 = 0x13;
  }
  if (0 < value1) {
    value4 = 2000 - arg1;
    value3 = 3000 - arg1;
    do {
      Window_GadgetNotify_Button_SetState
                (DAT_0057de30,value4 + arg1,(uint32_t)(arg1 == DAT_0057de54));
      value2 = IDMap_Lookup(DAT_0057de68,arg1,(int *)0x0);
      Window_GadgetNotify_Text_SetText(DAT_0057de30,value3 + arg1,value2 + 4);
      arg1 = arg1 + 1;
      value1 = value1 + -1;
    } while (value1 != 0);
  }
  return;
}
