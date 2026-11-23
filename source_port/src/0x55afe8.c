// Unwind@0055afe8: ported from Pizza Connection 2 at 0x55afe8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55afe8
#include "pc2_port.h"

void Unwind_0055afe8(void)

{
  int unaff_EBP;
  
  Buffer_ReleaseField8(*(int *)(unaff_EBP + -0x10) + 0x3c);
  return;
}
