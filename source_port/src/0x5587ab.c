// Unwind@005587ab: ported from Pizza Connection 2 at 0x5587ab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5587ab
#include "pc2_port.h"

void Unwind_005587ab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
