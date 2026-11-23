// Unwind@00558eac: ported from Pizza Connection 2 at 0x558eac.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558eac
#include "pc2_port.h"

void Unwind_00558eac(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
