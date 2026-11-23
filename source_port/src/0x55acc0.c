// Unwind@0055acc0: ported from Pizza Connection 2 at 0x55acc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55acc0
#include "pc2_port.h"

void Unwind_0055acc0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x734));
  return;
}
