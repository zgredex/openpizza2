// SaveGame_DeserializeRuntimeList: ported from Pizza Connection 2 at 0x487a30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x487a30
#include "pc2_port.h"

void __thiscall SaveGame_DeserializeRuntimeList(void *self,void *arg1)

{
  void *this_00;
  int value1;
  int value2;
  int local_1c;
  void *local_18;
  void *local_14;
  int local_10;
  int local_c [2];
  
  this_00 = *(void **)(DAT_0057c5cc + 0x2c3d4);
  value2 = 0x2c41c;
  local_18 = this_00;
  local_14 = self;
  do {
    value1 = *(int *)(value2 + DAT_0057c5cc);
    if (((-1 < value1) && (value1 < *(int *)((intptr_t)this_00 + 0x48))) &&
       (*(char *)(*(int *)((intptr_t)this_00 + 0x4c) + 0x3e + value1 * 0x48) != '\0')) {
      Record_ClearFlags48(this_00,value1);
      *(uint32_t *)((intptr_t)local_14 + value2 + -0x2c0b0) = 0xffffffff;
    }
    value2 = value2 + 4;
  } while (value2 < 0x2c434);
  value2 = 0x2c41c;
  do {
    value1 = *(int *)(value2 + DAT_0057c5cc);
    CRT_Istream_Read(arg1,&local_1c,4);
    if (local_1c == 1) {
      CRT_Istream_Read(arg1,local_c,4);
      CRT_Istream_Read(arg1,&local_10,4);
      Record_SetRect48((intptr_t)local_18,value1,SUB84((double)local_c[0],0),
                       (intptr_t)((uint64_t)(double)local_c[0] >> 0x20),(double)local_10);
      CRT_Istream_Read(arg1,&local_1c,4);
      Record_SelectVariant(local_18,value1,local_1c);
      CRT_Istream_Read(arg1,&local_1c,4);
      *(int *)(value2 + -0x2c0b0 + (intptr_t)local_14) = local_1c;
    }
    value2 = value2 + 4;
  } while (value2 < 0x2c434);
  return;
}
