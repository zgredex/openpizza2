// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x557050.c:21:80: error: use of undeclared identifier 'LPBOOL'; did you mean 'BOOL'?
// FUN_00557050: ported from Pizza Connection 2 at 0x557050.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557050
#include "pc2_port.h"

uint32_t FUN_00557050(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  uint32_t *lpMultiByteStr;
  int value1;
  uint32_t *uptr2;
  
  lpWideCharStr = (LPCWSTR)*DAT_00585638;
  uptr2 = DAT_00585638;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (uint32_t *)0x0)) ||
       (value1 = WideCharToMultiByte(1,0,(LPCWSTR)*uptr2,-1,(LPSTR)lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), value1 == 0)) break;
    FUN_005577d5(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)uptr2[1];
    uptr2 = uptr2 + 1;
  }
  return 0xffffffff;
}
