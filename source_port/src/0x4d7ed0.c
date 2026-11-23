// City_CollectBranchesNearPoint: ported from Pizza Connection 2 at 0x4d7ed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d7ed0
#include "pc2_port.h"


uint32_t * __thiscall
City_CollectBranchesNearPoint(void *self,int arg1,int arg2,int arg3)

{
  void *this_00;
  void *pvVar1;
  uint32_t *this_01;
  int value2;
  int value3;
  int value4;
  void *this_02;
  int value5;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005590eb;
  local_c = ExceptionList;
  this_00 = *(void **)((intptr_t)self + 0xfa8);
  ExceptionList = &local_c;
  local_10 = self;
  pvVar1 = operator_new(0x1c);
  value5 = 0;
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    this_01 = (uint32_t *)0x0;
  }
  else {
    this_01 = List_Construct(pvVar1,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)((intptr_t)self + 0xfc0) < 1) {
    ExceptionList = local_c;
    return this_01;
  }
  do {
    value2 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value5,(int *)0x0);
    if ((((*(int *)(value2 + 4) == 0xf) || (*(int *)(value2 + 4) == 0x1b)) &&
        (*(int *)(value2 + 0x74) != 0)) &&
       (value3 = Game_GetAdjustedValue(*(int *)(value2 + 0x74)), value3 != -1)) {
      UI_GetRecordCenteredRect(this_00,*(int *)(value2 + 0x24),&local_18,&local_14);
      if (*(int *)(value2 + 0x74) == 0) {
        value3 = -1;
      }
      else {
        value3 = Game_GetAdjustedValue(*(int *)(value2 + 0x74));
      }
      if (*(int *)(value2 + 0x74) == 0) {
        value4 = -1;
      }
      else {
        value4 = Game_GetAdjustedValue(*(int *)(value2 + 0x74));
      }
      if ((local_18 - arg2) * (local_18 - arg2) +
          (local_14 - arg3) * (local_14 - arg3) * 4 < value4 * value3 * 4) {
        if (*(int *)(value2 + 4) == 0x1b) {
          pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value2 + 8));
          this_02 = (void *)Game_FindPlanByTarget(pvVar1,value2);
          if ((*(int *)((intptr_t)this_02 + 4) == 0) ||
             (value2 = GamePlan_ComputeCategoryEffect(this_02,*(int *)((intptr_t)pvVar1 + 0x48),arg1),
             value2 < 0x33)) goto LAB_004d804f;
          value2 = IDMap_Lookup((void *)((intptr_t)pvVar1 + 0x148),*(int *)((intptr_t)this_02 + 0xc),(int *)0x0
                              );
          value2 = *(int *)(value2 + 0x16f0);
        }
        value3 = Map_LookupLinear(this_01,value2);
        if (value3 == -1) {
          List_Add(this_01,value2);
        }
      }
    }
LAB_004d804f:
    value5 = value5 + 1;
    self = local_10;
    if (*(int *)((intptr_t)local_10 + 0xfc0) <= value5) {
      ExceptionList = local_c;
      return this_01;
    }
  } while( true );
}
