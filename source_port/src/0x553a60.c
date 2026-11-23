// CRT_XcptFilter: ported from Pizza Connection 2 at 0x553a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553a60
#include "pc2_port.h"

LONG __cdecl CRT_XcptFilter(int arg1,_EXCEPTION_POINTERS *arg2)

{
  code *cptr1;
  DWORD DVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  int *ptr5;
  LONG LVar6;
  int value7;
  int value8;
  
  pDVar4 = CRT_GetThreadData();
  ptr5 = CRT_FindExceptionHandler(arg1,(int *)pDVar4[0x14]);
  if ((ptr5 == (int *)0x0) || (cptr1 = (code *)ptr5[2], cptr1 == (code *)0x0)) {
    LVar6 = UnhandledExceptionFilter(arg2);
  }
  else if (cptr1 == (code *)0x5) {
    ptr5[2] = 0;
    LVar6 = 1;
  }
  else {
    if (cptr1 != (code *)0x1) {
      DVar2 = pDVar4[0x15];
      pDVar4[0x15] = (DWORD)arg2;
      if (ptr5[1] == 8) {
        if (DAT_005770b8 < DAT_005770bc + DAT_005770b8) {
          value7 = DAT_005770b8 * 0xc;
          value8 = DAT_005770b8;
          do {
            *(uint32_t *)(value7 + 8 + pDVar4[0x14]) = 0;
            value8 = value8 + 1;
            value7 = value7 + 0xc;
          } while (value8 < DAT_005770bc + DAT_005770b8);
        }
        value7 = *ptr5;
        DVar3 = pDVar4[0x16];
        if (value7 == -0x3fffff72) {
          pDVar4[0x16] = 0x83;
        }
        else if (value7 == -0x3fffff70) {
          pDVar4[0x16] = 0x81;
        }
        else if (value7 == -0x3fffff6f) {
          pDVar4[0x16] = 0x84;
        }
        else if (value7 == -0x3fffff6d) {
          pDVar4[0x16] = 0x85;
        }
        else if (value7 == -0x3fffff73) {
          pDVar4[0x16] = 0x82;
        }
        else if (value7 == -0x3fffff71) {
          pDVar4[0x16] = 0x86;
        }
        else if (value7 == -0x3fffff6e) {
          pDVar4[0x16] = 0x8a;
        }
        (*cptr1)(8,pDVar4[0x16]);
        pDVar4[0x16] = DVar3;
      }
      else {
        ptr5[2] = 0;
        (*cptr1)(ptr5[1]);
      }
      pDVar4[0x15] = DVar2;
    }
    LVar6 = -1;
  }
  return LVar6;
}
