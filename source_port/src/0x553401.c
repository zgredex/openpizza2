// CRT_InvokeExceptionHandler: ported from Pizza Connection 2 at 0x553401.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553401
#include "pc2_port.h"


void __cdecl CRT_InvokeExceptionHandler(int arg1)

{
  uint8_t *UNRECOVERED_JUMPTABLE;
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  puStack_c = &DAT_0055ce50;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  if ((arg1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(uint8_t **)(*(int *)(arg1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (uint8_t *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    CRT_LockStub(*(uint32_t *)(arg1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}
