// GamePlan_UpdateEffectBars: ported from Pizza Connection 2 at 0x4c39f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c39f0
#include "pc2_port.h"

void __cdecl GamePlan_UpdateEffectBars(void *arg1,int arg2)

{
  int value1;
  int value2;
  
                    /* Fills the game-plan category-effect bars. */
  value2 = 0;
  do {
    value1 = GamePlan_ComputeCategoryEffect(DAT_0057da14,*(int *)(arg2 + 0x48),value2);
    value1 = Math_PiecewiseLinear(value1);
    Rating_UpdateBarByKey(arg1,0x509,value2,value1,DAT_00582858);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
