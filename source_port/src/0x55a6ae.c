// Unwind@0055a6ae: ported from Pizza Connection 2 at 0x55a6ae.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a6ae
#include "pc2_port.h"

void Unwind_0055a6ae(void)

{
  int unaff_EBP;
  
  Array_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x8324));
  return;
}
