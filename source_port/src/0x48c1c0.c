// Object_AbortOrderForTarget: ported from Pizza Connection 2 at 0x48c1c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c1c0
#include "pc2_port.h"

void Object_AbortOrderForTarget(void *arg1,int arg2,int arg3)

{
  int value1;
  
                    /* Aborts an object's order when its target matches. */
  value1 = State_Is2DOr2E((intptr_t)arg1);
  if ((value1 == 0) &&
     ((arg3 != 0 ||
      ((*(int *)((intptr_t)arg1 + 0xa4) != 0x19 && (*(int *)((intptr_t)arg1 + 0xa4) != 0x1a)))))) {
    if (*(int *)((intptr_t)arg1 + 0x74) == 0) {
      value1 = *(int *)((intptr_t)arg1 + 0xfc);
    }
    else {
      value1 = *(int *)((intptr_t)arg1 + 0xf4);
    }
    if (value1 == arg2) {
      Object_AbortOrderAndReturnHome(arg1);
      if (*(int *)((intptr_t)arg1 + 0x74) != 0) {
        *(uint8_t *)((intptr_t)arg1 + 0x81) = 1;
      }
    }
  }
  return;
}
