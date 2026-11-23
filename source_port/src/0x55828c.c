// Unwind@0055828c: ported from Pizza Connection 2 at 0x55828c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55828c
#include "pc2_port.h"

void Unwind_0055828c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
