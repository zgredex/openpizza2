// Unwind@0055b463: ported from Pizza Connection 2 at 0x55b463.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b463
#include "pc2_port.h"

void Unwind_0055b463(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 4) {
    *(uint32_t *)(unaff_EBP + -0x18) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x10) + 0x18;
  }
  SoundMixerThread_Destroy(*(uint32_t **)(unaff_EBP + -0x18));
  return;
}
