// Unwind@005591eb: ported from Pizza Connection 2 at 0x5591eb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5591eb
#include "pc2_port.h"

void Unwind_005591eb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
