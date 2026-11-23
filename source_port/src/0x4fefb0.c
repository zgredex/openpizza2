// AI_Annoy_SendGangsterGroup: ported from Pizza Connection 2 at 0x4fefb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fefb0
#include "pc2_port.h"

uint32_t __thiscall AI_Annoy_SendGangsterGroup(void *self,void *arg1,int arg2)

{
  bool flag1;
  uint32_t uvalue2;
  int value3;
  uint32_t extraout_var;
  uint32_t uvalue4;
  int value5;
  uint32_t local_4;
  
                    /* Sends a group of gangsters to harass a branch. */
  local_4 = 0;
  Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg2 + 0x30));
  uvalue2 = AI_CountAvailableTargets(arg1,0x1e);
  if (uvalue2 != 0) {
    value3 = AI_OpenBranchesInCity(self,arg1,arg2);
    if (value3 != 0) {
      if ((intptr_t)uvalue2 < 4) {
        uvalue2 = 3;
      }
      uvalue2 = Random_RangeFast(1,uvalue2);
      flag1 = Math_CompareRounded();
      if (CONCAT31(extraout_var,flag1) == 0) {
        return 2;
      }
      if (0 < (intptr_t)uvalue2) {
        do {
          uvalue4 = AI_HireCourier(arg1,arg2);
          local_4 = local_4 | uvalue4;
          uvalue2 = uvalue2 - 1;
        } while (uvalue2 != 0);
        if (local_4 != 0) {
          value3 = *(int *)(arg2 + 0x30);
          value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
          if (value3 == value5) {
            Sound_SetTimeout(DAT_0057ba0c);
          }
        }
      }
    }
  }
  return 1;
}
