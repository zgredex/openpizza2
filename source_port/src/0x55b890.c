// Unwind@0055b890: ported from Pizza Connection 2 at 0x55b890.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b890
#include "pc2_port.h"

void Unwind_0055b890(void)

{
  int unaff_EBP;
  
  NamedLockable_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x178));
  return;
}
