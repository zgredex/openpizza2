// Unwind@0055b600: ported from Pizza Connection 2 at 0x55b600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b600
#include "pc2_port.h"

void Unwind_0055b600(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable((uint32_t *)(unaff_EBP + -0x58));
  return;
}
