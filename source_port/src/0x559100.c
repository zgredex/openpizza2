// Unwind@00559100: ported from Pizza Connection 2 at 0x559100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559100
#include "pc2_port.h"

void Unwind_00559100(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
