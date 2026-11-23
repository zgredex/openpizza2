// __freebuf: ported from Pizza Connection 2 at 0x552017.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552017
#include "pc2_port.h"

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    CRT_FreeInternal(_File->_base);
    *(uint16_t *)&_File->_flag = (uint16_t)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}
