// UI_PrintSignedValue: ported from Pizza Connection 2 at 0x4a6680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a6680
#include "pc2_port.h"

void __cdecl UI_PrintSignedValue(void *arg1,int arg2,int arg3)

{
  uint32_t uvalue1;
  
  if (arg3 < 1) {
    if (arg3 == 0) {
      uvalue1 = 0;
    }
    else {
      uvalue1 = 0xff;
    }
  }
  else {
    uvalue1 = 0xa000;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,arg2,uvalue1);
  Gadget_SetTextf(arg1,arg2,&DAT_005686f4,arg3);
  return;
}
