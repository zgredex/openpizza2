// Unwind@00557ffc: ported from Pizza Connection 2 at 0x557ffc.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557ffc
#include "pc2_port.h"

void Unwind_00557ffc(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x16f8));
  return;
}
