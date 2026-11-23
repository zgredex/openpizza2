// Unwind@0055936a: ported from Pizza Connection 2 at 0x55936a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55936a
#include "pc2_port.h"

void Unwind_0055936a(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x164));
  return;
}
