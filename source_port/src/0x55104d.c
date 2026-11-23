// CRT_FlushStreamBuffer: ported from Pizza Connection 2 at 0x55104d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55104d
#include "pc2_port.h"

uint32_t __cdecl CRT_FlushStreamBuffer(uint32_t arg1,int *arg2)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  char *cptr3;
  int *ptr4;
  uint8_t flag5;
  uint32_t extraout_var;
  uint8_t *uptr6;
  int *ptr7;
  
  ptr4 = arg2;
  uvalue1 = arg2[3];
  uvalue2 = arg2[4];
  if (((uvalue1 & 0x82) == 0) || ((uvalue1 & 0x40) != 0)) {
LAB_00551159:
    arg2[3] = uvalue1 | 0x20;
  }
  else {
    if ((uvalue1 & 1) != 0) {
      arg2[1] = 0;
      if ((uvalue1 & 0x10) == 0) goto LAB_00551159;
      *arg2 = arg2[2];
      arg2[3] = uvalue1 & 0xfffffffe;
    }
    uvalue1 = arg2[3];
    arg2[1] = 0;
    arg2 = (int *)0x0;
    ptr4[3] = uvalue1 & 0xffffffef | 2;
    if (((uvalue1 & 0x10c) == 0) &&
       (((ptr4 != (int *)&DAT_005767a8 && (ptr4 != (int *)&DAT_005767c8)) ||
        (flag5 = CRT_TestLockFlag(uvalue2), CONCAT31(extraout_var,flag5) == 0)))) {
      CRT_StreamAllocBuffer(ptr4);
    }
    if ((*(uint16_t *)(ptr4 + 3) & 0x108) == 0) {
      ptr7 = (int *)0x1;
      arg2 = (int *)CRT_Write(uvalue2,(char *)&arg1,1);
    }
    else {
      cptr3 = (char *)ptr4[2];
      ptr7 = (int *)(*ptr4 - (intptr_t)cptr3);
      *ptr4 = (intptr_t)(cptr3 + 1);
      ptr4[1] = ptr4[6] + -1;
      if ((intptr_t)ptr7 < 1) {
        if (uvalue2 == 0xffffffff) {
          uptr6 = &DAT_00576760;
        }
        else {
          uptr6 = (uint8_t *)((&DAT_00586c20)[(intptr_t)uvalue2 >> 5] + (uvalue2 & 0x1f) * 0x24);
        }
        if ((uptr6[4] & 0x20) != 0) {
          CRT_Lseek(uvalue2,0,2);
        }
      }
      else {
        arg2 = (int *)CRT_Write(uvalue2,cptr3,(DWORD)ptr7);
      }
      *(uint8_t *)ptr4[2] = (uint8_t)arg1;
    }
    if (arg2 == ptr7) {
      return arg1 & 0xff;
    }
    ptr4[3] = ptr4[3] | 0x20;
  }
  return 0xffffffff;
}
