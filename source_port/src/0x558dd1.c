// Unwind@00558dd1: ported from Pizza Connection 2 at 0x558dd1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558dd1
#include "pc2_port.h"

void Unwind_00558dd1(void)

{
  int unaff_EBP;
  
  List_Node_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x114) + 0xfc8));
  return;
}
