// Unwind@0055af70: ported from Pizza Connection 2 at 0x55af70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55af70
#include "pc2_port.h"

void Unwind_0055af70(void)

{
  int unaff_EBP;
  
  SoundBuffer_DestroyInterfaces(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
