// Unwind@00559f3e: ported from Pizza Connection 2 at 0x559f3e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559f3e
#include "pc2_port.h"

void Unwind_00559f3e(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x140));
  return;
}
