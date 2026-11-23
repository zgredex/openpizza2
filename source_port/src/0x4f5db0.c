// Object_ClearState: ported from Pizza Connection 2 at 0x4f5db0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5db0
#include "pc2_port.h"

void Object_ClearState(int arg1)

{
  if ((arg1 != 0) && (*(int *)(arg1 + 8) != 0)) {
    *(uint32_t *)(*(int *)(arg1 + 8) + 0x1c) = 0xffffffff;
    *(uint8_t *)(*(int *)(arg1 + 8) + 0x2c) = 0;
    *(uint8_t *)(*(int *)(arg1 + 8) + 0x2d) = 0;
    *(uint8_t *)(*(int *)(arg1 + 8) + 0x2e) = 0;
    *(uint8_t *)(*(int *)(arg1 + 8) + 0x2f) = 0;
  }
  return;
}
