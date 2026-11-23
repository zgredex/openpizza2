// Unwind@0055b6f3: ported from Pizza Connection 2 at 0x55b6f3.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b6f3
#include "pc2_port.h"

void Unwind_0055b6f3(void)

{
  int unaff_EBP;
  
  SoundBuffer_DestroyInterfaces(*(uint32_t **)(unaff_EBP + 8));
  return;
}
