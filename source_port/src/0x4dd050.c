// Game_RemoveRecordFromAllLocalMaps: ported from Pizza Connection 2 at 0x4dd050.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd050
#include "pc2_port.h"

void __thiscall Game_RemoveRecordFromAllLocalMaps(void *self,void *arg1)

{
  int value1;
  void *this_00;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0xfc0);
  value2 = 0;
  if (0 < value1) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0xfac),value2,(int *)0x0);
      Game_RemoveRecordFromLocalMap(this_00,arg1);
      value2 = value2 + 1;
    } while (value2 < value1);
  }
  return;
}
