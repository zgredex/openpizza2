// Unwind@00559eac: ported from Pizza Connection 2 at 0x559eac.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559eac
#include "pc2_port.h"

void Unwind_00559eac(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x120));
  return;
}
