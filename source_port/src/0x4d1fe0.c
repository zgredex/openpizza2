// MapObject_Save: ported from Pizza Connection 2 at 0x4d1fe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d1fe0
#include "pc2_port.h"

void __thiscall MapObject_Save(void *self,void *arg1)

{
  int *ptr1;
  void *this_00;
  int value2;
  void *local_4;
  
  this_00 = arg1;
  local_4 = self;
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x4c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x50,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x30,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x34,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x38,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x3c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x94,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x10,0x10);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x20,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x24,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x40,8);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x48,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x54,4);
  ptr1 = (int *)((intptr_t)self + 0x28);
  CRT_Ostream_Write(this_00,ptr1,4);
  if (*ptr1 == -1) {
    NoOp_Stub();
  }
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*ptr1,(int *)0x0);
  arg1 = (void *)Game_RemoveIDMapEntry(DAT_0057c5cc,*(int *)(value2 + 0xfa8));
  CRT_Ostream_Write(this_00,&arg1,4);
  arg1 = *(void **)((intptr_t)self + 0x6c);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x6c)) {
    do {
      arg1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x58),value2,(int *)0x0);
      CRT_Ostream_Write(this_00,&arg1,4);
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x6c));
  }
  if (*(int *)((intptr_t)self + 0x74) == 0) {
    arg1 = (void *)0x0;
    CRT_Ostream_Write(this_00,&arg1,4);
  }
  else {
    arg1 = (void *)0x1;
    CRT_Ostream_Write(this_00,&arg1,4);
    BuildingValue_Save(*(void **)((intptr_t)self + 0x74),this_00);
  }
  arg1 = *(void **)((intptr_t)self + 0x8c);
  CRT_Ostream_Write(this_00,&arg1,4);
  value2 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      local_4 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x78),value2,(int *)0x0);
      CRT_Ostream_Write(this_00,&local_4,4);
      value2 = value2 + 1;
    } while (value2 < (intptr_t)arg1);
  }
  return;
}
