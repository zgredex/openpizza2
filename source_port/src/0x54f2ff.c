// CRT_DoExit: ported from Pizza Connection 2 at 0x54f2ff.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f2ff
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CRT_DoExit(UINT arg1,int arg2,int arg3)

{
  HANDLE hProcess;
  uint32_t *uptr1;
  UINT uExitCode;
  
  CRT_LockExit();
  if (DAT_00585650 == 1) {
    uExitCode = arg1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0058564c = 1;
  DAT_00585648 = (uint8_t)arg3;
  if (arg2 == 0) {
    if ((DAT_00586d34 != (uint32_t *)0x0) &&
       (uptr1 = (uint32_t *)(DAT_00586d30 - 4), DAT_00586d34 <= uptr1)) {
      do {
        if ((code *)*uptr1 != (code *)0x0) {
          (*(code *)*uptr1)();
        }
        uptr1 = uptr1 + -1;
      } while (DAT_00586d34 <= uptr1);
    }
    CRT_RunAtexitRange((uint32_t *)&DAT_00563048,(uint32_t *)&DAT_00563050);
  }
  CRT_RunAtexitRange((uint32_t *)&DAT_00563054,(uint32_t *)&DAT_0056305c);
  if (arg3 == 0) {
    DAT_00585650 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(arg1);
  }
  CRT_UnlockExit();
  return;
}
