// Unwind@00558780: ported from Pizza Connection 2 at 0x558780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558780
#include "pc2_port.h"

void Unwind_00558780(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x118));
  return;
}
