// CRT_CloseLocked: ported from Pizza Connection 2 at 0x54fee8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fee8
#include "pc2_port.h"

uint32_t __cdecl CRT_CloseLocked(uint32_t arg1)

{
  int value1;
  int value2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  uint32_t uvalue5;
  
  value1 = CRT_GetOsHandle(arg1);
  if (value1 != -1) {
    if ((arg1 == 1) || (arg1 == 2)) {
      value1 = CRT_GetOsHandle(2);
      value2 = CRT_GetOsHandle(1);
      if (value2 == value1) goto LAB_0054ff36;
    }
    hObject = (HANDLE)CRT_GetOsHandle(arg1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_0054ff38;
    }
  }
LAB_0054ff36:
  DVar4 = 0;
LAB_0054ff38:
  CRT_FreeOsfHandle(arg1);
  *(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uvalue5 = 0;
  }
  else {
    CRT_MapWin32Error(DVar4);
    uvalue5 = 0xffffffff;
  }
  return uvalue5;
}
