// Unwind@0055afc0: ported from Pizza Connection 2 at 0x55afc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55afc0
#include "pc2_port.h"

void Unwind_0055afc0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x24));
  return;
}
