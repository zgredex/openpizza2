// _malloc: ported from Pizza Connection 2 at 0x551f8b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551f8b
#include "pc2_port.h"

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_005858f8);
  return pvVar1;
}
