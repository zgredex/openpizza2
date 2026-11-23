// Unwind@0055b02b: ported from Pizza Connection 2 at 0x55b02b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b02b
#include "pc2_port.h"

void Unwind_0055b02b(void)

{
  int unaff_EBP;
  
  CS_Delete((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}
