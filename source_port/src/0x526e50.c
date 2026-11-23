// UI_MarkFullRectDirty: ported from Pizza Connection 2 at 0x526e50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526e50
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall UI_MarkFullRectDirty(void *arg1)

{
  _DAT_00584508 = 1;
  Rect_Union(arg1,0,0,*(int *)((intptr_t)arg1 + 0x270),*(int *)((intptr_t)arg1 + 0x274));
  return;
}
