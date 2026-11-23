// Unwind@0055a550: ported from Pizza Connection 2 at 0x55a550.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a550
#include "pc2_port.h"

void Unwind_0055a550(void)

{
  int unaff_EBP;
  
  UI_Child_Destroy(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
