// CRT_Filebuf_Close: ported from Pizza Connection 2 at 0x54ce1e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ce1e
#include "pc2_port.h"

int * __fastcall CRT_Filebuf_Close(int *arg1)

{
  int value1;
  int value2;
  
  if (arg1[0x13] != -1) {
    if (arg1[0xc] < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)(arg1 + 0xd));
    }
    value1 = (**(code **)(*arg1 + 4))();
    value2 = CRT_Close(arg1[0x13]);
    if ((value2 != -1) && (value1 != -1)) {
      arg1[0x13] = -1;
      if (arg1[0xc] < 0) {
        CS_LeaveRaw((LPCRITICAL_SECTION)(arg1 + 0xd));
      }
      return arg1;
    }
    if (arg1[0xc] < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)(arg1 + 0xd));
    }
  }
  return (int *)0x0;
}
