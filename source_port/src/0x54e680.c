// CRT_CatchBlockFrameHandler: ported from Pizza Connection 2 at 0x54e680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e680
#include "pc2_port.h"

void __cdecl CRT_CatchBlockFrameHandler(PEXCEPTION_RECORD arg1,PVOID arg2,DWORD arg3)

{
                    /* Re-enters the C++ frame handler for a catch-block frame. */
  CRT_InternalCxxFrameHandler
            (arg1,*(PVOID *)((intptr_t)arg2 + 0xc),arg3,0,*(int **)((intptr_t)arg2 + 8),
             *(int *)((intptr_t)arg2 + 0x10),arg2,'\0');
  return;
}
