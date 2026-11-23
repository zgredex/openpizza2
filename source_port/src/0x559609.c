// Unwind@00559609: ported from Pizza Connection 2 at 0x559609.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559609
#include "pc2_port.h"

void Unwind_00559609(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
