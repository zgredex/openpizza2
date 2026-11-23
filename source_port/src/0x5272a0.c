// UI_SetFontName: ported from Pizza Connection 2 at 0x5272a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5272a0
#include "pc2_port.h"

void __thiscall UI_SetFontName(void *self,char *arg1)

{
                    /* Sets the UI manager's font resource by name. */
  Tooltip_SetBackgroundImage(*(void **)((intptr_t)self + 0x244),arg1);
  return;
}
