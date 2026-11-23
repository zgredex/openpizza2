// Unwind@00559510: ported from Pizza Connection 2 at 0x559510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559510
#include "pc2_port.h"

void Unwind_00559510(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
