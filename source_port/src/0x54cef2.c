// CRT_Filebuf_Underflow: ported from Pizza Connection 2 at 0x54cef2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cef2
#include "pc2_port.h"

uint32_t __fastcall CRT_Filebuf_Underflow(int *arg1)

{
  char *cptr1;
  uint8_t *bptr2;
  int value3;
  char *cptr4;
  uint32_t uStack_8;
  
  uStack_8 = arg1;
  value3 = Stream_GetAvailable((intptr_t)arg1);
  if (value3 != 0) {
    return (uint32_t)*(uint8_t *)arg1[10];
  }
  value3 = Stream_GetStatus(arg1);
  if ((value3 != -1) && (value3 = CRT_Filebuf_Sync((intptr_t)arg1), value3 != -1)) {
    if (arg1[2] == 0) {
      cptr1 = (char *)arg1[4];
      if (cptr1 < (char *)arg1[5]) {
        cptr4 = (char *)arg1[5] + -(intptr_t)cptr1;
      }
      else {
        cptr4 = (char *)0x0;
      }
      value3 = CRT_Read(arg1[0x13],cptr1,cptr4);
      if (0 < value3) {
        bptr2 = (uint8_t *)arg1[4];
        arg1[3] = -1;
        arg1[9] = (intptr_t)bptr2;
        arg1[10] = (intptr_t)bptr2;
        arg1[0xb] = (intptr_t)(bptr2 + value3);
        return (uint32_t)*bptr2;
      }
    }
    else {
      value3 = CRT_Read(arg1[0x13],(char *)((intptr_t)&uStack_8 + 3),(char *)0x1);
      if (0 < value3) {
        return (uint32_t)uStack_8 >> 0x18;
      }
    }
  }
  return 0xffffffff;
}
