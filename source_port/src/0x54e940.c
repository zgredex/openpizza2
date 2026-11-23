// _strncmp: ported from Pizza Connection 2 at 0x54e940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e940
#include "pc2_port.h"

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t svalue3;
  int value4;
  uint32_t uvalue5;
  char *cptr6;
  char *cptr7;
  
  uvalue5 = 0;
  if (_MaxCount != 0) {
    svalue3 = _MaxCount;
    cptr6 = _Str1;
    do {
      if (svalue3 == 0) break;
      svalue3 = svalue3 - 1;
      cVar1 = *cptr6;
      cptr6 = cptr6 + 1;
    } while (cVar1 != '\0');
    value4 = _MaxCount - svalue3;
    do {
      cptr6 = _Str2;
      cptr7 = _Str1;
      if (value4 == 0) break;
      value4 = value4 + -1;
      cptr7 = _Str1 + 1;
      cptr6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = cptr6;
      _Str1 = cptr7;
    } while (cVar1 == cVar2);
    uvalue5 = 0;
    if ((uint8_t)cptr6[-1] <= (uint8_t)cptr7[-1]) {
      if (cptr6[-1] == cptr7[-1]) {
        return 0;
      }
      uvalue5 = 0xfffffffe;
    }
    uvalue5 = ~uvalue5;
  }
  return uvalue5;
}
