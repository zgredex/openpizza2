// Unwind@0055b008: ported from Pizza Connection 2 at 0x55b008.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b008
#include "pc2_port.h"

void Unwind_0055b008(void)

{
  int unaff_EBP;
  
  Buffer_ReleaseField8(*(int *)(unaff_EBP + -0x10) + 0x3c);
  return;
}
