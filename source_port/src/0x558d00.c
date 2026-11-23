// Unwind@00558d00: ported from Pizza Connection 2 at 0x558d00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558d00
#include "pc2_port.h"

void Unwind_00558d00(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x58));
  return;
}
