// FUN_00557ae6: ported from Pizza Connection 2 at 0x557ae6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557ae6
#include "pc2_port.h"


uint32_t __cdecl FUN_00557ae6(LPCSTR arg1)

{
  BOOL BVar1;
  uint32_t uvalue2;
  
  BVar1 = CreateDirectoryA(arg1,(LPSECURITY_ATTRIBUTES)0x0);
  if (BVar1 == 0) {
    uvalue2 = GetLastError();
  }
  else {
    uvalue2 = 0;
  }
  if (uvalue2 == 0) {
    return 0;
  }
  CRT_MapWin32Error(uvalue2);
  return 0xffffffff;
}
