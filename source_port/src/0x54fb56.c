// CRT_Fwrite: ported from Pizza Connection 2 at 0x54fb56.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fb56
#include "pc2_port.h"

uint32_t __cdecl CRT_Fwrite(char *arg1,uint32_t arg2,uint32_t arg3,int *arg4)

{
  int *ptr1;
  int value2;
  int *ptr3;
  uint32_t uvalue4;
  int *ptr5;
  int *ptr6;
  int *ptr7;
  
  ptr1 = arg4;
  ptr6 = (int *)(arg2 * arg3);
  if (ptr6 == (int *)0x0) {
    arg3 = 0;
  }
  else {
    ptr5 = ptr6;
    if ((*(uint16_t *)(arg4 + 3) & 0x10c) == 0) {
      arg4 = (int *)0x1000;
    }
    else {
      arg4 = (int *)arg4[6];
    }
    do {
      if (((ptr1[3] & 0x108U) == 0) || (ptr7 = (int *)ptr1[1], ptr7 == (int *)0x0)) {
        if (arg4 <= ptr5) {
          if (((ptr1[3] & 0x108U) != 0) && (value2 = CRT_FlushStream(ptr1), value2 != 0)) {
LAB_0054fc57:
            return (uint32_t)((intptr_t)ptr6 - (intptr_t)ptr5) / arg2;
          }
          if (arg4 == (int *)0x0) {
            ptr7 = ptr5;
          }
          else {
            ptr7 = (int *)((intptr_t)ptr5 - (uint32_t)ptr5 % (uint32_t)arg4);
          }
          ptr3 = (int *)CRT_Write(ptr1[4],arg1,(DWORD)ptr7);
          if ((ptr3 == (int *)0xffffffff) ||
             (ptr5 = (int *)((intptr_t)ptr5 - (intptr_t)ptr3), ptr3 < ptr7)) {
            ptr1[3] = ptr1[3] | 0x20;
            goto LAB_0054fc57;
          }
          goto LAB_0054fc0e;
        }
        uvalue4 = CRT_FlushStreamBuffer((intptr_t)*arg1,ptr1);
        if (uvalue4 == 0xffffffff) goto LAB_0054fc57;
        arg1 = arg1 + 1;
        arg4 = (int *)ptr1[6];
        ptr5 = (int *)((intptr_t)ptr5 - 1);
        if ((intptr_t)arg4 < 1) {
          arg4 = (int *)0x1;
        }
      }
      else {
        ptr3 = ptr5;
        if (ptr7 <= ptr5) {
          ptr3 = ptr7;
        }
        _memmove_2((uint32_t *)*ptr1,(uint32_t *)arg1,(uint32_t)ptr3);
        ptr1[1] = ptr1[1] - (intptr_t)ptr3;
        *ptr1 = *ptr1 + (intptr_t)ptr3;
        ptr5 = (int *)((intptr_t)ptr5 - (intptr_t)ptr3);
LAB_0054fc0e:
        arg1 = arg1 + (intptr_t)ptr3;
      }
    } while (ptr5 != (int *)0x0);
  }
  return arg3;
}
