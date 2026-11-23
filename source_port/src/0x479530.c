// Map_CountEdgeMatchedTiles: ported from Pizza Connection 2 at 0x479530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479530
#include "pc2_port.h"

int __thiscall Map_CountEdgeMatchedTiles(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  short *psVar4;
  int local_c;
  int local_8;
  int local_4;
  
  value2 = 0;
  local_c = 0;
  psVar4 = (short *)(arg1 + 0xc);
  do {
    value3 = 0;
    do {
      if ((((psVar4[-4] == 1) && (*psVar4 == 1)) && (psVar4[0x13c] == 1)) && (psVar4[0x140] == 1)) {
        Map_GridToScreenOffset(*(void **)((intptr_t)self + 0x14e0),value3,value2,&local_4,&local_8);
        value1 = Game_FindRecordByPair(self,local_4,local_8);
        if (value1 != 0) {
          value1 = Map_CheckTileEdgeMatch(self,value2,value3,value1,arg1);
          if (value1 != 0) {
            local_c = local_c + 1;
          }
        }
      }
      value3 = value3 + 1;
      psVar4 = psVar4 + 4;
    } while (value3 < 0x50);
    value2 = value2 + 1;
  } while (value2 < 0x50);
  return local_c;
}
