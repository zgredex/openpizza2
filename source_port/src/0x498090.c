// Mission_CheckGamePlanCategoryGoal: ported from Pizza Connection 2 at 0x498090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498090
#include "pc2_port.h"

void Mission_CheckGamePlanCategoryGoal(void)

{
  int value1;
  int value2;
  int value3;
  
                    /* Completes a mission goal when a game-plan category effect exceeds 70. */
  value3 = 0;
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  do {
    value2 = GamePlan_ComputeCategoryEffect(DAT_0057c9ec,*(int *)(value1 + 0x48),value3);
    if (0x46 < value2) {
      UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x1a,-1);
      MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x1a,-1,-1);
      return;
    }
    value3 = value3 + 1;
  } while (value3 < 7);
  return;
}
