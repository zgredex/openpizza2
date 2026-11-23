// CRT_Terminate: ported from Pizza Connection 2 at 0x5534dc.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5534dc
#include "pc2_port.h"


void CRT_Terminate(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  puStack_c = &DAT_0055ce60;
  puStack_10 = &LAB_00553be0;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = CRT_GetThreadData();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = CRT_GetThreadData();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_00555fd6();
  return;
}
