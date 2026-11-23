// Game_RebuildObjectTypeLists: ported from Pizza Connection 2 at 0x495500.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x495500
#include "pc2_port.h"

void Game_RebuildObjectTypeLists(void)

{
  void *self;
  uint32_t uvalue1;
  int value2;
  
  value2 = 0;
  do {
    if (*(int *)((intptr_t)&DAT_0057c6e0 + value2) != 0) {
      List_Node_Reset(*(int *)((intptr_t)&DAT_0057c6e0 + value2));
      if (*(uint32_t **)((intptr_t)&DAT_0057c6e0 + value2) != (uint32_t *)0x0) {
        (**(code **)**(uint32_t **)((intptr_t)&DAT_0057c6e0 + value2))(1);
      }
    }
    self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
    uvalue1 = Game_CollectObjectsByType(self,*(uint32_t *)((intptr_t)&DAT_00568760 + value2));
    *(uint32_t *)((intptr_t)&DAT_0057c6e0 + value2) = uvalue1;
    value2 = value2 + 4;
  } while (value2 < 0x10);
  return;
}
