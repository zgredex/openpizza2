// Stats_ComputeTypeThreeShare: ported from Pizza Connection 2 at 0x479a40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479a40
#include "pc2_port.h"

void __fastcall Stats_ComputeTypeThreeShare(void *arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  
  value2 = Game_CountPlayersByByte(arg1,1);
  value3 = Game_CountPlayersByByte(arg1,2);
  value4 = Game_CountPlayersByByte(arg1,4);
  value5 = Game_CountPlayersByByte(arg1,3);
  value6 = Game_CountRecordsByByteC(arg1,3);
  value2 = value2 + value3 + value4 + value5 + value6;
  ptr1 = (int *)((intptr_t)arg1 + 0x1868);
  if (value2 < 1) {
    *ptr1 = 0;
    Clamp_0_100(ptr1);
    return;
  }
  *ptr1 = (value6 * 100) / value2;
  Clamp_0_100(ptr1);
  return;
}
