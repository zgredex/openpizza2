// Storage_SaveRecord: ported from Pizza Connection 2 at 0x513e50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513e50
#include "pc2_port.h"

void __thiscall Storage_SaveRecord(void *self,void *arg1)

{
  void *this_00;
  void *this_01;
  uint32_t uvalue1;
  int value2;
  void *local_4;
  
  this_00 = arg1;
  local_4 = self;
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,0x1e);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x24,4);
  CRT_Ostream_Write(this_00,(int *)((intptr_t)self + 0x28),4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x38,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x3c,1);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x40,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x30,4);
  this_01 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  local_4 = (void *)Array_FindIndexByPtr(this_01,*(int *)((intptr_t)self + 0x34));
  CRT_Ostream_Write(this_00,&local_4,4);
  arg1 = *(void **)((intptr_t)self + 0x58);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      uvalue1 = IDMap_Lookup((void *)((intptr_t)self + 0x44),value2,(int *)0x0);
      CRT_Ostream_Write(this_00,uvalue1,0x20);
      value2 = value2 + 1;
    } while (value2 < (intptr_t)arg1);
  }
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x60,0xf0);
  return;
}
