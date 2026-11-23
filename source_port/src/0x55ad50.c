// Unwind@0055ad50: ported from Pizza Connection 2 at 0x55ad50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ad50
#include "pc2_port.h"

void Unwind_0055ad50(void)

{
  int unaff_EBP;
  
  SpriteBase_Destructor(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
