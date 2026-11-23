// Unwind@0055b020: ported from Pizza Connection 2 at 0x55b020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b020
#include "pc2_port.h"

void Unwind_0055b020(void)

{
  int unaff_EBP;
  
  List_FreeAll((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}
