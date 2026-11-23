// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x54fcd4.c:22:3: error: use of undeclared identifier '_STARTUPINFOA'
// entry: ported from Pizza Connection 2 at 0x54fcd4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fcd4
#include "pc2_port.h"

struct pc2_obj_0x54fcd4_local_18 { intptr_t ExceptionRecord; };
struct pc2_obj_0x54fcd4_ExceptionRecord { intptr_t ExceptionCode; };
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  struct pc2_obj_0x54fcd4_ExceptionRecord *ExceptionRecord;
  struct pc2_obj_0x54fcd4_local_18 *local_18;
  DWORD DVar1;
  int value2;
  uint8_t *bptr3;
  HMODULE pHVar4;
  UINT UVar5;
  uint32_t uvalue6;
  uint8_t auStack_6a [10];
  _STARTUPINFOA local_60;
  uint8_t *local_1c;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055cd08;
  puStack_10 = &LAB_00553be0;
  pvStack_14 = ExceptionList;
  local_1c = auStack_6a + -0xe;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_00585620 = DVar1 >> 8 & 0xff;
  _DAT_0058561c = DVar1 & 0xff;
  _DAT_00585618 = _DAT_0058561c * 0x100 + _DAT_00585620;
  _DAT_00585614 = DVar1 >> 0x10;
  value2 = CRT_InitHeap(1);
  if (value2 == 0) {
    CRT_AmsgExit(0x1c);
  }
  value2 = CRT_MtInit();
  if (value2 == 0) {
    CRT_AmsgExit(0x10);
  }
  local_8 = 0;
  CRT_IOInit();
  DAT_00586d24 = GetCommandLineA();
  DAT_00585654 = CRT_GetEnvStrings();
  CRT_SetArgv();
  CRT_SetEnvp();
  CRT_CInit();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  bptr3 = CRT_GetWinMainCmdLine();
  uvalue6 = 0;
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  UVar5 = WinMain(pHVar4,uvalue6,(intptr_t)bptr3);
  CRT_Exit(UVar5);
  CRT_XcptFilter(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}
