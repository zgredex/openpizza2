// RefCounted_Free: ported from Pizza Connection 2 at 0x521da0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521da0
#include "pc2_port.h"

void RefCounted_Free(int *arg1)

{
  if (arg1 != (int *)0x0) {
    if ((*arg1 == 1) && ((uint32_t *)arg1[1] != (uint32_t *)0x0)) {
      (*(code *)**(uint32_t **)arg1[1])(1);
    }
    Mem_Free(arg1);
  }
  return;
}
