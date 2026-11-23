// CRT_CallCatchBlock2: ported from Pizza Connection 2 at 0x54e62c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e62c
#include "pc2_port.h"

uint32_t __cdecl
CRT_CallCatchBlock2(uint32_t arg1,uint32_t arg2,uint32_t arg3,int arg4,int arg5
                   )

{
  uint32_t uvalue1;
  void *local_18;
  code *local_14;
  uint32_t local_10;
  uint32_t local_c;
  int local_8;
  
                    /* Invokes a catch funclet under a synthetic registration node. */
  local_10 = arg2;
  local_14 = CRT_CatchBlockFrameHandler;
  local_8 = arg4 + 1;
  local_c = arg1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uvalue1 = __CallSettingFrame_12(arg3,arg1,arg5);
  ExceptionList = local_18;
  return uvalue1;
}
