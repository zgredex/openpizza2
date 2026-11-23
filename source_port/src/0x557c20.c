// Unwind@00557c20: ported from Pizza Connection 2 at 0x557c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c20
#include "pc2_port.h"

void Unwind_00557c20(void)

{
  int unaff_EBP;
  
  NamedLockable_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1688));
  return;
}
