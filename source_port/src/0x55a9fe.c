// Unwind@0055a9fe: ported from Pizza Connection 2 at 0x55a9fe.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a9fe
#include "pc2_port.h"

void Unwind_0055a9fe(void)

{
  int unaff_EBP;
  
  Array_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x2a8));
  return;
}
