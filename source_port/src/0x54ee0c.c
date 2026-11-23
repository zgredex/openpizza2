// CRT_FseekLocked: ported from Pizza Connection 2 at 0x54ee0c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ee0c
#include "pc2_port.h"

int __cdecl CRT_FseekLocked(int *arg1,int arg2,DWORD arg3)

{
  uint32_t uvalue1;
  int value2;
  DWORD DVar3;
  DWORD *pDVar4;
  
  if (((arg1[3] & 0x83U) == 0) || (((arg3 != 0 && (arg3 != 1)) && (arg3 != 2)))) {
    pDVar4 = CRT_GetErrnoPtr();
    *pDVar4 = 0x16;
    value2 = -1;
  }
  else {
    arg1[3] = arg1[3] & 0xffffffef;
    if (arg3 == 1) {
      value2 = CRT_FtellLocked((char *)arg1);
      arg2 = arg2 + value2;
      arg3 = 0;
    }
    CRT_FlushStream(arg1);
    uvalue1 = arg1[3];
    if ((uvalue1 & 0x80) == 0) {
      if ((((uvalue1 & 1) != 0) && ((uvalue1 & 8) != 0)) && ((uvalue1 & 0x400) == 0)) {
        arg1[6] = 0x200;
      }
    }
    else {
      arg1[3] = uvalue1 & 0xfffffffc;
    }
    DVar3 = CRT_Lseek(arg1[4],arg2,arg3);
    value2 = (DVar3 != 0xffffffff) - 1;
  }
  return value2;
}
