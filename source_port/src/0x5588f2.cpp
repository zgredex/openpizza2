// Unwind@005588f2: ported from Pizza Connection 2 at 0x5588f2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5588f2
#include "pc2_port.h"

void Unwind_005588f2(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
