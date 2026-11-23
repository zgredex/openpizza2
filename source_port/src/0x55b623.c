// Unwind@0055b623: ported from Pizza Connection 2 at 0x55b623.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b623
#include "pc2_port.h"

void Unwind_0055b623(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable((uint32_t *)(unaff_EBP + -0x58));
  return;
}
