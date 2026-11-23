// CRT_Tolower: ported from Pizza Connection 2 at 0x54f8a9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f8a9
#include "pc2_port.h"

uint32_t __cdecl CRT_Tolower(uint32_t arg1)

{
  void *extraout_ECX;
  bool flag1;
  void *self;
  
  if (DAT_005857cc == 0) {
    if ((0x40 < (intptr_t)arg1) && ((intptr_t)arg1 < 0x5b)) {
      return arg1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_00585be8);
    flag1 = DAT_00585be4 != 0;
    self = extraout_ECX;
    if (flag1) {
      InterlockedDecrement((LONG *)&DAT_00585be8);
      self = (void *)0x13;
      CRT_Lock(0x13);
    }
    arg1 = CRT_Tolower_L(self,arg1);
    if (flag1) {
      CS_LeaveIndexed(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_00585be8);
    }
  }
  return arg1;
}
