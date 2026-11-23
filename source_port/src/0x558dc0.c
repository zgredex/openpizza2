// Unwind@00558dc0: ported from Pizza Connection 2 at 0x558dc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558dc0
#include "pc2_port.h"

void Unwind_00558dc0(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x114) + 0xfac));
  return;
}
