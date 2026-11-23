// Unwind@0055943c: ported from Pizza Connection 2 at 0x55943c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55943c
#include "pc2_port.h"

void Unwind_0055943c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
