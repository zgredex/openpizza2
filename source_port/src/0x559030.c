// Unwind@00559030: ported from Pizza Connection 2 at 0x559030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559030
#include "pc2_port.h"

void Unwind_00559030(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
