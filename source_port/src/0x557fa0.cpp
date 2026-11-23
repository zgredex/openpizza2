// Unwind@00557fa0: ported from Pizza Connection 2 at 0x557fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557fa0
#include "pc2_port.h"

void Unwind_00557fa0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}
