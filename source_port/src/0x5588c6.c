// Unwind@005588c6: ported from Pizza Connection 2 at 0x5588c6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5588c6
#include "pc2_port.h"

void Unwind_005588c6(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
