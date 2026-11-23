// Game_UpgradeProductionLevel: ported from Pizza Connection 2 at 0x4e3660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3660
#include "pc2_port.h"

uint32_t __fastcall Game_UpgradeProductionLevel(int arg1)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  bool flag4;
  int local_4;
  
  flag4 = arg1 == *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_4 = Game_ComputeActionCost(arg1);
  if (local_4 != 0) {
    if ((flag4) && (*(int *)(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8) + 0x180) != 0)) {
      local_4 = (local_4 * 0xf) / 10;
    }
    uvalue3 = Game_CanAffordWithCurrency((void *)arg1,10,(float)local_4,'\x01',0xffffffff);
    if ((char)uvalue3 == '\0') {
      return 0;
    }
    if (flag4) {
      value1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      value2 = *(int *)(value1 + 0x180);
      if (value2 != 0) {
        *(int *)(value1 + 0x180) = value2 + -1;
      }
    }
    Game_AdvanceProductionCounter(arg1);
  }
  return 1;
}
