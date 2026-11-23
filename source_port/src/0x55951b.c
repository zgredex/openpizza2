// Unwind@0055951b: ported from Pizza Connection 2 at 0x55951b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55951b
#include "pc2_port.h"

void Unwind_0055951b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
