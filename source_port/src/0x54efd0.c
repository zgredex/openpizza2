// _strrchr: ported from Pizza Connection 2 at 0x54efd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54efd0
#include "pc2_port.h"

/* Library Function - Single Match
    _strrchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int value2;
  char *cptr4;
  char *cptr3;
  
  value2 = -1;
  do {
    cptr4 = _Str;
    if (value2 == 0) break;
    value2 = value2 + -1;
    cptr4 = _Str + 1;
    cVar1 = *_Str;
    _Str = cptr4;
  } while (cVar1 != '\0');
  value2 = -(value2 + 1);
  cptr4 = cptr4 + -1;
  do {
    cptr3 = cptr4;
    if (value2 == 0) break;
    value2 = value2 + -1;
    cptr3 = cptr4 + -1;
    cVar1 = *cptr4;
    cptr4 = cptr3;
  } while ((char)_Ch != cVar1);
  cptr3 = cptr3 + 1;
  if (*cptr3 != (char)_Ch) {
    cptr3 = (char *)0x0;
  }
  return cptr3;
}
