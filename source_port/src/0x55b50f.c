// Unwind@0055b50f: ported from Pizza Connection 2 at 0x55b50f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b50f
#include "pc2_port.h"

void Unwind_0055b50f(void)

{
  int unaff_EBP;
  
  CS_Delete((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x9c));
  return;
}
