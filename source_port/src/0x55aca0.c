// Unwind@0055aca0: ported from Pizza Connection 2 at 0x55aca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aca0
#include "pc2_port.h"

void Unwind_0055aca0(void)

{
  int unaff_EBP;
  
  SpriteBase_Destructor(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
