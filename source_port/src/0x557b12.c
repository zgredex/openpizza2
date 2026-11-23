// FUN_00557b12: ported from Pizza Connection 2 at 0x557b12.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557b12
#include "pc2_port.h"

uint32_t __cdecl FUN_00557b12(LPCSTR arg1)

{
  uint8_t uvalue1;
  BOOL BVar2;
  DWORD DVar3;
  uint32_t uvalue4;
  uint8_t local_10c;
  uint8_t local_10b;
  
  BVar2 = SetCurrentDirectoryA(arg1);
  if (BVar2 != 0) {
    DVar3 = GetCurrentDirectoryA(0x105,(LPSTR)&local_10c);
    if (DVar3 != 0) {
      if (((local_10c != 0x5c) && (local_10c != 0x2f)) || (local_10c != local_10b)) {
        arg1 = (LPCSTR)CONCAT31(((uint8_t)(((intptr_t)arg1) >> 24)),0x3d);
        uvalue4 = FUN_00557b98((uint32_t)local_10c);
        uvalue1 = SUB41(arg1,0);
        arg1 = (LPCSTR)(uint32_t)CONCAT12(0x3a,CONCAT11((char)uvalue4,uvalue1));
        BVar2 = SetEnvironmentVariableA((LPCSTR)&arg1,(LPCSTR)&local_10c);
        if (BVar2 == 0) goto LAB_00557b86;
      }
      return 0;
    }
  }
LAB_00557b86:
  DVar3 = GetLastError();
  CRT_MapWin32Error(DVar3);
  return 0xffffffff;
}
