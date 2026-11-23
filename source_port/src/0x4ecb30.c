// MapSprite_Save: ported from Pizza Connection 2 at 0x4ecb30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ecb30
#include "pc2_port.h"

void MapSprite_Save(char *arg1,int *arg2)

{
  void *self;
  int *ptr1;
  char cVar2;
  int value3;
  void **ppvVar4;
  int64_t lvalue5;
  uint32_t uvalue6;
  uint32_t local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  uint32_t local_8 [2];
  
  ptr1 = arg2;
  self = arg1;
  value3 = *arg2;
  if ((value3 < 0) || (*(int *)(arg2[0x16] + 0x48) <= value3)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = *(char *)(*(int *)(arg2[0x16] + 0x4c) + 0x3e + value3 * 0x48);
  }
  arg2 = (int *)CONCAT31(((uint8_t)(((intptr_t)arg2) >> 24)),cVar2 == '\x01');
  CRT_Ostream_Write(arg1,&arg2,1);
  Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&arg1,&local_1c);
  CRT_Ostream_Write(self,&arg1,4);
  CRT_Ostream_Write(self,&local_1c,4);
  Record_GetPairPositions((void *)ptr1[0x16],*ptr1,local_10,local_8);
  lvalue5 = __ftol();
  arg1 = (void *)lvalue5;
  lvalue5 = __ftol();
  local_1c = (uint32_t)lvalue5;
  CRT_Ostream_Write(self,&arg1,4);
  CRT_Ostream_Write(self,&local_1c,4);
  CRT_Ostream_Write(self,ptr1 + 2,2);
  CRT_Ostream_Write(self,(intptr_t)ptr1 + 10,2);
  CRT_Ostream_Write(self,ptr1 + 3,4);
  CRT_Ostream_Write(self,ptr1 + 4,1);
  local_14 = (intptr_t)(short)ptr1[10];
  CRT_Ostream_Write(self,&local_14,4);
  CRT_Ostream_Write(self,ptr1 + 0xb,4);
  CRT_Ostream_Write(self,ptr1 + 0xc,8);
  CRT_Ostream_Write(self,ptr1 + 0xe,8);
  CRT_Ostream_Write(self,ptr1 + 0x10,4);
  CRT_Ostream_Write(self,ptr1 + 0x11,8);
  CRT_Ostream_Write(self,ptr1 + 0x15,4);
  CRT_Ostream_Write(self,ptr1 + 0x13,8);
  local_18 = ptr1[6];
  CRT_Ostream_Write(self,&local_18,4);
  arg1 = (void *)0x0;
  if (0 < local_18) {
    do {
      uvalue6 = 2;
      value3 = Array_GetPtr4(ptr1 + 5,(intptr_t)arg1);
      CRT_Ostream_Write(self,value3 + 2,uvalue6);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_18);
  }
  if (ptr1[8] == 0) {
    ppvVar4 = &arg1;
    uvalue6 = 4;
    arg1 = (void *)0x0;
  }
  else {
    arg1 = (void *)0x1;
    CRT_Ostream_Write(self,&arg1,4);
    uvalue6 = 2;
    ppvVar4 = (void **)(ptr1[8] + 2);
  }
  CRT_Ostream_Write(self,ppvVar4,uvalue6);
  if (ptr1[9] == 0) {
    arg1 = (void *)0x0;
    CRT_Ostream_Write(self,&arg1,4);
    return;
  }
  arg1 = (void *)0x1;
  CRT_Ostream_Write(self,&arg1,4);
  CRT_Ostream_Write(self,ptr1[9] + 2,2);
  return;
}
