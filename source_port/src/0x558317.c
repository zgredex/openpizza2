// Unwind@00558317: ported from Pizza Connection 2 at 0x558317.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558317
#include "pc2_port.h"

void Unwind_00558317(void)

{
  int unaff_EBP;
  
  UI_BriefingList_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x10) + 0x304));
  return;
}
