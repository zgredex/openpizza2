// Object_UpdateWalkStep: ported from Pizza Connection 2 at 0x4f21e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f21e0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateWalkStep(void *self,uint32_t *arg1,uint32_t arg2)

{
  uint32_t *this_00;
  uint32_t *uptr1;
  bool flag2;
  int value3;
  uint32_t extraout_var;
  uint32_t uvalue4;
  int value5;
  uint32_t uvalue6;
  int64_t lvalue7;
  int64_t lvalue8;
  int local_34;
  int local_30;
  int local_28;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18 [2];
  uint32_t local_10 [3];
  
                    /* Advances one walking sprite element and its directional variant. */
  _DAT_00580a58 = 1;
  if ((short)arg1[10] == -1) {
    RecordList_TickFrameAndGetPoints((void *)arg1[0x16],*arg1,local_10,local_18);
    _DAT_00580a58 = 0;
    return;
  }
  if ((arg1[0x10] != 0xffffffff) &&
     (value3 = MapActor_UpdateLinkedOverlays(self,(int *)arg1), value3 != 0)) {
    _DAT_00580a58 = 0;
    return;
  }
  uvalue6 = local_20;
LAB_004f2245:
  do {
    uvalue4 = *arg1;
    local_20 = 0;
    if (((-1 < (intptr_t)uvalue4) && ((intptr_t)uvalue4 < *(int *)(arg1[0x16] + 0x48))) &&
       (*(char *)(*(int *)(arg1[0x16] + 0x4c) + 0x3e + uvalue4 * 0x48) != '\0')) {
      Record_TryAdvanceFrame((void *)arg1[0x16],uvalue4,arg2,local_10,local_18,&local_1c);
      lvalue7 = __ftol();
      lvalue8 = __ftol();
      flag2 = Object_TryNeighborPlacement(self,(int *)arg1,(intptr_t)lvalue7,(intptr_t)lvalue8);
      if (CONCAT31(extraout_var,flag2) != 0) {
        uvalue6 = Enum_MapDirection((intptr_t)arg1);
        arg1[0x10] = uvalue6;
        Object_UpdateState(self,(intptr_t)arg1);
        Record_ClearFlags48((void *)arg1[0x16],*arg1);
        _DAT_00580a58 = 0;
        return;
      }
      RecordList_TickFrameAtTimeAndGetPoints
                ((void *)arg1[0x16],*arg1,arg2,local_10,local_18,&local_20);
      Object_MoveToMapCell(self,(int *)arg1,(intptr_t)lvalue7,(intptr_t)lvalue8);
      if (local_20 == 0) {
        _DAT_00580a58 = 0;
        return;
      }
      Object_SetShort28(arg1,(short)arg1[10] + 1);
      arg1[9] = arg1[8];
      uvalue4 = Array_GetPtr4(arg1 + 5,(intptr_t)(short)arg1[10]);
      arg1[8] = uvalue4;
      value3 = Array_GetPtr4(arg1 + 5,(short)arg1[10] + 1);
      if (value3 == 0) {
        Object_UpdateState(self,(intptr_t)arg1);
        Record_ClearFlags48((void *)arg1[0x16],*arg1);
LAB_004f2693:
        arg1[3] = 0;
        Object_SetShort28(arg1,0xffff);
        _DAT_00580a58 = 0;
        return;
      }
    }
    this_00 = arg1 + 5;
    value3 = Array_GetPtr4(this_00,(intptr_t)(short)arg1[10]);
    if (value3 == 0) {
      _DAT_00580a58 = 0;
      return;
    }
    local_28 = *(int *)(value3 + 0xc);
    local_34 = *(int *)(value3 + 0x10);
    value3 = Array_GetPtr4(this_00,(short)arg1[10] + 1);
    if (value3 == 0) {
      _DAT_00580a58 = 0;
      return;
    }
    local_30 = *(int *)(value3 + 0xc);
    value3 = *(int *)(value3 + 0x10);
    value5 = Array_GetPtr4(this_00,(intptr_t)(short)arg1[10]);
    if ((*(char *)(value5 + 6) == '\x02') &&
       (value5 = Array_GetPtr4(this_00,(short)arg1[10] + 1), *(char *)(value5 + 6) == '\x02')) {
      Object_UpdateState(self,(intptr_t)arg1);
      Record_ClearFlags48((void *)arg1[0x16],*arg1);
      Object_SetShort28(arg1,(short)arg1[10] + 1);
      uvalue4 = Array_GetPtr4(this_00,(intptr_t)(short)arg1[10]);
      arg1[9] = uvalue4;
      uvalue4 = Array_GetPtr4(this_00,(intptr_t)(short)arg1[10]);
      arg1[8] = uvalue4;
      Record_SetDoubles48((void *)arg1[0x16],*arg1,local_30 - *(int *)((intptr_t)self + 0xf8),
                          value3 - *(int *)((intptr_t)self + 0xfc));
      value3 = Array_GetPtr4(this_00,(intptr_t)(short)arg1[10]);
      local_28 = *(int *)(value3 + 0xc);
      value3 = Array_GetPtr4(this_00,(intptr_t)(short)arg1[10]);
      local_34 = *(int *)(value3 + 0x10);
      uptr1 = arg1 + 0x17;
      *uptr1 = *uptr1 - *(int *)((intptr_t)self + 0x24);
      arg1[0x19] = arg1[0x19] - *(int *)((intptr_t)self + 0x24);
      arg1[0x18] = arg1[0x18] - *(int *)((intptr_t)self + 0x28);
      arg1[0x1a] = arg1[0x1a] - *(int *)((intptr_t)self + 0x28);
      Gfx_BlitRectList(DAT_0058072c,uptr1);
      value3 = Array_GetPtr4(this_00,(short)arg1[10] + 1);
      if (value3 == 0) goto LAB_004f2693;
      value3 = Array_GetPtr4(this_00,(short)arg1[10] + 1);
      local_30 = *(int *)(value3 + 0xc);
      value3 = Array_GetPtr4(this_00,(short)arg1[10] + 1);
      value3 = *(int *)(value3 + 0x10);
    }
    if (arg1[1] != 0xffffffff) {
      local_28 = local_28 - *(int *)((intptr_t)self + 0xf8);
      value3 = value3 - *(int *)((intptr_t)self + 0xfc);
      local_34 = local_34 - *(int *)((intptr_t)self + 0xfc);
      local_30 = local_30 - *(int *)((intptr_t)self + 0xf8);
      Record_SetDoubles48B(arg1[0x16],*arg1,(double)local_30,(double)value3);
      if (local_30 < local_28) {
LAB_004f2610:
        uvalue6 = arg1[0xb];
        if (value3 < local_34) {
          uvalue6 = uvalue6 + 6;
          arg1[3] = uvalue6;
          Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
          goto LAB_004f2245;
        }
        if (value3 <= local_34) {
          uvalue6 = uvalue6 + 7;
          arg1[3] = uvalue6;
          Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
          goto LAB_004f2245;
        }
      }
      else {
        if (local_28 < local_30) {
          uvalue6 = arg1[0xb];
          if (value3 < local_34) {
            uvalue6 = uvalue6 + 4;
            arg1[3] = uvalue6;
            Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
          }
          else if (local_34 < value3) {
LAB_004f2555:
            uvalue6 = uvalue6 + 2;
            arg1[3] = uvalue6;
            Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
          }
          else {
LAB_004f256c:
            uvalue6 = uvalue6 + 3;
            arg1[3] = uvalue6;
            Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
          }
          goto LAB_004f2245;
        }
LAB_004f2583:
        if (local_28 == local_30) {
          if (value3 < local_34) {
            uvalue6 = arg1[0xb] + 5;
            arg1[3] = uvalue6;
            Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
            goto LAB_004f2245;
          }
          uvalue6 = arg1[0xb] + 1;
        }
      }
      arg1[3] = uvalue6;
      Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
      goto LAB_004f2245;
    }
    value3 = value3 + -0xd0;
    local_28 = local_28 + -0xa0;
    local_30 = local_30 + -0xa0;
    local_34 = local_34 + -0xd0;
    Record_SetDoubles48B(arg1[0x16],*arg1,(double)local_30,(double)value3);
    if (local_30 < local_28) goto LAB_004f2610;
    if (local_30 <= local_28) goto LAB_004f2583;
    uvalue6 = arg1[0xb];
    if (local_34 <= value3) {
      if (value3 <= local_34) goto LAB_004f256c;
      goto LAB_004f2555;
    }
    uvalue6 = uvalue6 + 4;
    arg1[3] = uvalue6;
    Record_SelectVariant((void *)arg1[0x16],*arg1,uvalue6);
  } while( true );
}
