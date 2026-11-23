// Unwind@005580fb: ported from Pizza Connection 2 at 0x5580fb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5580fb
#include "pc2_port.h"

void Unwind_005580fb(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x14) + 0x20));
  return;
}
