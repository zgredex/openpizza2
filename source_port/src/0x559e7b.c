// Unwind@00559e7b: ported from Pizza Connection 2 at 0x559e7b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559e7b
#include "pc2_port.h"

void Unwind_00559e7b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
