// Surface_AliasPixelPlanes: ported from Pizza Connection 2 at 0x4ed040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed040
#include "pc2_port.h"

void __fastcall Surface_AliasPixelPlanes(int arg1)

{
  if ((*(int *)(arg1 + 0xc) == 0x40) && (*(int *)(arg1 + 0x10) == 0x20)) {
    *(uint32_t *)(*(int *)(arg1 + 4) + 4) = *(uint32_t *)(*(int *)(arg1 + 4) + 0xc);
    *(uint32_t *)(*(int *)(arg1 + 4) + 8) = *(uint32_t *)(*(int *)(arg1 + 4) + 0x14);
    *(uint32_t *)(*(int *)(arg1 + 4) + 8) = *(uint32_t *)(*(int *)(arg1 + 4) + 0x14);
    return;
  }
  if ((*(int *)(arg1 + 0xc) == 0x10) && (*(int *)(arg1 + 0x10) == 8)) {
    *(uint32_t *)(*(int *)(arg1 + 4) + 4) = *(uint32_t *)(*(int *)(arg1 + 4) + 0x10);
    *(uint32_t *)(*(int *)(arg1 + 4) + 8) = *(uint32_t *)(*(int *)(arg1 + 4) + 0x18);
    return;
  }
  NoOp_Stub();
  return;
}
