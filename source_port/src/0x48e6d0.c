// Branch_UpdateStarRating: ported from Pizza Connection 2 at 0x48e6d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e6d0
#include "pc2_port.h"

void __cdecl Branch_UpdateStarRating(void *arg1)

{
  int value1;
  int value2;
  
                    /* Shows the branch's star sprites for its rating. */
  value1 = 0;
  value2 = *(int *)(*(int *)(DAT_0057c670 + 0x9c) + 0x14b4);
  if (0 < value2) {
    do {
      UI_ShowChildByID(arg1,value1 + 0x1f49);
      value1 = value1 + 1;
    } while (value1 < value2);
  }
  for (; value2 < 5; value2 = value2 + 1) {
    UI_RemoveObjectByKey(arg1,value2 + 0x1f49);
  }
  return;
}
