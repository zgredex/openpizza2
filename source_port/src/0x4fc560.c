// Game_PurgeUnusedCompanyRecipes: ported from Pizza Connection 2 at 0x4fc560.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc560
#include "pc2_port.h"

void __fastcall Game_PurgeUnusedCompanyRecipes(int arg1)

{
  void *self;
  bool flag1;
  uint32_t *uptr2;
  int value3;
  int *local_8;
  int local_4;
  
  if (*(int *)(DAT_0057c670 + 0x290) != 5) {
    local_8 = (int *)(arg1 + 0x114);
    local_4 = 6;
    do {
      if ((local_8[1] != 0) && (*local_8 != 0)) {
        self = (void *)local_8[-0x29];
        value3 = *(int *)((intptr_t)self + 0x124) + -1;
        if (-1 < value3) {
          do {
            uptr2 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)self + 0x110),value3,(int *)0x0);
            flag1 = Game_IsRecordLinked(self,(intptr_t)uptr2);
            if (!flag1) {
              Company_RemoveRecipe(self,uptr2);
            }
            value3 = value3 + -1;
          } while (-1 < value3);
        }
      }
      local_8 = local_8 + 0x5a;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}
