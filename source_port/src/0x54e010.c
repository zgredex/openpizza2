// _strchr: ported from Pizza Connection 2 at 0x54e010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e010
#include "pc2_port.h"

/* Library Function - Single Match
    _strchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint32_t uvalue1;
  char cVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t *uptr5;
  
  while (((uint32_t)_Str & 3) != 0) {
    uvalue1 = *(uint32_t *)_Str;
    if ((char)uvalue1 == (char)_Val) {
      return (char *)(uint32_t *)_Str;
    }
    _Str = (char *)((intptr_t)_Str + 1);
    if ((char)uvalue1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uvalue1 = *(uint32_t *)_Str;
      uvalue4 = uvalue1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uvalue3 = uvalue1 ^ 0xffffffff ^ uvalue1 + 0x7efefeff;
      uptr5 = (uint32_t *)((intptr_t)_Str + 4);
      if (((uvalue4 ^ 0xffffffff ^ uvalue4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)uptr5;
      if ((uvalue3 & 0x81010100) != 0) {
        if ((uvalue3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uvalue1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uvalue1 = *(uint32_t *)_Str;
    if ((char)uvalue1 == (char)_Val) {
      return (char *)(uint32_t *)_Str;
    }
    if ((char)uvalue1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uvalue1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((intptr_t)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uvalue1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((intptr_t)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uvalue1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((intptr_t)_Str + 3);
    }
    _Str = (char *)uptr5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}
