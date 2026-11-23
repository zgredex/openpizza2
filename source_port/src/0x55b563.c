// Unwind@0055b563: ported from Pizza Connection 2 at 0x55b563.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b563
#include "pc2_port.h"

void Unwind_0055b563(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable((uint32_t *)(unaff_EBP + -0x58));
  return;
}
