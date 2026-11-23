// Unwind@0055aa50: ported from Pizza Connection 2 at 0x55aa50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aa50
#include "pc2_port.h"

void Unwind_0055aa50(void)

{
  int unaff_EBP;
  
  Array_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x148));
  return;
}
