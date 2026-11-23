// Unwind@0055b328: ported from Pizza Connection 2 at 0x55b328.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b328
#include "pc2_port.h"

void Unwind_0055b328(void)

{
  int unaff_EBP;
  
  CS_LeavePtr((uint32_t *)(unaff_EBP + 8));
  return;
}
