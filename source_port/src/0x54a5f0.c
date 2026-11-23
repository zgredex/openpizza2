// DebugConsole_Construct: ported from Pizza Connection 2 at 0x54a5f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a5f0
#include "pc2_port.h"

void __thiscall DebugConsole_Construct(void *self,uint32_t arg1)

{
                    /* Constructs the in-game debug console. */
  *(uint8_t ***)self = &PTR_DebugConsole_Delete_0055cb3c;
  *(uint32_t *)((intptr_t)self + 4) = 0;
  *(uint32_t *)((intptr_t)self + 8) = arg1;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  return;
}
