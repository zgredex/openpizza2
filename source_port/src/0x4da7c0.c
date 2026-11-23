// Game_RecordPlayerStat: ported from Pizza Connection 2 at 0x4da7c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da7c0
#include "pc2_port.h"

void __thiscall Game_RecordPlayerStat(void *self,int arg1)

{
  void *this_00;
  int *ptr1;
  int value2;
  void *local_4;
  
  local_4 = self;
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,arg1);
  AI_GetTopActionIndices(this_00,(int *)&local_4,&arg1);
  ptr1 = (int *)((intptr_t)self + 0xfec);
  value2 = 8;
  do {
    ptr1[-2] = *ptr1;
    ptr1[-1] = (intptr_t)local_4;
    *ptr1 = arg1;
    ptr1 = ptr1 + 6;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
