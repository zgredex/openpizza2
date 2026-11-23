// Renderer_ToggleRenderTarget: ported from Pizza Connection 2 at 0x538780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538780
#include "pc2_port.h"

void __fastcall Renderer_ToggleRenderTarget(void *arg1)

{
  void *local_4;
  
  if (*(int *)((intptr_t)arg1 + 0x4c) != 3) {
    local_4 = arg1;
    if (*(int *)((intptr_t)arg1 + 0x4c) == 0) {
      Renderer_ReleaseTargets(arg1);
      *(uint32_t *)((intptr_t)arg1 + 0x4c) = 1;
    }
    else {
      Renderer_ReleaseTargets(arg1);
      *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
    }
    Surface_InitPixelFormat(arg1,(int *)&local_4,1);
    *(uint8_t *)((intptr_t)arg1 + 0x30) = 1;
    Renderer_CopyStateToChildren((intptr_t)arg1);
  }
  return;
}
