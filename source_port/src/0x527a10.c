// UI_RefreshChildSprite: ported from Pizza Connection 2 at 0x527a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527a10
#include "pc2_port.h"

void __thiscall UI_RefreshChildSprite(void *self,int arg1,int arg2,int arg3)

{
  if ((arg1 == 0) || (*(void **)((intptr_t)self + 0x8314) == (void *)0x0)) {
    UI_ClearChildExtent(*(uint32_t **)((intptr_t)self + 0x8310));
    return;
  }
  UI_SetElementSprite(*(void **)((intptr_t)self + 0x8310),*(void **)((intptr_t)self + 0x8314),arg2,arg3)
  ;
  return;
}
