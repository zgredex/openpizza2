// Game_HasObjectWithSourceId: ported from Pizza Connection 2 at 0x50bba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50bba0
#include "pc2_port.h"

uint32_t __fastcall Game_HasObjectWithSourceId(int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value1 = *(int *)(arg1 + 0x164);
  value2 = Game_CountObjectsByState(DAT_0057c670,-1);
  value4 = 0;
  if (0 < value2) {
    do {
      value3 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),value4,(int *)0x0);
      if ((*(int *)(value3 + 0x30) == 0x1d) && (*(int *)(value3 + 0x10c) == value1)) {
        return 1;
      }
      value4 = value4 + 1;
    } while (value4 < value2);
  }
  return 0;
}
