// Unwind@00559ec8: ported from Pizza Connection 2 at 0x559ec8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559ec8
#include "pc2_port.h"

void Unwind_00559ec8(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x120));
  return;
}
