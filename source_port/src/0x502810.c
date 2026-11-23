// Game_IsInputIndexUsed: ported from Pizza Connection 2 at 0x502810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502810
#include "pc2_port.h"

uint32_t Game_IsInputIndexUsed(int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  void *self;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  
  value5 = 0;
  uvalue1 = *(uint32_t *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uvalue2 = *(uint32_t *)(uvalue1 + 0x124);
  uvalue4 = uvalue1;
  if (0 < (intptr_t)uvalue2) {
    do {
      self = (void *)IDMap_Lookup((void *)(uvalue1 + 0x110),value5,(int *)0x0);
      value6 = 0;
      do {
        value3 = Game_MapInputIndex(self,value6);
        if (arg1 < value3) {
          return CONCAT31((int3)((uint32_t)value3 >> 8),1);
        }
        value6 = value6 + 1;
      } while (value6 < 8);
      value5 = value5 + 1;
      uvalue4 = uvalue2;
    } while (value5 < (intptr_t)uvalue2);
  }
  return uvalue4 & 0xffffff00;
}
