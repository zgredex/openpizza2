// Unwind@0055b673: ported from Pizza Connection 2 at 0x55b673.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b673
#include "pc2_port.h"

void Unwind_0055b673(void)

{
  int unaff_EBP;
  
  CS_Delete((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}
