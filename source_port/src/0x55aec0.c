// Unwind@0055aec0: ported from Pizza Connection 2 at 0x55aec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aec0
#include "pc2_port.h"

void Unwind_0055aec0(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable(*(uint32_t **)(unaff_EBP + -0x24));
  return;
}
