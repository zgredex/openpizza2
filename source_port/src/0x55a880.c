// Unwind@0055a880: ported from Pizza Connection 2 at 0x55a880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a880
#include "pc2_port.h"

void Unwind_0055a880(void)

{
  int unaff_EBP;
  
  UI_Child_Destroy(*(uint32_t **)(unaff_EBP + -0x30));
  return;
}
