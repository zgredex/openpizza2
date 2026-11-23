// _memset: ported from Pizza Connection 2 at 0x555ce0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555ce0
#include "pc2_port.h"

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  size_t svalue3;
  uint32_t *uptr4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uvalue1 = _Val & 0xff;
  uptr4 = _Dst;
  if (3 < _Size) {
    uvalue2 = -(intptr_t)_Dst & 3;
    svalue3 = _Size;
    if (uvalue2 != 0) {
      svalue3 = _Size - uvalue2;
      do {
        *(uint8_t *)uptr4 = (uint8_t)_Val;
        uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
        uvalue2 = uvalue2 - 1;
      } while (uvalue2 != 0);
    }
    uvalue1 = uvalue1 * 0x1010101;
    _Size = svalue3 & 3;
    uvalue2 = svalue3 >> 2;
    if (uvalue2 != 0) {
      for (; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
        *uptr4 = uvalue1;
        uptr4 = uptr4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)uptr4 = (char)uvalue1;
    uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}
