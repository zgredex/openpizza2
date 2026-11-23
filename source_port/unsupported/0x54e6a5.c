// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x54e6a5.c:32:14: error: use of undeclared identifier 'CRT_SeTranslatorFrameHandler'
// CRT_InvokeSeTranslator: ported from Pizza Connection 2 at 0x54e6a5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e6a5
#include "pc2_port.h"

uint32_t __cdecl
CRT_InvokeSeTranslator
          (uint32_t *arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4,
          uint32_t arg5,uint32_t arg6,uint32_t arg7)

{
  DWORD *pDVar1;
  uint8_t auStackY_cc [128];
  uint32_t uvalue2;
  uint32_t **pptr3;
  uint32_t *local_34;
  uint32_t local_30;
  uint32_t *local_2c;
  code *local_28;
  uint32_t local_24;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint8_t *local_10;
  uint8_t *local_c;
  uint32_t local_8;
  
                    /* Calls the thread's SEH-to-C++ exception translator. */
  local_c = auStackY_cc + 200;
  local_10 = auStackY_cc + 0x88;
  local_28 = CRT_SeTranslatorFrameHandler;
  local_24 = arg5;
  local_20 = arg2;
  local_1c = arg6;
  local_18 = arg7;
  local_8 = 0;
  local_14 = 0x54e72d;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = arg1;
  local_30 = arg3;
  pptr3 = &local_34;
  uvalue2 = *arg1;
  pDVar1 = CRT_GetThreadData();
  (*(code *)pDVar1[0x1a])(uvalue2,pptr3);
  if (local_8 != 0) {
    *local_2c = *(uint32_t *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}
