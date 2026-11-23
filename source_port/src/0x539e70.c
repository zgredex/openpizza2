// Renderer_CopyStateToChildren: ported from Pizza Connection 2 at 0x539e70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539e70
#include "pc2_port.h"

void __fastcall Renderer_CopyStateToChildren(int arg1)

{
  uint32_t *uptr1;
  
  for (uptr1 = *(uint32_t **)(arg1 + 0x50); uptr1 != (uint32_t *)0x0;
      uptr1 = (uint32_t *)uptr1[1]) {
    Renderer_CopyState((void *)*uptr1,arg1);
  }
  return;
}
