// Unwind@0055a620: ported from Pizza Connection 2 at 0x55a620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a620
#include "pc2_port.h"

void Unwind_0055a620(void)

{
  int unaff_EBP;
  
  UI_Child_Destroy(*(uint32_t **)(unaff_EBP + -0x10));
  return;
}
