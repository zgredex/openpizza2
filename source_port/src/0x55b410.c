// Unwind@0055b410: ported from Pizza Connection 2 at 0x55b410.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b410
#include "pc2_port.h"

void Unwind_0055b410(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(uint32_t *)(unaff_EBP + -0x14) = 0;
  }
  else {
    *(uint32_t *)(unaff_EBP + -0x14) = *(uint32_t *)(unaff_EBP + -0x10);
  }
  SoundBuffer_DestructBase(*(uint32_t **)(unaff_EBP + -0x14));
  return;
}
