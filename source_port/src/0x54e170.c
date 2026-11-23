// _strstr: ported from Pizza Connection 2 at 0x54e170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e170
#include "pc2_port.h"

/* Library Function - Single Match
    _strstr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *cptr1;
  char *cptr2;
  char cVar3;
  uint32_t uvalue4;
  char cVar5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  char *cptr8;
  uint32_t *uptr9;
  char *cptr10;
  
  cVar3 = *_SubStr;
  if (cVar3 == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    while (((uint32_t)_Str & 3) != 0) {
      uvalue4 = *(uint32_t *)_Str;
      if ((char)uvalue4 == cVar3) {
        return (char *)(uint32_t *)_Str;
      }
      _Str = (char *)((intptr_t)_Str + 1);
      if ((char)uvalue4 == '\0') {
        return (char *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uvalue4 = *(uint32_t *)_Str;
        uvalue7 = uvalue4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uvalue6 = uvalue4 ^ 0xffffffff ^ uvalue4 + 0x7efefeff;
        uptr9 = (uint32_t *)((intptr_t)_Str + 4);
        if (((uvalue7 ^ 0xffffffff ^ uvalue7 + 0x7efefeff) & 0x81010100) != 0) break;
        _Str = (char *)uptr9;
        if ((uvalue6 & 0x81010100) != 0) {
          if ((uvalue6 & 0x1010100) != 0) {
            return (char *)0x0;
          }
          if ((uvalue4 + 0x7efefeff & 0x80000000) == 0) {
            return (char *)0x0;
          }
        }
      }
      uvalue4 = *(uint32_t *)_Str;
      if ((char)uvalue4 == cVar3) {
        return (char *)(uint32_t *)_Str;
      }
      if ((char)uvalue4 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uvalue4 >> 8);
      if (cVar5 == cVar3) {
        return (char *)((intptr_t)_Str + 1);
      }
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uvalue4 >> 0x10);
      if (cVar5 == cVar3) {
        return (char *)((intptr_t)_Str + 2);
      }
      if (cVar5 == '\0') break;
      cVar5 = (char)(uvalue4 >> 0x18);
      if (cVar5 == cVar3) {
        return (char *)((intptr_t)_Str + 3);
      }
      _Str = (char *)uptr9;
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
    }
    return (char *)0x0;
  }
  do {
    cVar5 = *_Str;
    do {
      while (_Str = _Str + 1, cVar5 != cVar3) {
        if (cVar5 == '\0') {
          return (char *)0x0;
        }
        cVar5 = *_Str;
      }
      cVar5 = *_Str;
      cptr10 = _Str + 1;
      cptr8 = _SubStr;
    } while (cVar5 != _SubStr[1]);
    do {
      if (cptr8[2] == '\0') {
LAB_0054e1e3:
        return _Str + -1;
      }
      if (*cptr10 != cptr8[2]) break;
      cptr1 = cptr8 + 3;
      if (*cptr1 == '\0') goto LAB_0054e1e3;
      cptr2 = cptr10 + 1;
      cptr8 = cptr8 + 2;
      cptr10 = cptr10 + 2;
    } while (*cptr1 == *cptr2);
  } while( true );
}
