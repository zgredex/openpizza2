// CRT_ThreadStart: ported from Pizza Connection 2 at 0x54f1de.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f1de
#include "pc2_port.h"


uint32_t CRT_ThreadStart(LPVOID arg1)

{
  BOOL BVar1;
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055ccf8;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  BVar1 = TlsSetValue(DAT_00576ac4,arg1);
  if (BVar1 == 0) {
    __amsg_exit(0x10);
  }
  if (PTR_NoOp_Empty_0057671c != (uint8_t *)0x0) {
    (*(code *)PTR_NoOp_Empty_0057671c)();
  }
  local_8 = 0;
  (**(code **)((intptr_t)arg1 + 0x48))(*(uint32_t *)((intptr_t)arg1 + 0x4c));
  CRT_EndThread();
  ExceptionList = local_14;
  return 0;
}
