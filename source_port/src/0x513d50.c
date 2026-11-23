// Storage_LoadRecord: ported from Pizza Connection 2 at 0x513d50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513d50
#include "pc2_port.h"

void __thiscall Storage_LoadRecord(void *self,void *arg1)

{
  void *this_00;
  int value1;
  uint32_t uvalue2;
  void *pvVar3;
  void *local_4;
  
  this_00 = arg1;
  local_4 = self;
  CRT_Istream_Read(arg1,(intptr_t)self + 4,0x1e);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x24,4);
  CRT_Istream_Read(this_00,(int *)((intptr_t)self + 0x28),4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x2c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x38,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x3c,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x40,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x30,4);
  CRT_Istream_Read(this_00,&local_4,4);
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  uvalue2 = IDMap_Lookup((void *)(value1 + 0xfac),(intptr_t)local_4,(int *)0x0);
  *(uint32_t *)((intptr_t)self + 0x34) = uvalue2;
  CRT_Istream_Read(this_00,&arg1,4);
  value1 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      pvVar3 = operator_new(0x20);
      CRT_Istream_Read(this_00,pvVar3,0x20);
      List_Add((void *)((intptr_t)self + 0x44),pvVar3);
      value1 = value1 + 1;
    } while (value1 < (intptr_t)arg1);
  }
  CRT_Istream_Read(this_00,(intptr_t)self + 0x60,0xf0);
  return;
}
