// Unwind@00559863: ported from Pizza Connection 2 at 0x559863.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559863
#include "pc2_port.h"

void Unwind_00559863(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
