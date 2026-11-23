// Unwind@0055b06a: ported from Pizza Connection 2 at 0x55b06a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b06a
#include "pc2_port.h"

void Unwind_0055b06a(void)

{
  int unaff_EBP;
  
  SoundMixerThread_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x88) + 0x1c));
  return;
}
