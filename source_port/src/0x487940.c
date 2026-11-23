// SaveGame_SerializeRuntimeList: ported from Pizza Connection 2 at 0x487940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x487940
#include "pc2_port.h"

void __thiscall SaveGame_SerializeRuntimeList(void *self,void *arg1)

{
  void *this_00;
  int value1;
  void *this_01;
  int value2;
  uint32_t local_c;
  uint32_t local_8;
  void *local_4;
  
  this_01 = arg1;
  this_00 = *(void **)(DAT_0057c5cc + 0x2c3d4);
  value2 = 0x2c41c;
  local_4 = self;
  do {
    value1 = *(int *)(DAT_0057c5cc + value2);
    if (((value1 < 0) || (*(int *)((intptr_t)this_00 + 0x48) <= value1)) ||
       (*(char *)(*(int *)((intptr_t)this_00 + 0x4c) + 0x3e + value1 * 0x48) == '\0')) {
      arg1 = (void *)0x0;
    }
    else {
      arg1 = (void *)0x1;
      CRT_Ostream_Write(this_01,&arg1,4);
      Record_GetTwoFloats48(this_00,value1,&local_c,&local_8);
      CRT_Ostream_Write(this_01,&local_c,4);
      CRT_Ostream_Write(this_01,&local_8,4);
      arg1 = (void *)Record_GetTypeIndex48(this_00,value1);
      CRT_Ostream_Write(this_01,&arg1,4);
      arg1 = *(void **)((intptr_t)local_4 + value2 + -0x2c0b0);
    }
    CRT_Ostream_Write(this_01,&arg1,4);
    value2 = value2 + 4;
  } while (value2 < 0x2c434);
  return;
}
