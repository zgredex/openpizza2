// Unwind@0055a598: ported from Pizza Connection 2 at 0x55a598.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a598
#include "pc2_port.h"

void Unwind_0055a598(void)

{
  int unaff_EBP;
  
  Array_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}
