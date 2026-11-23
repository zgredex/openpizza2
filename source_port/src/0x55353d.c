// CRT_Inconsistency: ported from Pizza Connection 2 at 0x55353d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55353d
#include "pc2_port.h"


void CRT_Inconsistency(void)

{
  void *pvStack_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  puStack_c = &DAT_0055ce78;
  puStack_10 = &LAB_00553be0;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_CRT_Terminate_00576d00 != (uint8_t *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_CRT_Terminate_00576d00)();
  }
  local_8 = 0xffffffff;
  CRT_Terminate();
  return;
}
