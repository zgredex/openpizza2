// CRT_WctombLocked: ported from Pizza Connection 2 at 0x5554ae.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5554ae
#include "pc2_port.h"

int __cdecl CRT_WctombLocked(LPSTR arg1,WCHAR arg2)

{
  LPSTR lpMultiByteStr;
  int value1;
  DWORD *pDVar2;
  
  lpMultiByteStr = arg1;
  if (arg1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_005857cc == 0) {
    if ((uint16_t)arg2 < 0x100) {
      *arg1 = (CHAR)arg2;
      return 1;
    }
  }
  else {
    arg1 = (LPSTR)0x0;
    value1 = WideCharToMultiByte(DAT_005857dc,0x220,&arg2,1,lpMultiByteStr,DAT_00576cf0,
                                (LPCSTR)0x0,(LPBOOL)&arg1);
    if ((value1 != 0) && (arg1 == (LPSTR)0x0)) {
      return value1;
    }
  }
  pDVar2 = CRT_GetErrnoPtr();
  *pDVar2 = 0x2a;
  return -1;
}
