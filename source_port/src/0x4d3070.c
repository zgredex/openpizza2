// Entity_SetTileId: ported from Pizza Connection 2 at 0x4d3070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3070
#include "pc2_port.h"

void __thiscall Entity_SetTileId(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x24) = arg1;
  return;
}
