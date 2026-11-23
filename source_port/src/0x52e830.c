// Renderer_ReleaseTarget: ported from Pizza Connection 2 at 0x52e830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e830
#include "pc2_port.h"

void __fastcall Renderer_ReleaseTarget(int arg1)

{
  if (*(int *)(arg1 + 0x14) != 0) {
    *(uint32_t *)(arg1 + 0x14) = 0;
    *(uint32_t *)(arg1 + 0x3c) = 1;
  }
  return;
}
