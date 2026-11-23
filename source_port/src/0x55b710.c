// Unwind@0055b710: ported from Pizza Connection 2 at 0x55b710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b710
#include "pc2_port.h"

void Unwind_0055b710(void)

{
  int unaff_EBP;
  
  SoundBuffer_DestructDerived(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
