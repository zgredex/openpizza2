// Unwind@0055af08: ported from Pizza Connection 2 at 0x55af08.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55af08
#include "pc2_port.h"

void Unwind_0055af08(void)

{
  int unaff_EBP;
  
  List_FreeAll((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}
