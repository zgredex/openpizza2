// Unwind@0055b110: ported from Pizza Connection 2 at 0x55b110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b110
#include "pc2_port.h"

void Unwind_0055b110(void)

{
  int unaff_EBP;
  
  CS_LeavePtr((uint32_t *)(unaff_EBP + 4));
  return;
}
