// Unwind@00559ddb: ported from Pizza Connection 2 at 0x559ddb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559ddb
#include "pc2_port.h"

void Unwind_00559ddb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
