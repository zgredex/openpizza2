// RecipeEdit_UpdateRatingBars: ported from Pizza Connection 2 at 0x49d6f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d6f0
#include "pc2_port.h"

void __cdecl RecipeEdit_UpdateRatingBars(void *arg1)

{
  int value1;
  int value2;
  
                    /* Recomputes a recipe and fills its eight category rating bars. */
  if (DAT_0057cac4 == (void *)0x0) {
    value1 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x4df,value1,0,0);
      value1 = value1 + 1;
    } while (value1 < 8);
    return;
  }
  value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  Recipe_RecomputeAllStats(DAT_0057cac4,value1);
  value1 = 0;
  do {
    value2 = Game_MapInputIndex(DAT_0057cac4,value1);
    Rating_UpdateBarByKey(arg1,0x4df,value1,value2,DAT_0058155c);
    value1 = value1 + 1;
  } while (value1 < 8);
  return;
}
