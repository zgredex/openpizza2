// Unwind@0055a3db: ported from Pizza Connection 2 at 0x55a3db.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a3db
#include "pc2_port.h"

void Unwind_0055a3db(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
