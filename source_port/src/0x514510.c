// Storage_OrderDelivery: ported from Pizza Connection 2 at 0x514510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514510
#include "pc2_port.h"

void __fastcall Storage_OrderDelivery(int arg1)

{
  int value1;
  void *self;
  void *pvVar2;
  
  value1 = Storage_GetFillPercent(arg1);
  if (value1 < 0x22) {
    value1 = Game_CountFilteredObjects(DAT_0057c670,0x18,0xc,*(int *)(arg1 + 0x34),-1);
    if (((value1 < 1) && (*(int *)(*(int *)(arg1 + 0x34) + 0x38) == 0)) &&
       (*(int *)(arg1 + 0x30) != -1)) {
      self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(arg1 + 0x28),
                                  (int *)0x0);
      value1 = Array_GetStride60(self,*(int *)(arg1 + 0x30));
      pvVar2 = (void *)Game_FindRecordByField24(self,*(int *)(value1 + 0x10));
      City_SpawnDeliveryVehicles(self,arg1,pvVar2);
    }
  }
  return;
}
