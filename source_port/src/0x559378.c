// Unwind@00559378: ported from Pizza Connection 2 at 0x559378.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559378
#include "pc2_port.h"

void Unwind_00559378(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x180));
  return;
}
