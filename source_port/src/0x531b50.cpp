// UI_ClearButtonRecordAnimation: ported from Pizza Connection 2 at 0x531b50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531b50
#include "pc2_port.h"

void __thiscall UI_ClearButtonRecordAnimation(void *self,int arg1)

{
  Window_GadgetNotify(self,arg1,6,0x12d,0,0);
  return;
}
