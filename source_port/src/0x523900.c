// UI_ReplaceActiveObject: ported from Pizza Connection 2 at 0x523900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523900
#include "pc2_port.h"

void __thiscall UI_ReplaceActiveObject(void *self,uint32_t arg1)

{
  Movie_ReleasePlayer((intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0x1c4) = arg1;
  *(uint32_t *)((intptr_t)self + 0x83b8) = 1;
  UI_MarkFullRectDirty(self);
  return;
}
