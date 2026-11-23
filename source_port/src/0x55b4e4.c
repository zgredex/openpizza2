// Unwind@0055b4e4: ported from Pizza Connection 2 at 0x55b4e4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b4e4
#include "pc2_port.h"

void Unwind_0055b4e4(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(uint32_t *)(unaff_EBP + -0x5c) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x10) + 0x70;
  }
  List_FreeAll(*(uint32_t **)(unaff_EBP + -0x5c));
  return;
}
