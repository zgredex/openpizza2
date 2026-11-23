// Unwind@0055a770: ported from Pizza Connection 2 at 0x55a770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a770
#include "pc2_port.h"

void Unwind_0055a770(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x20));
  return;
}
