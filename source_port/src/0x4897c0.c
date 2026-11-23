// City_GetListEndpoints: ported from Pizza Connection 2 at 0x4897c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4897c0
#include "pc2_port.h"

void __thiscall City_GetListEndpoints(void *self,int arg1,int arg2,int *arg3,int *arg4)

{
  int value1;
  short *psVar2;
  int value3;
  
  value3 = 0;
  value1 = IDMap_Lookup((void *)((intptr_t)self + 0x74),arg1,(int *)0x0);
  if (*(short *)(value1 + (arg2 * 3 + 0x1e) * 4) != -1) {
    psVar2 = (short *)(value1 + (arg2 * 3 + 0x1e) * 4);
    do {
      psVar2 = psVar2 + 1;
      value3 = value3 + 1;
    } while (*psVar2 != -1);
  }
  *arg3 = (intptr_t)*(short *)(value1 + (arg2 * 3 + 0x1e) * 4);
  *arg4 = (intptr_t)*(short *)(value1 + 0x76 + (value3 + arg2 * 6) * 2);
  return;
}
