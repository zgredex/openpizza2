// PersonAction_LoadState: ported from Pizza Connection 2 at 0x505910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505910
#include "pc2_port.h"

void __thiscall PersonAction_LoadState(void *self,void *arg1)

{
  void *this_00;
  uint32_t uvalue1;
  void *this_01;
  int value2;
  uint32_t *uptr3;
  int local_10;
  int local_c;
  int local_8;
  uint32_t local_4;
  
                    /* Deserializes a person action/task record and its lists. */
  this_00 = arg1;
  CRT_Istream_Read(arg1,(intptr_t)self + 4,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x24,4);
  CRT_Istream_Read(this_00,(int *)((intptr_t)self + 0x28),4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x30,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x34,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x38,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x3c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x40,2);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x44,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x48,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x4c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x50,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x54,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x58,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x5c,0x18);
  CRT_Istream_Read(this_00,(int *)((intptr_t)self + 0x74),4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x78,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x7c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x80,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x81,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x84,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x88,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x8c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x90,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x94,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x98,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x9c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x14c,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xa0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xa4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xa8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x110,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x104,1);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x108,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xac,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x2c,4);
  CRT_Istream_Read(this_00,&arg1,4);
  uvalue1 = Game_UpdateIDMapEntry(DAT_0057c5cc,(intptr_t)arg1);
  *(uint32_t *)((intptr_t)self + 0xc4) = uvalue1;
  MapObject_ReadRenderRecord(self,(uint32_t)(*(int *)((intptr_t)self + 0x74) != 0),this_00);
  this_01 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (void *)0x0) {
    *(uint32_t *)((intptr_t)self + 0xcc) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&arg1,4);
    uvalue1 = Game_UpdateAndFetchMapEntryFAC(this_01,(intptr_t)arg1);
    *(uint32_t *)((intptr_t)self + 0xcc) = uvalue1;
  }
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (void *)0x0) {
    uvalue1 = 0;
  }
  else {
    CRT_Istream_Read(this_00,&arg1,4);
    uvalue1 = Game_UpdateAndFetchMapEntryFAC(this_01,(intptr_t)arg1);
  }
  Object_SetFieldFC(self,uvalue1);
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (void *)0x0) {
    *(uint32_t *)((intptr_t)self + 0x100) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&arg1,4);
    uvalue1 = Game_UpdateAndFetchMapEntryFAC(this_01,(intptr_t)arg1);
    *(uint32_t *)((intptr_t)self + 0x100) = uvalue1;
  }
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (void *)0x0) {
    *(uint32_t *)((intptr_t)self + 0xd0) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&arg1,4);
    uvalue1 = Game_UpdateAndFetchMapEntryFAC(this_01,(intptr_t)arg1);
    *(uint32_t *)((intptr_t)self + 0xd0) = uvalue1;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0xd4);
  local_8 = 8;
  do {
    CRT_Istream_Read(this_00,&arg1,4);
    if (arg1 == (void *)0x0) {
      *uptr3 = 0;
    }
    else {
      CRT_Istream_Read(this_00,&arg1,4);
      uvalue1 = Game_UpdateAndFetchMapEntryFAC(this_01,(intptr_t)arg1);
      *uptr3 = uvalue1;
    }
    uptr3 = uptr3 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  CRT_Istream_Read(this_00,&arg1,4);
  if (arg1 == (void *)0x0) {
    *(uint32_t *)((intptr_t)self + 0xf4) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&arg1,4);
    uvalue1 = Game_UpdateAndFetchMapEntryFAC(this_01,(intptr_t)arg1);
    *(uint32_t *)((intptr_t)self + 0xf4) = uvalue1;
  }
  CRT_Istream_Read(this_00,&arg1,4);
  *(uint32_t *)((intptr_t)self + 0xf8) = 0;
  if (arg1 != (void *)0x0) {
    CRT_Istream_Read(this_00,&local_4,2);
    if (*(void **)((intptr_t)self + 0xc4) != (void *)0x0) {
      value2 = Object_FindRecordByKey28(*(void **)((intptr_t)self + 0xc4),(int *)0x1,local_4 & 0xffff);
      *(int *)((intptr_t)self + 0xf8) = value2;
    }
  }
  CRT_Istream_Read(this_00,&local_10,4);
  arg1 = (void *)0x0;
  if (0 < local_10) {
    do {
      CRT_Istream_Read(this_00,&local_c,4);
      List_Add((void *)((intptr_t)self + 0x114),local_c);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_10);
  }
  CRT_Istream_Read(this_00,&local_10,4);
  arg1 = (void *)0x0;
  if (0 < local_10) {
    do {
      CRT_Istream_Read(this_00,&local_c,4);
      uvalue1 = Game_UpdateAndFetchMapEntryFAC(this_01,local_c);
      List_Add((void *)((intptr_t)self + 0x130),uvalue1);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_10);
  }
  return;
}
