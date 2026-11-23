// Unwind@0055b05c: ported from Pizza Connection 2 at 0x55b05c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b05c
#include "pc2_port.h"

void Unwind_0055b05c(void)

{
  int unaff_EBP;
  
  DirectSoundBuffer_Destructor((uint32_t *)(*(int *)(unaff_EBP + -0x88) + 0x14));
  return;
}
