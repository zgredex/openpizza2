// Unwind@0055aec8: ported from Pizza Connection 2 at 0x55aec8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aec8
#include "pc2_port.h"

void Unwind_0055aec8(void)

{
  int unaff_EBP;
  
  List_FreeAll((uint32_t *)(*(int *)(unaff_EBP + -0x24) + 0x38));
  return;
}
