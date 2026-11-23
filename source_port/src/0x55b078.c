// Unwind@0055b078: ported from Pizza Connection 2 at 0x55b078.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b078
#include "pc2_port.h"

void Unwind_0055b078(void)

{
  int unaff_EBP;
  
  List_FreeAll((uint32_t *)(*(int *)(unaff_EBP + -0x88) + 0x54));
  return;
}
