// CRT_FrameUnwindToState: ported from Pizza Connection 2 at 0x552fc9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552fc9
#include "pc2_port.h"


void __cdecl CRT_FrameUnwindToState(int arg1,uint32_t arg2,int arg3,int arg4)

{
  int value1;
  int value2;
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  puStack_c = &DAT_0055ce18;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (value2 = *(int *)(arg1 + 8); local_8 = 0xffffffff, value2 != arg4;
      value2 = *(int *)(*(int *)(arg3 + 8) + value2 * 8)) {
    if ((value2 < 0) || (*(int *)(arg3 + 4) <= value2)) {
      CRT_Inconsistency();
    }
    local_8 = 0;
    value1 = *(int *)(*(int *)(arg3 + 8) + 4 + value2 * 8);
    if (value1 != 0) {
      __CallSettingFrame_12(value1,arg1,0x103);
    }
  }
  *(int *)(arg1 + 8) = value2;
  ExceptionList = local_14;
  return;
}
