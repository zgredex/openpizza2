// Object_EnsureInit: ported from Pizza Connection 2 at 0x520cd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520cd0
#include "pc2_port.h"

void __fastcall Object_EnsureInit(int *arg1)

{
  if (arg1[7] == 0) {
    arg1[7] = 1;
    (**(code **)(*arg1 + 0xc))(0x34,0,0);
  }
  return;
}
