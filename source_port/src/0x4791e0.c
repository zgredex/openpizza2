// Stats_ComputeBestPairShareAverage: ported from Pizza Connection 2 at 0x4791e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4791e0
#include "pc2_port.h"

void __fastcall Stats_ComputeBestPairShareAverage(void *arg1)

{
  int value1;
  int value2;
  int value3;
  int local_8;
  int local_4;
  
  value1 = Game_CountPlayersByByte(arg1,1);
  if (value1 < 1) {
    value1 = 0;
  }
  else {
    Game_FindBestPlayerRecordPair(arg1,1,&local_4,&local_8);
    value2 = Game_CountRecordsByPair(arg1,local_4,local_8);
    value1 = (value2 * 100) / value1;
  }
  value2 = Game_CountPlayersByByte(arg1,2);
  if (value2 < 1) {
    value2 = 0;
  }
  else {
    Game_FindBestPlayerRecordPair(arg1,2,&local_4,&local_8);
    value3 = Game_CountRecordsByPair(arg1,local_4,local_8);
    value2 = (value3 * 100) / value2;
  }
  *(int *)((intptr_t)arg1 + 0x1850) = (value2 + value1) / 2;
  Clamp_0_100((int *)((intptr_t)arg1 + 0x1850));
  return;
}
