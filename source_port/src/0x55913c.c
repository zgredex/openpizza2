// Unwind@0055913c: ported from Pizza Connection 2 at 0x55913c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55913c
#include "pc2_port.h"

void Unwind_0055913c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x118));
  return;
}
