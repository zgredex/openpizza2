// _strncpy: ported from Pizza Connection 2 at 0x54f620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f620
#include "pc2_port.h"

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  char cVar3;
  uint32_t uvalue4;
  uint32_t *uptr5;
  
  if (_Count == 0) {
    return _Dest;
  }
  uptr5 = (uint32_t *)_Dest;
  if (((uint32_t)_Source & 3) != 0) {
    while( true ) {
      uvalue4 = *(uint32_t *)_Source;
      _Source = (char *)((intptr_t)_Source + 1);
      *(char *)uptr5 = (char)uvalue4;
      uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uvalue4 == '\0') break;
      if (((uint32_t)_Source & 3) == 0) {
        uvalue4 = _Count >> 2;
        goto joined_r0x0054f65e;
      }
    }
    do {
      if (((uint32_t)uptr5 & 3) == 0) {
        uvalue4 = _Count >> 2;
        cVar3 = '\0';
        if (uvalue4 == 0) goto LAB_0054f69b;
        goto LAB_0054f709;
      }
      *(char *)uptr5 = '\0';
      uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uvalue4 = _Count >> 2;
  if (uvalue4 != 0) {
    do {
      uvalue1 = *(uint32_t *)_Source;
      uvalue2 = *(uint32_t *)_Source;
      _Source = (char *)((intptr_t)_Source + 4);
      if (((uvalue1 ^ 0xffffffff ^ uvalue1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uvalue2 == '\0') {
          *uptr5 = 0;
joined_r0x0054f705:
          while( true ) {
            uvalue4 = uvalue4 - 1;
            uptr5 = uptr5 + 1;
            if (uvalue4 == 0) break;
LAB_0054f709:
            *uptr5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0054f69b;
          return _Dest;
        }
        if ((char)(uvalue2 >> 8) == '\0') {
          *uptr5 = uvalue2 & 0xff;
          goto joined_r0x0054f705;
        }
        if ((uvalue2 & 0xff0000) == 0) {
          *uptr5 = uvalue2 & 0xffff;
          goto joined_r0x0054f705;
        }
        if ((uvalue2 & 0xff000000) == 0) {
          *uptr5 = uvalue2;
          goto joined_r0x0054f705;
        }
      }
      *uptr5 = uvalue2;
      uptr5 = uptr5 + 1;
      uvalue4 = uvalue4 - 1;
joined_r0x0054f65e:
    } while (uvalue4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint32_t *)_Source;
    _Source = (char *)((intptr_t)_Source + 1);
    *(char *)uptr5 = cVar3;
    uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_0054f69b:
        *(char *)uptr5 = cVar3;
        uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}
