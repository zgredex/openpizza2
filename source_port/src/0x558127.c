// Unwind@00558127: ported from Pizza Connection 2 at 0x558127.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558127
#include "pc2_port.h"

void Unwind_00558127(void)

{
  int unaff_EBP;
  
  UI_BriefingList_Destroy((uint32_t *)(*(int *)(unaff_EBP + -0x14) + 0x304));
  return;
}
