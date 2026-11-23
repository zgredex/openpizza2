// UI_BriefingList_Load: ported from Pizza Connection 2 at 0x54b230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b230
#include "pc2_port.h"

void __thiscall UI_BriefingList_Load(void *self,void *arg1)

{
  void *pvVar1;
  int value2;
  uint32_t local_c;
  int local_8;
  int local_4;
  
  UI_DestroyBriefingList(self);
  CRT_Istream_Read(arg1,&local_8,4);
  value2 = 0;
  if (0 < local_8) {
    do {
      CRT_Istream_Read(arg1,&local_4,4);
      CRT_Istream_Read(arg1,&local_c,4);
      pvVar1 = operator_new(local_c);
      *(uint32_t *)((intptr_t)pvVar1 + 8) = 0xffffffff;
      *(void **)((intptr_t)pvVar1 + 0x18) = self;
      CRT_Istream_Read(arg1,pvVar1,local_c);
      IDMap_InsertGrow((void *)((intptr_t)self + 4),pvVar1,local_4);
      value2 = value2 + 1;
    } while (value2 < local_8);
  }
  return;
}
