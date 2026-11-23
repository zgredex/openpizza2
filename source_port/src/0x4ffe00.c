// Game_RefreshObjectCategoryBins: ported from Pizza Connection 2 at 0x4ffe00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffe00
#include "pc2_port.h"

void Game_RefreshObjectCategoryBins(void *arg1)

{
  int *ptr1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int local_20 [8];
  
  ptr1 = local_20;
  for (value2 = 8; value2 != 0; value2 = value2 + -1) {
    *ptr1 = 0;
    ptr1 = ptr1 + 1;
  }
  value2 = Game_CountObjectsByType(arg1,0xffffffff);
  value5 = 0;
  if (0 < value2) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value5,(int *)0x0);
      if (*(char *)(*ptr1 + 0x824) == '\0') {
        uvalue3 = ptr1[1];
        value4 = 3;
        do {
          local_20[uvalue3 & 7] = local_20[uvalue3 & 7] + 1;
          uvalue3 = uvalue3 + 1;
          value4 = value4 + -1;
        } while (value4 != 0);
      }
      value5 = value5 + 1;
    } while (value5 < value2);
  }
  ptr1 = local_20;
  value5 = 7;
  value2 = local_20[0];
  do {
    ptr1 = ptr1 + 1;
    if (value2 <= *ptr1) {
      value2 = *ptr1;
    }
    value5 = value5 + -1;
  } while (value5 != 0);
  value5 = Game_CountPlayersByByte(arg1,5);
  if (value5 < value2 / 2) {
    Game_MarkAllObjectsDirty(arg1,2);
  }
  return;
}
