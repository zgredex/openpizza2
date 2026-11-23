// CRT_Chsize: ported from Pizza Connection 2 at 0x554784.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554784
#include "pc2_port.h"

int __cdecl CRT_Chsize(uint32_t arg1,int arg2)

{
  DWORD DVar1;
  DWORD DVar2;
  int value3;
  DWORD DVar4;
  int value5;
  DWORD *pDVar6;
  HANDLE hFile;
  BOOL BVar7;
  uint8_t unaff_BP;
  int value8;
  char local_1008 [4064];
  uint32_t uStackY_28;
  
  __chkstk(unaff_BP);
  value8 = 0;
  DVar1 = CRT_LseekLocked(arg1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = CRT_LseekLocked(arg1,0,2), DVar2 == 0xffffffff)) {
    value8 = -1;
  }
  else {
    DVar2 = arg2 - DVar2;
    if ((intptr_t)DVar2 < 1) {
      if ((intptr_t)DVar2 < 0) {
        CRT_LseekLocked(arg1,arg2,0);
        hFile = (HANDLE)CRT_GetOsHandle(arg1);
        BVar7 = SetEndOfFile(hFile);
        value8 = (BVar7 != 0) - 1;
        if (value8 == -1) {
          pDVar6 = CRT_GetErrnoPtr();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = CRT_GetDosErrnoPtr();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x5547f1;
      value3 = CRT_SetMode(arg1,0x8000);
      do {
        DVar4 = 0x1000;
        if ((intptr_t)DVar2 < 0x1000) {
          DVar4 = DVar2;
        }
        value5 = CRT_WriteCore(arg1,local_1008,DVar4);
        if (value5 == -1) {
          pDVar6 = CRT_GetDosErrnoPtr();
          if (*pDVar6 == 5) {
            pDVar6 = CRT_GetErrnoPtr();
            *pDVar6 = 0xd;
          }
          value8 = -1;
          break;
        }
        DVar2 = DVar2 - value5;
      } while (0 < (intptr_t)DVar2);
      CRT_SetMode(arg1,value3);
    }
    CRT_LseekLocked(arg1,DVar1,0);
  }
  return value8;
}
