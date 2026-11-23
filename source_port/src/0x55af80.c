// Unwind@0055af80: ported from Pizza Connection 2 at 0x55af80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55af80
#include "pc2_port.h"

void Unwind_0055af80(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
