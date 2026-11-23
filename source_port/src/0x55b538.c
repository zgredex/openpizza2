// Unwind@0055b538: ported from Pizza Connection 2 at 0x55b538.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b538
#include "pc2_port.h"

void Unwind_0055b538(void)

{
  int unaff_EBP;
  
  SoundSample_Destruct((uint32_t *)(unaff_EBP + -0x58));
  return;
}
