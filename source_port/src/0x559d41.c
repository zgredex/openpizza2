// Unwind@00559d41: ported from Pizza Connection 2 at 0x559d41.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559d41
#include "pc2_port.h"

void Unwind_00559d41(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
