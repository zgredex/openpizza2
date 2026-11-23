// Player_HasRecordWithField30: ported from Pizza Connection 2 at 0x4da6b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da6b0
#include "pc2_port.h"

uint32_t Player_HasRecordWithField30(int arg1,int arg2)

{
  void *self;
  int value1;
  uint32_t uvalue2;
  int value3;
  
  uvalue2 = Game_GetPlayerBySlot(DAT_0057c670,arg2);
  value1 = *(int *)(uvalue2 + 0x194);
  value3 = 0;
  if (0 < value1) {
    self = (void *)(uvalue2 + 0x180);
    do {
      uvalue2 = IDMap_Lookup(self,value3,(int *)0x0);
      if (*(int *)(uvalue2 + 0x30) == arg1) {
        return CONCAT31((int3)(uvalue2 >> 8),1);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return uvalue2 & 0xffffff00;
}
