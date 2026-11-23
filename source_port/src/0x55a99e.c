// Unwind@0055a99e: ported from Pizza Connection 2 at 0x55a99e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a99e
#include "pc2_port.h"

void Unwind_0055a99e(void)

{
  int unaff_EBP;
  
  Array_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x20) + 0x2a8));
  return;
}
