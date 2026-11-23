// Game_GetPlayerCount: ported from Pizza Connection 2 at 0x482720.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482720
#include "pc2_port.h"

int __fastcall Game_GetPlayerCount(int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  
  value1 = 0;
  ptr2 = (int *)(arg1 + 0x200);
  value3 = 6;
  do {
    if (*ptr2 != 0) {
      value1 = value1 + 1;
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  return value1;
}
