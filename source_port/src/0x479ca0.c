// Stats_UpdateAverages: ported from Pizza Connection 2 at 0x479ca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479ca0
#include "pc2_port.h"

void __thiscall Stats_UpdateAverages(void *self,int arg1)

{
  int value1;
  int value2;
  int64_t lvalue3;
  
  value1 = Map_CountEdgeMatchedTiles(self,arg1);
  value2 = Game_CountPlayersByByte(self,1);
  value2 = value2 - value1;
  if (0 < value2) {
    do {
      value2 = value2 + -1;
    } while (value2 != 0);
  }
  Game_CountPlayersByByte(self,1);
  Game_CountPlayersByByte(self,2);
  City_HasRoomForBuilding(self);
  value1 = *(int *)((intptr_t)self + 0x187c);
  if (0 < value1) {
    do {
      value1 = value1 + -1;
    } while (value1 != 0);
  }
  Grid_ScoreRuns(arg1);
  lvalue3 = __ftol();
  *(int *)((intptr_t)self + 0x1878) = (intptr_t)lvalue3;
  if ((intptr_t)lvalue3 < 0) {
    *(uint32_t *)((intptr_t)self + 0x1878) = 0;
  }
  return;
}
