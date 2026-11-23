// UI_BriefingList_Save: ported from Pizza Connection 2 at 0x54b1b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b1b0
#include "pc2_port.h"

void __thiscall UI_BriefingList_Save(void *self,void *arg1)

{
  void *this_00;
  uint32_t *uptr1;
  int value2;
  int local_8;
  int local_4;
  
  this_00 = arg1;
  local_8 = *(int *)((intptr_t)self + 0x18);
  CRT_Ostream_Write(arg1,&local_8,4);
  value2 = 0;
  if (0 < local_8) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)self + 4),value2,&local_4);
      arg1 = (void *)*uptr1;
      CRT_Ostream_Write(this_00,&local_4,4);
      CRT_Ostream_Write(this_00,&arg1,4);
      CRT_Ostream_Write(this_00,uptr1,arg1);
      value2 = value2 + 1;
    } while (value2 < local_8);
  }
  return;
}
