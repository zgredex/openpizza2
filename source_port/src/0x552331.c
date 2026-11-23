// CRT_MtInit: ported from Pizza Connection 2 at 0x552331.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552331
#include "pc2_port.h"

uint32_t CRT_MtInit(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  Thread_InitLocks();
  DAT_00576ac4 = TlsAlloc();
  if (DAT_00576ac4 != 0xffffffff) {
    lpTlsValue = (DWORD *)CRT_Calloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00576ac4,lpTlsValue);
      if (BVar1 != 0) {
        FileObject_InitBase((intptr_t)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}
