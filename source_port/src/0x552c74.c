// CRT_InternalCxxFrameHandler: ported from Pizza Connection 2 at 0x552c74.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552c74
#include "pc2_port.h"

uint32_t __cdecl
CRT_InternalCxxFrameHandler
          (PEXCEPTION_RECORD arg1,PVOID arg2,DWORD arg3,uint32_t arg4,int *arg5,
          int arg6,PVOID arg7,char arg8)

{
  code *cptr1;
  uint32_t uvalue2;
  
                    /* Shared C++ exception dispatcher for search and unwind passes. */
  if (*arg5 != 0x19930520) {
    CRT_Inconsistency();
  }
  if ((arg1->ExceptionFlags & 0x66) == 0) {
    if (arg5[3] != 0) {
      if (((arg1->ExceptionCode == 0xe06d7363) && (0x19930520 < arg1->ExceptionInformation[0])
          ) && (cptr1 = *(code **)(arg1->ExceptionInformation[2] + 8), cptr1 != (code *)0x0)) {
        uvalue2 = (*cptr1)(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
        return uvalue2;
      }
      CRT_CxxCatchSearch(arg1,arg2,arg3,arg4,(uint32_t)arg5,arg8,arg6,arg7);
    }
  }
  else if ((arg5[1] != 0) && (arg6 == 0)) {
    CRT_FrameUnwindToState((intptr_t)arg2,arg4,(intptr_t)arg5,-1);
  }
  return 1;
}
