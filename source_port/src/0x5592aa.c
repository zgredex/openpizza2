// Unwind@005592aa: ported from Pizza Connection 2 at 0x5592aa.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5592aa
#include "pc2_port.h"

void Unwind_005592aa(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x164));
  return;
}
