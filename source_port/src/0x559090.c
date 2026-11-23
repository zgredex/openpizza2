// Unwind@00559090: ported from Pizza Connection 2 at 0x559090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559090
#include "pc2_port.h"

void Unwind_00559090(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
