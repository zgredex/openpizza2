// Unwind@00559fac: ported from Pizza Connection 2 at 0x559fac.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559fac
#include "pc2_port.h"

void Unwind_00559fac(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x438));
  return;
}
