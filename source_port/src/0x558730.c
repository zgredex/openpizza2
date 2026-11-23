// Unwind@00558730: ported from Pizza Connection 2 at 0x558730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558730
#include "pc2_port.h"

void Unwind_00558730(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x228));
  return;
}
