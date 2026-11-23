// Unwind@005588d1: ported from Pizza Connection 2 at 0x5588d1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5588d1
#include "pc2_port.h"

void Unwind_005588d1(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
