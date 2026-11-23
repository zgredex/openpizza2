// Unwind@00559050: ported from Pizza Connection 2 at 0x559050.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559050
#include "pc2_port.h"

void Unwind_00559050(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x38));
  return;
}
