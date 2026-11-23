// Unwind@0055b48e: ported from Pizza Connection 2 at 0x55b48e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b48e
#include "pc2_port.h"

void Unwind_0055b48e(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(uint32_t *)(unaff_EBP + -0x7c) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x10) + 0x50;
  }
  List_FreeAll(*(uint32_t **)(unaff_EBP + -0x7c));
  return;
}
