// Unwind@0055b0a2: ported from Pizza Connection 2 at 0x55b0a2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b0a2
#include "pc2_port.h"

void Unwind_0055b0a2(void)

{
  int unaff_EBP;
  
  CS_Delete((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x88) + 0xa0));
  return;
}
