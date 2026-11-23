// Unwind@0055ae68: ported from Pizza Connection 2 at 0x55ae68.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ae68
#include "pc2_port.h"

void Unwind_0055ae68(void)

{
  int unaff_EBP;
  
  CS_Delete((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x23c));
  return;
}
