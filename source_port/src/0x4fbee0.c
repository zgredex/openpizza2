// Map_CommitPendingObjectEdits: ported from Pizza Connection 2 at 0x4fbee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fbee0
#include "pc2_port.h"


void Map_CommitPendingObjectEdits(int *arg1,char arg2)

{
  int value1;
  void *self;
  void *this_00;
  int value2;
  int *ptr3;
  int value4;
  void *this_01;
  int value5;
  int value6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Commits pending map objects, construction sites, and selection state. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a14b;
  local_c = ExceptionList;
  if ((arg1 != (int *)0x0) && (arg1[3] != 0)) {
    value1 = *(int *)(*arg1 + 0x24);
    ExceptionList = &local_c;
    Game_ClearPendingMapObjects(*arg1);
    self = (void *)arg1[3];
    value6 = 0;
    this_00 = *(void **)(*arg1 + 0x14e0);
    value2 = *(int *)((intptr_t)self + 0x14);
    if (0 < value2) {
      do {
        ptr3 = (int *)IDMap_Lookup(self,value6,(int *)0x0);
        if ((arg2 != '\0') || (ptr3[7] != 0)) {
          value4 = Grid_GetCell(this_00,(intptr_t)(short)ptr3[5],(intptr_t)*(short *)((intptr_t)ptr3 + 0x16));
          Map_SetTileFieldWithDefault(this_00,value4,*ptr3,*(uint8_t *)(ptr3 + 6) - 1);
          if ((ptr3[8] != 0) && (ptr3[3] != -1)) {
            IDMap_Lookup((void *)(DAT_0057c670 + 0x74),ptr3[3],(int *)0x0);
            this_01 = operator_new(0x24);
            local_4 = 0;
            if (this_01 == (void *)0x0) {
              value5 = 0;
            }
            else {
              value5 = ConstructionOrder_Construct(this_01,ptr3[3],ptr3[4]);
            }
            *(int *)(value5 + 0x18) = (intptr_t)(short)ptr3[5];
            *(int *)(value5 + 0x1c) = (intptr_t)*(short *)((intptr_t)ptr3 + 0x16);
            local_4 = 0xffffffff;
            *(uint32_t *)(value5 + 0x20) = **(uint32_t **)(value4 + 8);
            List_Add((void *)(*arg1 + 0x16f8),value5);
          }
        }
        Mem_Free(ptr3);
        value6 = value6 + 1;
      } while (value6 < value2);
    }
    List_Node_Reset((intptr_t)self);
    if (arg1[7] == 0) {
      *(int *)(*arg1 + 0x19fc) = value1;
      *(int *)(*arg1 + 0x1a04) = value1;
      *(int *)(*arg1 + 0x1a00) = arg1[9];
      Game_GetSizeName((void *)*arg1,value1);
      Branch_ApplyBuildingStyleVariant((void *)*arg1,*(int *)(*arg1 + 0x1a04));
    }
    Map_BuildTerrainGrid((intptr_t)arg1);
    IDMap_FreeValuesAndDestroy((uint32_t *)arg1[3]);
    arg1[3] = 0;
    *(uint32_t *)(*arg1 + 0x1718) = 0;
  }
  ExceptionList = local_c;
  return;
}
