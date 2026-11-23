// Unwind@0055af78: ported from Pizza Connection 2 at 0x55af78.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55af78
#include "pc2_port.h"

void Unwind_0055af78(void)

{
  int unaff_EBP;
  
  SoundBuffer_DestructDerived(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
