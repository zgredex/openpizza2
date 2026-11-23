// Unwind@0055912e: ported from Pizza Connection 2 at 0x55912e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55912e
#include "pc2_port.h"

void Unwind_0055912e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x118));
  return;
}
