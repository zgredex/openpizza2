// UI_StartButtonMovie: ported from Pizza Connection 2 at 0x531c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531c40
#include "pc2_port.h"

void __thiscall UI_StartButtonMovie(void *self,int arg1,uint32_t arg2)

{
  Window_GadgetNotify(self,arg1,6,0x3e,arg2,0);
  return;
}
