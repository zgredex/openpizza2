// UI_RefreshAndCenter: ported from Pizza Connection 2 at 0x523de0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523de0
#include "pc2_port.h"

void __thiscall UI_RefreshAndCenter(void *self,void *arg1)

{
  CS_Enter(*(int *)((intptr_t)self + 0x1c8));
  UI_RenderScene((intptr_t)self);
  Surface_CopyRect16(arg1,*(int *)((intptr_t)self + 0xc),0,0);
  CS_Leave(*(int *)((intptr_t)self + 0x1c8));
  return;
}
