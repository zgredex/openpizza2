// Unwind@00559e70: ported from Pizza Connection 2 at 0x559e70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559e70
#include "pc2_port.h"

void Unwind_00559e70(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
