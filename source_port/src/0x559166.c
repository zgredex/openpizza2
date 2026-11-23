// Unwind@00559166: ported from Pizza Connection 2 at 0x559166.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559166
#include "pc2_port.h"

void Unwind_00559166(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x118));
  return;
}
