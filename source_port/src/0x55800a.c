// Unwind@0055800a: ported from Pizza Connection 2 at 0x55800a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55800a
#include "pc2_port.h"

void Unwind_0055800a(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x1728));
  return;
}
