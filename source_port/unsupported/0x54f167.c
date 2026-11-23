// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x54f167.c:19:60: error: use of undeclared identifier 'CRT_ThreadStart'
// CRT_BeginThread: ported from Pizza Connection 2 at 0x54f167.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f167
#include "pc2_port.h"

HANDLE __cdecl CRT_BeginThread(int arg1,SIZE_T arg2,int arg3)

{
  int *lpThreadId;
  HANDLE hThread;
  DWORD DVar1;
  
  DVar1 = 0;
  lpThreadId = CRT_Calloc(1,0x74);
  if (lpThreadId != (int *)0x0) {
    FileObject_InitBase((intptr_t)lpThreadId);
    lpThreadId[0x12] = arg1;
    lpThreadId[0x13] = arg3;
    hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,arg2,CRT_ThreadStart,lpThreadId,4,
                           (LPDWORD)lpThreadId);
    lpThreadId[1] = (intptr_t)hThread;
    if ((hThread != (HANDLE)0x0) && (DVar1 = ResumeThread(hThread), DVar1 != 0xffffffff)) {
      return hThread;
    }
    DVar1 = GetLastError();
  }
  CRT_FreeInternal(lpThreadId);
  if (DVar1 != 0) {
    CRT_MapWin32Error(DVar1);
  }
  return (HANDLE)0xffffffff;
}
