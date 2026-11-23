// Branch_GetRecipePriceParts: ported from Pizza Connection 2 at 0x513c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513c40
#include "pc2_port.h"

void __thiscall
Branch_GetRecipePriceParts
          (void *self,int arg1,uint32_t *arg2,float *arg3,int *arg4,
          uint32_t *arg5)

{
  double fVar1;
  int64_t lvalue2;
  
  if (*arg4 == -999) {
    *arg4 = *(int *)(arg1 + 0x14a8);
  }
  *arg2 = *(uint32_t *)(arg1 + 0x14ac);
  Branch_GetBuildingValue(arg1);
  lvalue2 = __ftol();
  *arg5 = (intptr_t)lvalue2;
  fVar1 = Get_Float44((intptr_t)self);
  *arg3 = (float)fVar1;
  return;
}
