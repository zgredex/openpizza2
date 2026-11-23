// CRT_CatchIt: ported from Pizza Connection 2 at 0x55307d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55307d
#include "pc2_port.h"

void __cdecl
CRT_CatchIt(PEXCEPTION_RECORD arg1,PVOID arg2,DWORD arg3,uint32_t arg4,int arg5,
           uint8_t *arg6,uint8_t *arg7,int *arg8,int arg9,PVOID arg10)

{
  uint8_t *UNRECOVERED_JUMPTABLE;
  
                    /* Builds the catch object, unwinds, and transfers to the catch funclet. */
  if (arg7 != (uint8_t *)0x0) {
    CRT_BuildCatchObject((intptr_t)arg1,(intptr_t)arg2,arg6,arg7);
  }
  if (arg10 == (PVOID)0x0) {
    arg10 = arg2;
  }
  else {
  }
  CRT_Unwind(arg10,arg1);
  CRT_FrameUnwindToState((intptr_t)arg2,arg4,arg5,*arg8);
  *(int *)((intptr_t)arg2 + 8) = arg8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (uint8_t *)
       CRT_CallCatchBlock((DWORD)arg1,arg2,arg3,arg5,*(uint32_t *)(arg6 + 0xc),
                          arg9,0x100);
  if (UNRECOVERED_JUMPTABLE != (uint8_t *)0x0) {
    CRT_CallExceptionHandler(UNRECOVERED_JUMPTABLE);
  }
  return;
}
