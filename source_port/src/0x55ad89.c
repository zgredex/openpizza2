// Unwind@0055ad89: ported from Pizza Connection 2 at 0x55ad89.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ad89
#include "pc2_port.h"

void Unwind_0055ad89(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x348));
  return;
}
