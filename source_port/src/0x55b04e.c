// Unwind@0055b04e: ported from Pizza Connection 2 at 0x55b04e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b04e
#include "pc2_port.h"

void Unwind_0055b04e(void)

{
  int unaff_EBP;
  
  SoundBuffer_DestructBase((uint32_t *)(*(int *)(unaff_EBP + -0x88) + 4));
  return;
}
