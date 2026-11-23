// LookupTable_HasKey: ported from Pizza Connection 2 at 0x514220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514220
#include "pc2_port.h"

bool __thiscall LookupTable_HasKey(void *self,int arg1)

{
  int value1;
  
  value1 = Array_FindPair(self,arg1);
  return value1 != -1;
}
