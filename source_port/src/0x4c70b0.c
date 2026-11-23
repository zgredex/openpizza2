// UI_SetMultipleLabels: ported from Pizza Connection 2 at 0x4c70b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c70b0
#include "pc2_port.h"

void __cdecl UI_SetMultipleLabels(void *arg1,int *arg2)

{
  bool flag1;
  
  flag1 = false;
  do {
    if (*arg2 == -1) {
      flag1 = true;
    }
    else {
      UI_SetChildLabelText(arg1,*arg2,1,(char *)arg2[1]);
    }
    arg2 = arg2 + 2;
  } while (!flag1);
  return;
}
