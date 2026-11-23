// Game_ValidateObjectPlacement: ported from Pizza Connection 2 at 0x489180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489180
#include "pc2_port.h"

uint32_t __thiscall
Game_ValidateObjectPlacement
          (void *self,int arg1,int arg2,int arg3,int arg4,int arg5,int arg6)

{
  void *this_00;
  bool flag1;
  int value2;
  void *this_01;
  uint32_t *this_02;
  uint32_t extraout_var;
  int value3;
  
                    /* Validates a building placement at a screen point or cell. */
  if (*(int *)((intptr_t)self + 0x344) == -1) {
    return 0;
  }
  this_00 = *(void **)((intptr_t)self + 0x2fc);
  if (arg4 == 0) {
    if (((arg1 < 0) || (DAT_00571950 + -0x1e < arg1)) ||
       ((arg2 < 0 || (DAT_00571954 < arg2)))) {
LAB_00489222:
      *(uint32_t *)((intptr_t)self + 0x358) = 0;
      return 0;
    }
    value2 = Map_ComputeBlitRect(this_00,arg1,arg2,(int *)0x0,0);
    arg4 = **(int **)(value2 + 8) % *(int *)((intptr_t)this_00 + 0x1c);
    arg2 = **(int **)(value2 + 8) / *(int *)((intptr_t)this_00 + 0x1c);
  }
  else {
    if (((arg5 != -1) && (arg6 != -1)) &&
       ((arg5 < 0 ||
        (((DAT_00571950 + -0x1e < arg5 || (arg6 < 0)) || (DAT_00571954 < arg6))))))
    goto LAB_00489222;
    arg4 = arg1;
    value2 = Grid_GetCell(this_00,arg1,arg2);
    if (value2 == 0) {
      return 0;
    }
    if (*(int *)(value2 + 8) == 0) {
      return 0;
    }
  }
  *(uint32_t *)((intptr_t)self + 0x358) = 1;
  this_01 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x74),*(int *)((intptr_t)self + 0x344),(int *)0x0);
  Object_GetPair68(this_01,&arg6,&arg5);
  this_02 = Grid_CollectFootprintCellsAtCell(this_00,(intptr_t)this_01,arg4,arg2);
  arg1 = 0;
  if (0 < (intptr_t)this_02[5]) {
    do {
      value2 = IDMap_Lookup(this_02,arg1,(int *)0x0);
      if (*(int *)((intptr_t)this_01 + 8) == 5) {
        flag1 = IsMenuId352(*(int *)(*(int *)(value2 + 8) + 4));
        if (CONCAT31(extraout_var,flag1) == 0) goto LAB_0048933a;
      }
      else {
        value3 = IsMenuId34EOr350(*(int *)(*(int *)(value2 + 8) + 4));
        if (value3 == 0) goto LAB_00489368;
      }
      if (*(int *)(*(int *)(value2 + 8) + 4) < 0) goto LAB_0048933a;
      if (*(int *)(*(int *)(value2 + 8) + 0x10) != -1) goto LAB_00489368;
      arg1 = arg1 + 1;
    } while (arg1 < (intptr_t)this_02[5]);
  }
  if (this_02 != (uint32_t *)0x0) {
    (**(code **)*this_02)(1);
  }
  this_02 = Grid_CollectFootprintCellsAtCell(this_00,(intptr_t)this_01,arg4,arg2);
  value2 = MapCell_CheckSpriteOverlap(self,this_02);
  if (value2 == 0) {
    if ((arg3 == 0) || (value2 = Game_AnyBuildingReachesCellList(self,this_02), value2 == 0)) {
      if (this_02 != (uint32_t *)0x0) {
        (**(code **)*this_02)(1);
      }
      return 1;
    }
LAB_00489368:
    if (this_02 != (uint32_t *)0x0) {
      (**(code **)*this_02)(1);
      return 0;
    }
  }
  else {
LAB_0048933a:
    if (this_02 != (uint32_t *)0x0) {
      (**(code **)*this_02)(1);
      return 0;
    }
  }
  return 0;
}
