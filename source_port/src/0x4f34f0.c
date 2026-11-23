// UI_GetRecordCenteredRect: ported from Pizza Connection 2 at 0x4f34f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f34f0
#include "pc2_port.h"

void __thiscall UI_GetRecordCenteredRect(void *self,int arg1,int *arg2,int *arg3)

{
  UI_ComputeCenteredRect(self,(int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0xc),arg2,arg3);
  return;
}
