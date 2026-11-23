// Unwind@0055b540: ported from Pizza Connection 2 at 0x55b540.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b540
#include "pc2_port.h"

void Unwind_0055b540(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable((uint32_t *)(unaff_EBP + -0x58));
  return;
}
