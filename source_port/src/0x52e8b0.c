// Tooltip_SetBackgroundImage: ported from Pizza Connection 2 at 0x52e8b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e8b0
#include "pc2_port.h"

void __thiscall Tooltip_SetBackgroundImage(void *self,char *arg1)

{
  uint32_t uvalue1;
  
                    /* Sets the tooltip's background image resource. */
  if (*(int *)((intptr_t)self + 0x18) != 0) {
    UI_ReleaseRefCount(*(void **)((intptr_t)self + 0x38),*(int *)((intptr_t)self + 0x18));
  }
  if ((arg1 != (char *)0x0) && (*arg1 != '\0')) {
    uvalue1 = UI_LoadFontByName(*(void **)((intptr_t)self + 0x38),arg1);
    *(uint32_t *)((intptr_t)self + 0x18) = uvalue1;
  }
  return;
}
