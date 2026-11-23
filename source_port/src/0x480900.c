// Branch_SpawnRandomPedestrian: ported from Pizza Connection 2 at 0x480900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480900
#include "pc2_port.h"


void __fastcall Branch_SpawnRandomPedestrian(int arg1)

{
  bool flag1;
  uint32_t extraout_var;
  int value2;
  int value3;
  uint32_t uvalue4;
  void *pvVar5;
  char *self;
  int *ptr6;
  uint32_t local_28 [5];
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005580b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  local_4 = 0;
  flag1 = City_IsIdle(arg1);
  if ((CONCAT31(extraout_var,flag1) == 0) && (*(char *)(arg1 + 0x16f5) == '\0')) {
    value2 = Game_CountFreeBuildingsByType(*(void **)(arg1 + 0x16f0),0x1b);
    if (value2 < 0x1e) {
      pvVar5 = *(void **)(arg1 + 0x16f0);
      value2 = 0;
      if (0 < *(int *)((intptr_t)pvVar5 + 0x8c)) {
        do {
          value3 = Game_MapRecordToGlobal(pvVar5,value2);
          if ((*(int *)(value3 + 0x30) == 0x1b) && (*(int *)(value3 + 0x38) != 0x1f)) {
            List_Add(local_28,value3);
          }
          pvVar5 = *(void **)(arg1 + 0x16f0);
          value2 = value2 + 1;
        } while (value2 < *(int *)((intptr_t)pvVar5 + 0x8c));
      }
      if (0 < local_14) {
        ptr6 = (int *)0x0;
        uvalue4 = Random_RangeFast(0,local_14 - 1);
        value2 = IDMap_Lookup(local_28,uvalue4,ptr6);
        pvVar5 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                      (int *)0x0);
        self = City_CreateBranchObject(pvVar5,0x1b,arg1);
        if (*(int *)(value2 + 200) == 0) {
          value2 = 0;
        }
        else {
          value2 = *(int *)(*(int *)(value2 + 200) + 0x20);
        }
        UI_SetChildTracking(self,1,value2);
        Object_SetState(self,0x18);
        if (*(void **)(arg1 + 0x16f0) != (void *)0x0) {
          value2 = Game_CountFreeBuildingsByType(*(void **)(arg1 + 0x16f0),0x20);
          if (0 < value2) {
            UI_SetChildHeightFromValue((intptr_t)self);
          }
        }
      }
      local_4 = 0xffffffff;
      List_Node_Destroy(local_28);
      ExceptionList = local_c;
      return;
    }
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return;
}
