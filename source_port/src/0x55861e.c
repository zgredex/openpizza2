// Unwind@0055861e: ported from Pizza Connection 2 at 0x55861e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55861e
#include "pc2_port.h"

void Unwind_0055861e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x368));
  return;
}
