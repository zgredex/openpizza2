// Unwind@00559855: ported from Pizza Connection 2 at 0x559855.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559855
#include "pc2_port.h"

void Unwind_00559855(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
