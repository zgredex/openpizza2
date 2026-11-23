// Game_FindNearestServiceBuilding: ported from Pizza Connection 2 at 0x480e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480e80
#include "pc2_port.h"

int __thiscall Game_FindNearestServiceBuilding(void *self,int arg1)

{
  int *ptr1;
  void *this_00;
  void *this_01;
  int value2;
  int value3;
  int value4;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  ptr1 = *(int **)(arg1 + 200);
  this_00 = *(void **)((intptr_t)self + 0x16f0);
  local_8 = 90000000;
  local_4 = 0;
  if (ptr1 == (int *)0x0) {
    value4 = -1;
    this_01 = (void *)0x0;
  }
  else {
    value4 = *ptr1;
    this_01 = (void *)ptr1[0x16];
  }
  Record_GetTwoFloats48(this_01,value4,&local_14,&arg1);
  value4 = 0;
  local_14 = local_14 + *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0xf8);
  arg1 = arg1 + *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0xfc);
  if (*(int *)((intptr_t)this_00 + 0x8c) < 1) {
    return 0;
  }
  do {
    value2 = Game_MapRecordToGlobal(this_00,value4);
    value3 = *(int *)(value2 + 0x30);
    if ((((value3 == 0x1a) || (value3 == 0x1b)) || (value3 == 0x1c)) &&
       ((ptr1 = *(int **)(value2 + 200), ptr1 != (int *)0x0 && (*(int *)(value2 + 0x38) != 0x1f)))
       ) {
      Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_10,&local_c);
      local_10 = local_10 + *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0xf8);
      local_c = local_c + *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0xfc);
      value3 = Distance_Manhattan3(local_14,arg1,local_10,local_c);
      if (value3 < local_8) {
        local_8 = value3;
        local_4 = value2;
      }
    }
    value4 = value4 + 1;
  } while (value4 < *(int *)((intptr_t)this_00 + 0x8c));
  return local_4;
}
