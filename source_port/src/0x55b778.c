// Unwind@0055b778: ported from Pizza Connection 2 at 0x55b778.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b778
#include "pc2_port.h"

void Unwind_0055b778(void)

{
  int unaff_EBP;
  
  CS_LeavePtr((uint32_t *)(unaff_EBP + 0xc));
  return;
}
