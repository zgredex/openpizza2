// Unwind@0055acce: ported from Pizza Connection 2 at 0x55acce.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55acce
#include "pc2_port.h"

void Unwind_0055acce(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x734));
  return;
}
