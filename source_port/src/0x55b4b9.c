// Unwind@0055b4b9: ported from Pizza Connection 2 at 0x55b4b9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b4b9
#include "pc2_port.h"

void Unwind_0055b4b9(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(uint32_t *)(unaff_EBP + -0x6c) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x10) + 0x60;
  }
  List_FreeAll(*(uint32_t **)(unaff_EBP + -0x6c));
  return;
}
