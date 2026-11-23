// Buffer_FreeLockedGlobal: ported from Pizza Connection 2 at 0x4eeef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eeef0
#include "pc2_port.h"

void Buffer_FreeLockedGlobal(int arg1)

{
  CS_Enter(*(int *)(DAT_0057c670 + 0x248));
  if (0 < *(int *)(arg1 + 4)) {
    Mem_Free(*(LPVOID *)(arg1 + 8));
    *(uint32_t *)(arg1 + 4) = 0;
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x248));
  return;
}
