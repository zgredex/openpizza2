// CRT_Wctomb: ported from Pizza Connection 2 at 0x555455.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555455
#include "pc2_port.h"


int __cdecl CRT_Wctomb(LPSTR arg1,WCHAR arg2)

{
  int value1;
  bool flag2;
  
  InterlockedIncrement((LONG *)&DAT_00585be8);
  flag2 = DAT_00585be4 != 0;
  if (flag2) {
    InterlockedDecrement((LONG *)&DAT_00585be8);
    CRT_Lock(0x13);
  }
  value1 = CRT_WctombLocked(arg1,arg2);
  if (flag2) {
    CS_LeaveIndexed(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_00585be8);
  }
  return value1;
}
