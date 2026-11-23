// Unwind@0055aee8: ported from Pizza Connection 2 at 0x55aee8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aee8
#include "pc2_port.h"

void Unwind_0055aee8(void)

{
  int unaff_EBP;
  
  List_FreeAll((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}
