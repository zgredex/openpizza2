// Game_IsPlayerBestInStat: ported from Pizza Connection 2 at 0x48e000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e000
#include "pc2_port.h"

uint32_t __thiscall Game_IsPlayerBestInStat(void *self,int *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)(arg1[arg3] + arg2 * 4);
  if (value1 != 0) {
    value3 = 0;
    while( true ) {
      value2 = Game_GetPlayerBySlot(self,value3);
      if (((value2 != 0) && (*(int *)(value2 + 0x48) != arg3)) &&
         (value1 < *(int *)(*arg1 + arg2 * 4))) break;
      value3 = value3 + 1;
      arg1 = arg1 + 1;
      if (5 < value3) {
        return 1;
      }
    }
  }
  return 0;
}
