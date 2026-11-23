// __mbsnbicoll: ported from Pizza Connection 2 at 0x557011.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557011
#include "pc2_port.h"

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uint8_t *_Str1,uint8_t *_Str2,size_t _MaxCount)

{
  int value1;
  
  if (_MaxCount == 0) {
    return 0;
  }
  value1 = FUN_0055752d(DAT_00585bc4,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_005859ac);
  if (value1 == 0) {
    return 0x7fffffff;
  }
  return value1 + -2;
}
