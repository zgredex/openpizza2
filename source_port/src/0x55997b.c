// Unwind@0055997b: ported from Pizza Connection 2 at 0x55997b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55997b
#include "pc2_port.h"

void Unwind_0055997b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
