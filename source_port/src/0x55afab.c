// Unwind@0055afab: ported from Pizza Connection 2 at 0x55afab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55afab
#include "pc2_port.h"

void Unwind_0055afab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
