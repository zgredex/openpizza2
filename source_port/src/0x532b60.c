// Sound_StopBuffer: ported from Pizza Connection 2 at 0x532b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532b60
#include "pc2_port.h"

void __fastcall Sound_StopBuffer(int arg1)

{
  if (*(int *)(arg1 + 0x2c0) != 0) {
    *(uint32_t *)(arg1 + 0x2c0) = 0;
    if (*(uint32_t **)(arg1 + 0x138) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)(arg1 + 0x138))(1);
    }
    *(uint32_t *)(arg1 + 0x138) = 0;
  }
  return;
}
