// Object_IsSiteRatingSufficient: ported from Pizza Connection 2 at 0x5080f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5080f0
#include "pc2_port.h"

bool __thiscall Object_IsSiteRatingSufficient(void *self,void *arg1)

{
  int value1;
  
  if (*(int *)((intptr_t)arg1 + 0x2c) == 0) {
    value1 = Branch_GetCustomerGroupRating(arg1,*(int *)((intptr_t)self + 0x34),0);
    return *(int *)((intptr_t)self + 0x2c) <= value1;
  }
  return false;
}
