// Unwind@00559f60: ported from Pizza Connection 2 at 0x559f60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559f60
#include "pc2_port.h"

void Unwind_00559f60(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x11c));
  return;
}
