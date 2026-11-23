// Unwind@0055b438: ported from Pizza Connection 2 at 0x55b438.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b438
#include "pc2_port.h"

void Unwind_0055b438(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(uint32_t *)(unaff_EBP + -0x80) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x10) + 0x10;
  }
  DirectSoundBuffer_Destructor(*(uint32_t **)(unaff_EBP + -0x80));
  return;
}
