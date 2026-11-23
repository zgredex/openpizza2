// operator_new: ported from Pizza Connection 2 at 0x54e221.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e221
#include "pc2_port.h"

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint32_t arg1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(arg1,1);
  return pvVar1;
}
