// Storage_SettlePendingOrders: ported from Pizza Connection 2 at 0x513ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513ff0
#include "pc2_port.h"

void __fastcall Storage_SettlePendingOrders(int arg1)

{
  int value1;
  void *self;
  int *ptr2;
  int value3;
  double fVar4;
  float local_8;
  
  local_8 = 0.0;
  value1 = *(int *)(arg1 + 0x58);
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x24));
  value3 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)(arg1 + 0x44),value3,(int *)0x0);
      fVar4 = Market_ComputeWeightedAveragePrice((intptr_t)DAT_0057c670,ptr2,self);
      local_8 = (float)(fVar4 + (double)local_8);
      Mem_Free(ptr2);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  List_Node_Reset(arg1 + 0x44);
  Game_CanAffordWithCurrency(self,0xc,local_8,'\0',0xffffffff);
  return;
}
