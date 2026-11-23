// UI_SetButtonRecordVariant: ported from Pizza Connection 2 at 0x531b70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531b70
#include "pc2_port.h"

void __thiscall UI_SetButtonRecordVariant(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,6,300,arg2,0);
  return;
}
