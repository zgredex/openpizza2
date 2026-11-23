// CRT_TzsetInit: ported from Pizza Connection 2 at 0x55249f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55249f
#include "pc2_port.h"

void CRT_TzsetInit(void)

{
  if (DAT_00585728 == 0) {
    CRT_Lock(0xb);
    if (DAT_00585728 == 0) {
      CRT_Tzset();
      DAT_00585728 = DAT_00585728 + 1;
    }
    CS_LeaveIndexed(0xb);
  }
  return;
}
