// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x552398.c:6:9: error: conflicting types for 'CRT_GetThreadData'
// CRT_GetThreadData: ported from Pizza Connection 2 at 0x552398.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552398
#include "pc2_port.h"

DWORD * CRT_GetThreadData(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_00576ac4);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)CRT_Calloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00576ac4,lpTlsValue);
      if (BVar1 != 0) {
        FileObject_InitBase((intptr_t)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_005523f3;
      }
    }
    __amsg_exit(0x10);
  }
LAB_005523f3:
  SetLastError(dwErrCode);
  return lpTlsValue;
}
