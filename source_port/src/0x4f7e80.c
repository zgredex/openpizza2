// Company_HireFreeGuard: ported from Pizza Connection 2 at 0x4f7e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7e80
#include "pc2_port.h"

uint32_t Company_HireFreeGuard(void *arg1)

{
  int value1;
  
                    /* Claims a free guard and registers it in the company assignment list. */
  value1 = Game_CountFreeSlots(DAT_0057c670,0x17);
  if (value1 == 0) {
    return 0;
  }
  value1 = Game_FindFreeObjectByType(DAT_0057c670,0x17);
  if (value1 == 0) {
    return 0;
  }
  Company_AddStaffMember(arg1,*(int *)(value1 + 0x164),0x17);
  return 1;
}
