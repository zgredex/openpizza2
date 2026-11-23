// Unwind@0055857c: ported from Pizza Connection 2 at 0x55857c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55857c
#include "pc2_port.h"

void Unwind_0055857c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
