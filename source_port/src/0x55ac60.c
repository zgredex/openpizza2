// Unwind@0055ac60: ported from Pizza Connection 2 at 0x55ac60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ac60
#include "pc2_port.h"

void Unwind_0055ac60(void)

{
  int unaff_EBP;
  
  SpriteBase_Destructor(*(uint32_t **)(unaff_EBP + -0x3a8));
  return;
}
