// Unwind@0055ba74: ported from Pizza Connection 2 at 0x55ba74.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ba74
#include "pc2_port.h"

void Unwind_0055ba74(void)

{
  int unaff_EBP;
  
  if ((*(uint32_t *)(unaff_EBP + -0x10) & 1) == 0) {
    return;
  }
  CRT_Ios_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}
