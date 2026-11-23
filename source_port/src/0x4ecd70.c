// MapActor_ReadFromStream: ported from Pizza Connection 2 at 0x4ecd70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ecd70
#include "pc2_port.h"

void MapActor_ReadFromStream(void *arg1,uint32_t *arg2)

{
  void *self;
  uint32_t *this_00;
  int *ptr1;
  int value2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  int local_18;
  uint32_t local_14;
  int local_10;
  void *local_c;
  int local_8;
  uint16_t local_4 [2];
  
                    /* Deserializes a map actor's position, motion, ids, and path. */
  self = arg1;
  CRT_Istream_Read(arg1,&arg1,1);
  CRT_Istream_Read(self,&local_18,4);
  CRT_Istream_Read(self,&local_10,4);
  this_00 = arg2;
  Record_SetDoubles48((void *)arg2[0x16],*arg2,local_18,local_10);
  CRT_Istream_Read(self,&local_18,4);
  CRT_Istream_Read(self,&local_10,4);
  Record_SetDoubles48B(this_00[0x16],*this_00,(double)local_18,(double)local_10);
  CRT_Istream_Read(self,this_00 + 2,2);
  CRT_Istream_Read(self,(intptr_t)this_00 + 10,2);
  CRT_Istream_Read(self,this_00 + 3,4);
  CRT_Istream_Read(self,this_00 + 4,1);
  CRT_Istream_Read(self,local_4,4);
  Object_SetShort28(this_00,local_4[0]);
  CRT_Istream_Read(self,this_00 + 0xb,4);
  CRT_Istream_Read(self,this_00 + 0xc,8);
  CRT_Istream_Read(self,this_00 + 0xe,8);
  CRT_Istream_Read(self,this_00 + 0x10,4);
  if (DAT_0057c668 < 0x2a) {
    uptr4 = this_00 + 0x12;
    this_00[0x11] = 0xffffffff;
    uvalue5 = 4;
  }
  else {
    uptr4 = this_00 + 0x11;
    uvalue5 = 8;
  }
  CRT_Istream_Read(self,uptr4,uvalue5);
  CRT_Istream_Read(self,this_00 + 0x15,4);
  if (DAT_0057c668 < 0x2a) {
    uptr4 = this_00 + 0x14;
    this_00[0x13] = 0xffffffff;
    uvalue5 = 4;
  }
  else {
    uptr4 = this_00 + 0x13;
    uvalue5 = 8;
  }
  CRT_Istream_Read(self,uptr4,uvalue5);
  SetRect((LPRECT)(this_00 + 0x17),0xffff,0xffff,-1,-1);
  ptr1 = (int *)(uint32_t)(this_00[1] != 0xffffffff);
  CRT_Istream_Read(self,&local_8,4);
  Object_ClearField4((intptr_t)(this_00 + 5));
  local_18 = 0;
  if (0 < local_8) {
    do {
      CRT_Istream_Read(self,&local_14,2);
      value2 = Object_FindRecordByKey28(local_c,ptr1,local_14 & 0xffff);
      Array_Grow(this_00 + 5,value2);
      local_18 = local_18 + 1;
    } while (local_18 < local_8);
  }
  CRT_Istream_Read(self,&local_18,4);
  if (local_18 == 0) {
    this_00[8] = 0;
  }
  else {
    CRT_Istream_Read(self,&local_14,2);
    uvalue3 = Object_FindRecordByKey28(local_c,ptr1,local_14 & 0xffff);
    this_00[8] = uvalue3;
  }
  CRT_Istream_Read(self,&local_18,4);
  if (local_18 == 0) {
    this_00[9] = 0;
  }
  else {
    CRT_Istream_Read(self,&local_14,2);
    uvalue3 = Object_FindRecordByKey28(local_c,ptr1,local_14 & 0xffff);
    this_00[9] = uvalue3;
  }
  Record_ClearActive48((void *)this_00[0x16],*this_00);
  if ((char)arg1 != '\0') {
    Record_SelectVariant((void *)this_00[0x16],*this_00,this_00[3]);
  }
  return;
}
