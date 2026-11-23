// Unwind@0055852b: ported from Pizza Connection 2 at 0x55852b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55852b
#include "pc2_port.h"

void Unwind_0055852b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
