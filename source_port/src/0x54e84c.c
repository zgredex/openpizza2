// __global_unwind2: ported from Pizza Connection 2 at 0x54e84c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e84c
#include "pc2_port.h"

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID arg1)

{
  RtlUnwind(arg1,(PVOID)0x54e864,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}
