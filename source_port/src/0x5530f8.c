// CRT_CallCatchBlock: ported from Pizza Connection 2 at 0x5530f8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5530f8
#include "pc2_port.h"


uint32_t __cdecl
CRT_CallCatchBlock(DWORD arg1,uint32_t arg2,DWORD arg3,uint32_t arg4,
                  uint32_t arg5,int arg6,int arg7)

{
  DWORD *pDVar1;
  uint32_t uvalue2;
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
                    /* Runs a catch funclet with swapped current-exception state. */
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055ce28;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CRT_GetThreadData();
  CRT_GetThreadData();
  pDVar1 = CRT_GetThreadData();
  pDVar1[0x1b] = arg1;
  pDVar1 = CRT_GetThreadData();
  pDVar1[0x1c] = arg3;
  local_8 = 1;
  uvalue2 = CRT_CallCatchBlock2(arg2,arg4,arg5,arg6,arg7);
  local_8 = 0xffffffff;
  CRT_CallCatchBlockFinally();
  ExceptionList = local_14;
  return uvalue2;
}
