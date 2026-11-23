// Unwind@00557fc0: ported from Pizza Connection 2 at 0x557fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557fc0
#include "pc2_port.h"

void Unwind_00557fc0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x20));
  return;
}
