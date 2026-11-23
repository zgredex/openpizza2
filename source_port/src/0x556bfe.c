// ___add_12: ported from Pizza Connection 2 at 0x556bfe.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556bfe
#include "pc2_port.h"

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void __cdecl ___add_12(uint32_t *arg1,uint32_t *arg2)

{
  int value1;
  
  value1 = FUN_00556bdd(*arg1,*arg2,arg1);
  if (value1 != 0) {
    value1 = FUN_00556bdd(arg1[1],1,arg1 + 1);
    if (value1 != 0) {
      arg1[2] = arg1[2] + 1;
    }
  }
  value1 = FUN_00556bdd(arg1[1],arg2[1],arg1 + 1);
  if (value1 != 0) {
    arg1[2] = arg1[2] + 1;
  }
  FUN_00556bdd(arg1[2],arg2[2],arg1 + 2);
  return;
}
