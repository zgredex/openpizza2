// Window_SetRectAndUpdateChildren: ported from Pizza Connection 2 at 0x53a020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a020
#include "pc2_port.h"

void __thiscall Window_SetRectAndUpdateChildren(void *self,int arg1,int arg2)

{
  SetRect((LPRECT)((intptr_t)self + 0x84),arg1,arg2,(uint32_t)*(uint16_t *)((intptr_t)self + 0x1a) + arg1,
          (uint32_t)*(uint16_t *)((intptr_t)self + 0x1c) + arg2);
  Renderer_CopyStateToChildren((intptr_t)self);
  return;
}
