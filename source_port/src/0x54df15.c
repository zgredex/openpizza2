// __fclose_lk: ported from Pizza Connection 2 at 0x54df15.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54df15
#include "pc2_port.h"

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

uint32_t __cdecl __fclose_lk(FILE *arg1)

{
  int value1;
  uint32_t uvalue2;
  
  uvalue2 = 0xffffffff;
  if ((arg1->_flag & 0x83) != 0) {
    uvalue2 = CRT_FlushStream((int *)arg1);
    __freebuf(arg1);
    value1 = CRT_Close(arg1->_file);
    if (value1 < 0) {
      uvalue2 = 0xffffffff;
    }
    else if (arg1->_tmpfname != (char *)0x0) {
      CRT_FreeInternal(arg1->_tmpfname);
      arg1->_tmpfname = (char *)0x0;
    }
  }
  arg1->_flag = 0;
  return uvalue2;
}
