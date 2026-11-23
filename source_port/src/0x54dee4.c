// CRT_Fclose: ported from Pizza Connection 2 at 0x54dee4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dee4
#include "pc2_port.h"

uint32_t __cdecl CRT_Fclose(FILE *arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = 0xffffffff;
  if ((arg1->_flag & 0x40) == 0) {
    CRT_LockFile((uint32_t)arg1);
    uvalue1 = __fclose_lk(arg1);
    CS_LeaveObject((uint32_t)arg1);
  }
  else {
    arg1->_flag = 0;
  }
  return uvalue1;
}
