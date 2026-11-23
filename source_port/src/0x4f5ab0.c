// Object_EnsureFirstChild: ported from Pizza Connection 2 at 0x4f5ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5ab0
#include "pc2_port.h"

void Object_EnsureFirstChild(int arg1,uint32_t arg2,uint32_t *arg3)

{
  if (*(int *)(*(int *)(arg1 + 8) + 0x38) == 0) {
    *(uint32_t *)(*(int *)(arg1 + 8) + 0x38) = 1;
    *arg3 = **(uint32_t **)(arg1 + 8);
  }
  return;
}
