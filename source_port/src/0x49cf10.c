// CompanyRating_UpdateScoreText: ported from Pizza Connection 2 at 0x49cf10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49cf10
#include "pc2_port.h"

void __cdecl CompanyRating_UpdateScoreText(void *arg1)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  Gadget_SetTextf(arg1,0x465,(uint8_t *)s__d__s_00568324,*(uint32_t *)(value1 + 0x114c));
  return;
}
