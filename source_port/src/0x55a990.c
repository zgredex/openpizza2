// Unwind@0055a990: ported from Pizza Connection 2 at 0x55a990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a990
#include "pc2_port.h"

void Unwind_0055a990(void)

{
  int unaff_EBP;
  
  Array_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x20) + 0x148));
  return;
}
