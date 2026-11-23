// Unwind@0055aee0: ported from Pizza Connection 2 at 0x55aee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aee0
#include "pc2_port.h"

void Unwind_0055aee0(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
