// Unwind@00557d30: ported from Pizza Connection 2 at 0x557d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557d30
#include "pc2_port.h"

void Unwind_00557d30(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
