// Building_ComputeOperatingRevenue: ported from Pizza Connection 2 at 0x4d6260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6260
#include "pc2_port.h"

int64_t __thiscall Building_ComputeOperatingRevenue(void *self,int arg1,int arg2)

{
  int64_t lvalue1;
  int local_114;
  int local_110;
  double local_10c;
  int local_104;
  uint32_t local_100 [64];
  
  Map_CountNearbyObjects(self,arg1,&local_104,&local_110,&local_114);
  local_10c = (double)local_110 * 0.25 + (double)local_104 * 0.1 + 1.0;
  if (local_114 != 0) {
    local_10c = local_10c * 1.75;
  }
  Game_CountProductUsageByCategory(DAT_0057c670,arg1,local_100);
  __ftol();
  if (arg2 != 0) {
    if (arg2 == 1) {
      lvalue1 = __ftol();
      return lvalue1;
    }
    if (arg2 == 2) {
      lvalue1 = __ftol();
      return lvalue1;
    }
  }
  lvalue1 = __ftol();
  return lvalue1;
}
