// MapObjectList_Save: ported from Pizza Connection 2 at 0x4d7090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d7090
#include "pc2_port.h"

void __thiscall MapObjectList_Save(void *self,void *arg1)

{
  void *this_00;
  int *ptr1;
  int local_14;
  int local_10;
  uint32_t local_c;
  int local_8;
  uint32_t local_4;
  
  local_14 = Game_RemoveIDMapEntry(DAT_0057c5cc,*(int *)((intptr_t)self + 0xfa8));
  CRT_Ostream_Write(arg1,&local_14,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc1c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 4U,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x44,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc20,0x18);
  local_c = 0xc18;
  CRT_Ostream_Write(arg1,&local_c,4);
  CRT_Ostream_Write(arg1,-(uint32_t)(self != (void *)0x0) & (intptr_t)self + 4U,local_c);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xdac,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xdc4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xdc8,0x1e0);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc38,0x60);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc98,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xcc8,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xd40,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xd58,0x30);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xd88,0x24);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xce0,0x60);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xcb0,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xfe4,0xc0);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10ac,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10b0,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10b4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10b8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10c4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10d0,0x78);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10c0,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10bc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10cc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10c8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1148,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x114c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1150,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1154,4);
  local_14 = *(int *)((intptr_t)self + 0xfc0);
  CRT_Ostream_Write(arg1,&local_14,4);
  local_14 = 0;
  if (0 < *(int *)((intptr_t)self + 0xfc0)) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0xfac),local_14,(int *)0x0);
      MapObject_Save(this_00,arg1);
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)((intptr_t)self + 0xfc0));
  }
  local_10 = *(int *)((intptr_t)self + 0xfdc);
  CRT_Ostream_Write(arg1,&local_10,4);
  local_14 = 0;
  if (0 < local_10) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0xfc8),local_14,(int *)0x0);
      local_8 = ptr1[1];
      CRT_Ostream_Write(arg1,&local_8,4);
      local_4 = Map_LookupLinear((void *)(DAT_0057c670 + 0x20),*ptr1);
      CRT_Ostream_Write(arg1,&local_4,4);
      local_14 = local_14 + 1;
    } while (local_14 < local_10);
  }
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10a4,4);
  return;
}
