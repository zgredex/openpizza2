// Storage_ProduceBatch: ported from Pizza Connection 2 at 0x514330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514330
#include "pc2_port.h"

void __fastcall Storage_ProduceBatch(void *arg1)

{
  int value1;
  void *self;
  uint32_t *uptr2;
  int value3;
  uint32_t *uptr4;
  uint32_t *uptr5;
  double fVar6;
  int local_c;
  
  value1 = Storage_GetCapacity((intptr_t)arg1);
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x28),
                              (int *)0x0);
  uptr2 = (uint32_t *)Array_GetStride60(self,*(int *)((intptr_t)arg1 + 0x30));
  if (uptr2 != (uint32_t *)0x0) {
    value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x24));
    local_c = value1 - *(int *)((intptr_t)arg1 + 0x58);
    value1 = value1 / (*(int *)((intptr_t)arg1 + 0x2c) + 1);
    if (value1 < local_c) {
      local_c = value1;
    }
    uptr2[*(int *)((intptr_t)arg1 + 0x24) + 5] = uptr2[*(int *)((intptr_t)arg1 + 0x24) + 5] + local_c;
    if (0 < local_c) {
      do {
        uptr4 = operator_new(0x20);
        uptr5 = uptr4;
        for (value1 = 8; value1 != 0; value1 = value1 + -1) {
          *uptr5 = 0;
          uptr5 = uptr5 + 1;
        }
        *uptr4 = 200000;
        fVar6 = BuildingValue_Compute(value3,self,(intptr_t)uptr2);
        uptr4[4] = (float)fVar6;
        uptr4[1] = *uptr2;
        uptr4[3] = uptr2[1];
        List_Add((void *)((intptr_t)arg1 + 0x44),uptr4);
        local_c = local_c + -1;
      } while (local_c != 0);
    }
    Storage_DistributeCostToShops(arg1,*(float *)((intptr_t)self + 0x94) * 100.0,'\0');
    if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x1861c,0x23,0);
    }
  }
  return;
}
