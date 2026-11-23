// _strcmp: ported from Pizza Connection 2 at 0x54f000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f000
#include "pc2_port.h"

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  uint16_t uvalue1;
  uint32_t uvalue2;
  uint8_t flag3;
  bool flag4;
  
  if (((uint32_t)_Str1 & 3) != 0) {
    if (((uint32_t)_Str1 & 1) != 0) {
      flag3 = *_Str1;
      _Str1 = _Str1 + 1;
      flag4 = flag3 < (uint8_t)*_Str2;
      if (flag3 != *_Str2) goto LAB_0054f044;
      _Str2 = _Str2 + 1;
      if (flag3 == 0) {
        return 0;
      }
      if (((uint32_t)_Str1 & 2) == 0) goto LAB_0054f010;
    }
    uvalue1 = *(uint16_t *)_Str1;
    _Str1 = _Str1 + 2;
    flag3 = (uint8_t)uvalue1;
    flag4 = flag3 < (uint8_t)*_Str2;
    if (flag3 != *_Str2) goto LAB_0054f044;
    if (flag3 == 0) {
      return 0;
    }
    flag3 = (uint8_t)((uint16_t)uvalue1 >> 8);
    flag4 = flag3 < (uint8_t)_Str2[1];
    if (flag3 != _Str2[1]) goto LAB_0054f044;
    if (flag3 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0054f010:
  while( true ) {
    uvalue2 = *(uint32_t *)_Str1;
    flag3 = (uint8_t)uvalue2;
    flag4 = flag3 < (uint8_t)*_Str2;
    if (flag3 != *_Str2) break;
    if (flag3 == 0) {
      return 0;
    }
    flag3 = (uint8_t)((uint32_t)uvalue2 >> 8);
    flag4 = flag3 < (uint8_t)_Str2[1];
    if (flag3 != _Str2[1]) break;
    if (flag3 == 0) {
      return 0;
    }
    flag3 = (uint8_t)((uint32_t)uvalue2 >> 0x10);
    flag4 = flag3 < (uint8_t)_Str2[2];
    if (flag3 != _Str2[2]) break;
    if (flag3 == 0) {
      return 0;
    }
    flag3 = (uint8_t)((uint32_t)uvalue2 >> 0x18);
    flag4 = flag3 < (uint8_t)_Str2[3];
    if (flag3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (flag3 == 0) {
      return 0;
    }
  }
LAB_0054f044:
  return (uint32_t)flag4 * -2 + 1;
}
