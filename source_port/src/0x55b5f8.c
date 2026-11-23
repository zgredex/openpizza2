// Unwind@0055b5f8: ported from Pizza Connection 2 at 0x55b5f8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b5f8
#include "pc2_port.h"

void Unwind_0055b5f8(void)

{
  int unaff_EBP;
  
  SoundSample_Destruct((uint32_t *)(unaff_EBP + -0x58));
  return;
}
