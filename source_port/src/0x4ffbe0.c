// Game_AddPoliceStations: ported from Pizza Connection 2 at 0x4ffbe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffbe0
#include "pc2_port.h"

void Game_AddPoliceStations(int arg1)

{
  int value1;
  void *self;
  int value2;
  uint32_t uvalue3;
  void *pvVar4;
  int local_8;
  int local_4;
  
                    /* Adds police/security buildings during scenario setup. */
  value1 = Game_GetPlayerCount(DAT_0057c670);
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  while ((0 < arg1 && (value2 = Game_CountRecordsByOwner(self,0x11), value2 < 5))) {
    uvalue3 = Random_RangeFast(0,value1 - 1);
    pvVar4 = (void *)AI_PickInitialBranchPlot(self);
    if (pvVar4 == (void *)0x0) {
      return;
    }
    Game_ComputeTradeOffers(self,(intptr_t)pvVar4,2,&local_4,&local_8,uvalue3,(int *)0x0);
    value2 = *(int *)((intptr_t)pvVar4 + 0x48);
    *(int *)((intptr_t)pvVar4 + 0x3c) = local_8;
    if ((-1 < value2) && (value2 < 4)) {
      value2 = *(int *)(&DAT_00568188 + value2 * 4);
    }
    MapObject_SpawnByKind(self,pvVar4,6,uvalue3,(void *)0x11,value2 + 0x975);
    arg1 = arg1 + -1;
    *(uint32_t *)((intptr_t)pvVar4 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)pvVar4 + 0x50) = 0;
  }
  return;
}
