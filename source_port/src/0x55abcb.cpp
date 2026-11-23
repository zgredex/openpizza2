// Unwind@0055abcb: ported from Pizza Connection 2 at 0x55abcb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55abcb
#include "pc2_port.h"

void Unwind_0055abcb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
