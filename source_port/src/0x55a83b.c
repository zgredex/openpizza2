// Unwind@0055a83b: ported from Pizza Connection 2 at 0x55a83b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a83b
#include "pc2_port.h"

void Unwind_0055a83b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}
