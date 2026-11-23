// Unwind@0055af28: ported from Pizza Connection 2 at 0x55af28.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55af28
#include "pc2_port.h"

void Unwind_0055af28(void)

{
  int unaff_EBP;
  
  SoundBuffer_DestroyInterfaces(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
