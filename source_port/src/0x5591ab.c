// Unwind@005591ab: ported from Pizza Connection 2 at 0x5591ab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5591ab
#include "pc2_port.h"

void Unwind_005591ab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
