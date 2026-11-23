// Unwind@00558840: ported from Pizza Connection 2 at 0x558840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558840
#include "pc2_port.h"

void Unwind_00558840(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x61c));
  return;
}
