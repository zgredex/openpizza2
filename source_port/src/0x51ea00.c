// RefPtr_Release: ported from Pizza Connection 2 at 0x51ea00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51ea00
#include "pc2_port.h"

void __fastcall RefPtr_Release(int arg1)

{
  *(uint32_t *)(arg1 + 0x14) = 0;
  if (*(uint32_t **)(arg1 + 4) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 4))(1);
  }
  return;
}
