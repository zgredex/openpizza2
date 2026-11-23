// Game_GetPreviousPlayerSlot: ported from Pizza Connection 2 at 0x486ec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486ec0
#include "pc2_port.h"

int __thiscall Game_GetPreviousPlayerSlot(void *self,int arg1,char arg2)

{
  int value1;
  int value2;
  bool flag3;
  
  value1 = arg1 + -1;
  if (value1 != -1) {
    do {
      flag3 = arg1 < 0;
      arg1 = value1;
      if (SBORROW4(value1,-1) != flag3) {
        arg1 = 5;
      }
      value1 = Game_GetPlayerBySlot(self,arg1);
      if ((value1 != 0) &&
         ((arg2 != '\0' ||
          (value1 = *(int *)(value1 + 0x48), value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self),
          value1 != value2)))) {
        return arg1;
      }
      value1 = arg1 + -1;
    } while (arg1 != 0);
  }
  return -1;
}
