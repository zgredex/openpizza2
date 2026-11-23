// Unwind@0055b668: ported from Pizza Connection 2 at 0x55b668.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b668
#include "pc2_port.h"

void Unwind_0055b668(void)

{
  int unaff_EBP;
  
  List_FreeAll((uint32_t *)(*(int *)(unaff_EBP + -0x14) + 8));
  return;
}
