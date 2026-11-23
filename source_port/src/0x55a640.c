// Unwind@0055a640: ported from Pizza Connection 2 at 0x55a640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a640
#include "pc2_port.h"

void Unwind_0055a640(void)

{
  int unaff_EBP;
  
  NamedLockable_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1cc));
  return;
}
