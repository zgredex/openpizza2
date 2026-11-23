// Unwind@0055974b: ported from Pizza Connection 2 at 0x55974b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55974b
#include "pc2_port.h"

void Unwind_0055974b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
