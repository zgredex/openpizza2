// Game_ConsumeObject: ported from Pizza Connection 2 at 0x47eab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47eab0
#include "pc2_port.h"

uint32_t __thiscall Game_ConsumeObject(void *self,int arg1)

{
  int *ptr1;
  void *pvVar2;
  double fVar3;
  
  ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1998),arg1,(int *)0x0);
  if (ptr1 == (int *)0x0) {
    return 0;
  }
  IDMap_RemoveRecursive((void *)((intptr_t)self + 0x1998),arg1);
  pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  fVar3 = Market_ComputeWeightedAveragePrice((intptr_t)DAT_0057c670,ptr1,pvVar2);
  Game_CanAfford(self,0xc,(float)fVar3,'\0',-1);
  Mem_Free(ptr1);
  return 1;
}
