// _strlen: ported from Pizza Connection 2 at 0x550920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550920
#include "pc2_port.h"

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint32_t uvalue1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  
  uptr2 = (uint32_t *)_Str;
  do {
    if (((uint32_t)uptr2 & 3) == 0) goto LAB_00550940;
    uvalue1 = *uptr2;
    uptr2 = (uint32_t *)((intptr_t)uptr2 + 1);
  } while ((char)uvalue1 != '\0');
LAB_00550973:
  return (size_t)((intptr_t)uptr2 + (-1 - (intptr_t)_Str));
LAB_00550940:
  do {
    do {
      uptr3 = uptr2;
      uptr2 = uptr3 + 1;
    } while (((*uptr3 ^ 0xffffffff ^ *uptr3 + 0x7efefeff) & 0x81010100) == 0);
    uvalue1 = *uptr3;
    if ((char)uvalue1 == '\0') {
      return (intptr_t)uptr3 - (intptr_t)_Str;
    }
    if ((char)(uvalue1 >> 8) == '\0') {
      return (size_t)((intptr_t)uptr3 + (1 - (intptr_t)_Str));
    }
    if ((uvalue1 & 0xff0000) == 0) {
      return (size_t)((intptr_t)uptr3 + (2 - (intptr_t)_Str));
    }
  } while ((uvalue1 & 0xff000000) != 0);
  goto LAB_00550973;
}
