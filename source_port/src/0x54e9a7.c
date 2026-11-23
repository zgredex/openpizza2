// CRT_FreadCore: ported from Pizza Connection 2 at 0x54e9a7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e9a7
#include "pc2_port.h"

uint32_t __cdecl CRT_FreadCore(char *arg1,uint32_t arg2,uint32_t arg3,int *arg4)

{
  int *ptr1;
  char *cptr2;
  int value3;
  uint32_t uvalue4;
  char *cptr5;
  char *cptr6;
  char *cptr7;
  
  ptr1 = arg4;
  cptr6 = (char *)(arg2 * arg3);
  if (cptr6 == (char *)0x0) {
    return 0;
  }
  cptr5 = arg1;
  arg1 = cptr6;
  if ((*(uint16_t *)(arg4 + 3) & 0x10c) == 0) {
    arg4 = (int *)0x1000;
  }
  else {
    arg4 = (int *)arg4[6];
  }
  do {
    if (((*(uint16_t *)(ptr1 + 3) & 0x10c) == 0) ||
       (cptr2 = (char *)ptr1[1], cptr2 == (char *)0x0)) {
      if (arg1 < arg4) {
        uvalue4 = CRT_Filbuf(ptr1);
        if (uvalue4 == 0xffffffff) goto LAB_0054ea83;
        *cptr5 = (char)uvalue4;
        arg4 = (int *)ptr1[6];
        cptr5 = cptr5 + 1;
        arg1 = arg1 + -1;
      }
      else {
        cptr2 = arg1;
        if (arg4 != (int *)0x0) {
          cptr2 = arg1 + -((uint32_t)arg1 % (uint32_t)arg4);
        }
        value3 = CRT_Read(ptr1[4],cptr5,cptr2);
        if (value3 == 0) {
          ptr1[3] = ptr1[3] | 0x10;
LAB_0054ea83:
          return (uint32_t)((intptr_t)cptr6 - (intptr_t)arg1) / arg2;
        }
        if (value3 == -1) {
          ptr1[3] = ptr1[3] | 0x20;
          goto LAB_0054ea83;
        }
        arg1 = arg1 + -value3;
        cptr5 = cptr5 + value3;
      }
    }
    else {
      cptr7 = arg1;
      if (cptr2 <= arg1) {
        cptr7 = cptr2;
      }
      _memmove_2((uint32_t *)cptr5,(uint32_t *)*ptr1,(uint32_t)cptr7);
      arg1 = arg1 + -(intptr_t)cptr7;
      ptr1[1] = ptr1[1] - (intptr_t)cptr7;
      *ptr1 = (intptr_t)(cptr7 + *ptr1);
      cptr5 = cptr5 + (intptr_t)cptr7;
    }
    if (arg1 == (char *)0x0) {
      return arg3;
    }
  } while( true );
}
