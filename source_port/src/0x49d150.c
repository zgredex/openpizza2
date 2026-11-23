// Game_GetNthFreePlayerSlot: ported from Pizza Connection 2 at 0x49d150.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d150
#include "pc2_port.h"

int __cdecl Game_GetNthFreePlayerSlot(int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value3 = 0;
  value2 = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value2);
    if ((value1 != 0) && (*(int *)(value1 + 0x50) == 0)) {
      if (value3 == arg1) {
        return value2;
      }
      value3 = value3 + 1;
    }
    value2 = value2 + 1;
  } while (value2 < 6);
  return -1;
}
