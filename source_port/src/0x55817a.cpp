// Unwind@0055817a: ported from Pizza Connection 2 at 0x55817a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55817a
#include "pc2_port.h"

void Unwind_0055817a(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
