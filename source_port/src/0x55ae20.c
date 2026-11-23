// Unwind@0055ae20: ported from Pizza Connection 2 at 0x55ae20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ae20
#include "pc2_port.h"

void Unwind_0055ae20(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
