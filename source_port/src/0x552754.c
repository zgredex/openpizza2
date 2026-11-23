// CRT_IsIndst: ported from Pizza Connection 2 at 0x552754.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552754
#include "pc2_port.h"

bool __cdecl CRT_IsIndst(int *arg1)

{
  bool flag1;
  
  CRT_Lock(0xb);
  flag1 = Time_IsInActiveRange(arg1);
  CS_LeaveIndexed(0xb);
  return flag1;
}
