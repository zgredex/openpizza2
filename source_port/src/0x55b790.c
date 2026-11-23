// Unwind@0055b790: ported from Pizza Connection 2 at 0x55b790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b790
#include "pc2_port.h"

void Unwind_0055b790(void)

{
  int unaff_EBP;
  
  SoundBuffer_SetBaseVTable(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
