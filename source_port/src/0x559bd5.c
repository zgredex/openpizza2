// Unwind@00559bd5: ported from Pizza Connection 2 at 0x559bd5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559bd5
#include "pc2_port.h"

void Unwind_00559bd5(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
