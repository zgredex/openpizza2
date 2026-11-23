// CRT_CxxFrameHandler: ported from Pizza Connection 2 at 0x54e5f6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e5f6
#include "pc2_port.h"

uint32_t __cdecl
CRT_CxxFrameHandler(PEXCEPTION_RECORD arg1,PVOID arg2,DWORD arg3,uint32_t arg4)

{
  int *in_EAX;
  uint32_t uvalue1;
  
                    /* C++ frame-handler entry that forwards FuncInfo to the internal dispatcher. */
  uvalue1 = CRT_InternalCxxFrameHandler(arg1,arg2,arg3,arg4,in_EAX,0,(PVOID)0x0,'\0');
  return uvalue1;
}
