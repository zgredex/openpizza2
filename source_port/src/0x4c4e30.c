// Window_UpdatePolicePage: ported from Pizza Connection 2 at 0x4c4e30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c4e30
#include "pc2_port.h"

void __cdecl Window_UpdatePolicePage(void *arg1)

{
                    /* Updates the police/security page's budget and equipment. */
  DAT_0057dcf8 = *(uint32_t *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  DAT_0057dcf4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  Gadget_SetTextf(arg1,0x1fee,(uint8_t *)s___d___0056aef4,1000);
  Gadget_SetTextf(arg1,0x1fef,(uint8_t *)s___d___00568730,1000);
  Sound_ProcessEvent(DAT_0057ba0c,0xd,0,'\x01');
  PolicePage_FillContributionStats(arg1);
  return;
}
