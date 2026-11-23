// CompanyMenu_InitBranchOverview: ported from Pizza Connection 2 at 0x4a36d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a36d0
#include "pc2_port.h"

void __cdecl CompanyMenu_InitBranchOverview(void *arg1)

{
                    /* Initializes the company branch-overview page. */
  DAT_00568ef0 = 0xffffffff;
  DAT_00568ef4 = 0xffffffff;
  DAT_0057d01c = 0;
  DAT_0057d014 = Game_CountAssignedAssetSlots(DAT_0057c670,&DAT_00568ef0,&DAT_00568ef4);
  DAT_0057d018 = 1;
  HeadquartersPanel_UpdateStaffCosts(arg1);
  return;
}
