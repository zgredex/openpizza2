// Person_ClearCompletedAction: ported from Pizza Connection 2 at 0x50e520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e520
#include "pc2_port.h"

void __fastcall Person_ClearCompletedAction(void *arg1)

{
                    /* Clears a completed person action and returns to idle. */
  *(uint32_t *)((intptr_t)arg1 + 0x108) = 0xffffffff;
  if (*(int *)((intptr_t)arg1 + 0x74) == 0) {
    Person_ReturnToHomeBase(arg1);
    return;
  }
  return;
}
