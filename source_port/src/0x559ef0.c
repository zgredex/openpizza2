// Unwind@00559ef0: ported from Pizza Connection 2 at 0x559ef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559ef0
#include "pc2_port.h"

void Unwind_00559ef0(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x114) + 0x11c));
  return;
}
