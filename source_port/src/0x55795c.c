// FUN_0055795c: ported from Pizza Connection 2 at 0x55795c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55795c
#include "pc2_port.h"

int __cdecl FUN_0055795c(uint8_t *arg1,size_t arg2)

{
  uint8_t *_Str2;
  int value1;
  int *ptr2;
  
  _Str2 = (uint8_t *)*DAT_00585630;
  ptr2 = DAT_00585630;
  while( true ) {
    if (_Str2 == (uint8_t *)0x0) {
      return -((intptr_t)ptr2 - (intptr_t)DAT_00585630 >> 2);
    }
    value1 = __mbsnbicoll(arg1,_Str2,arg2);
    if ((value1 == 0) &&
       ((*(char *)(*ptr2 + arg2) == '=' || (*(char *)(*ptr2 + arg2) == '\0')))) break;
    _Str2 = (uint8_t *)ptr2[1];
    ptr2 = ptr2 + 1;
  }
  return (intptr_t)ptr2 - (intptr_t)DAT_00585630 >> 2;
}
