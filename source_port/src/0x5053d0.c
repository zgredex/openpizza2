// PersonList_Save: ported from Pizza Connection 2 at 0x5053d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5053d0
#include "pc2_port.h"

void __thiscall PersonList_Save(void *self,void *arg1)

{
  void *this_00;
  void *this_01;
  int value1;
  int *ptr2;
  uint32_t uvalue3;
  int local_c;
  int local_8;
  uint32_t local_4;
  
  this_00 = arg1;
  this_01 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,0x20);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x24,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x28,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x30,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x34,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x38,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x3c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x40,2);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x44,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x48,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x4c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x50,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x54,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x58,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x5c,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x74,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x78,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x7c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x80,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x81,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x84,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x88,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x8c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x90,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x94,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x98,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x9c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14c,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xa0,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xa4,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xa8,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x110,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x104,1);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x108,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xac,0x18);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x2c,4);
  local_c = Game_RemoveIDMapEntry(DAT_0057c5cc,*(int *)((intptr_t)self + 0xc4));
  CRT_Ostream_Write(arg1,&local_c,4);
  Person_Save(self,arg1);
  if (*(int *)((intptr_t)self + 0xcc) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    CRT_Ostream_Write(arg1,&local_c,4);
    local_c = SaveGame_LookupSavedId(this_01,*(int *)((intptr_t)self + 0xcc));
  }
  CRT_Ostream_Write(arg1,&local_c,4);
  if (*(int *)((intptr_t)self + 0xfc) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    CRT_Ostream_Write(arg1,&local_c,4);
    local_c = SaveGame_LookupSavedId(this_01,*(int *)((intptr_t)self + 0xfc));
  }
  CRT_Ostream_Write(arg1,&local_c,4);
  if (*(int *)((intptr_t)self + 0x100) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    CRT_Ostream_Write(arg1,&local_c,4);
    local_c = SaveGame_LookupSavedId(this_01,*(int *)((intptr_t)self + 0x100));
  }
  CRT_Ostream_Write(arg1,&local_c,4);
  if (*(int *)((intptr_t)self + 0xd0) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    CRT_Ostream_Write(arg1,&local_c,4);
    local_c = SaveGame_LookupSavedId(this_01,*(int *)((intptr_t)self + 0xd0));
  }
  CRT_Ostream_Write(arg1,&local_c,4);
  ptr2 = (int *)((intptr_t)self + 0xd4);
  arg1 = (void *)0x8;
  do {
    if (*ptr2 == 0) {
      local_c = 0;
    }
    else {
      local_c = 1;
      CRT_Ostream_Write(this_00,&local_c,4);
      local_c = SaveGame_LookupSavedId(this_01,*ptr2);
    }
    CRT_Ostream_Write(this_00,&local_c,4);
    ptr2 = ptr2 + 1;
    arg1 = (void *)((intptr_t)arg1 + -1);
  } while (arg1 != (void *)0x0);
  if (*(int *)((intptr_t)self + 0xf4) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    CRT_Ostream_Write(this_00,&local_c,4);
    local_c = SaveGame_LookupSavedId(this_01,*(int *)((intptr_t)self + 0xf4));
  }
  CRT_Ostream_Write(this_00,&local_c,4);
  if (*(int *)((intptr_t)self + 0xf8) == 0) {
    ptr2 = &local_c;
    uvalue3 = 4;
    local_c = 0;
  }
  else {
    local_c = 1;
    CRT_Ostream_Write(this_00,&local_c,4);
    uvalue3 = 2;
    ptr2 = (int *)(*(int *)((intptr_t)self + 0xf8) + 2);
  }
  CRT_Ostream_Write(this_00,ptr2,uvalue3);
  local_8 = *(int *)((intptr_t)self + 0x128);
  CRT_Ostream_Write(this_00,&local_8,4);
  local_c = 0;
  if (0 < local_8) {
    do {
      local_4 = IDMap_Lookup((void *)((intptr_t)self + 0x114),local_c,(int *)0x0);
      CRT_Ostream_Write(this_00,&local_4,4);
      local_c = local_c + 1;
    } while (local_c < local_8);
  }
  local_8 = *(int *)((intptr_t)self + 0x144);
  CRT_Ostream_Write(this_00,&local_8,4);
  local_c = 0;
  if (0 < local_8) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x130),local_c,(int *)0x0);
      local_4 = SaveGame_LookupSavedId(this_01,value1);
      CRT_Ostream_Write(this_00,&local_4,4);
      local_c = local_c + 1;
    } while (local_c < local_8);
  }
  return;
}
