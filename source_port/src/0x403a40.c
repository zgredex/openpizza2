// TimerClass_ScalarDeletingDestructor: ported from Pizza Connection 2 at 0x403a40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403a40
#include "pc2_port.h"

uint32_t * __thiscall TimerClass_ScalarDeletingDestructor(void *self,uint8_t arg1)

{
                    /* Scalar deleting destructor for the timer class. */
  Timer_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
