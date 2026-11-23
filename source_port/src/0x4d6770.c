// City_PickObjectAtScreenPoint: ported from Pizza Connection 2 at 0x4d6770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6770
#include "pc2_port.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * __thiscall City_PickObjectAtScreenPoint(void *self,int arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  char *cptr3;
  int *ptr4;
  bool flag5;
  void *pvVar6;
  uint32_t *uptr7;
  uint32_t extraout_var;
  int value8;
  uint32_t extraout_var_00;
  LPVOID pvVar9;
  int value10;
  int value11;
  int value12;
  int local_54;
  uint32_t *local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_34;
  int local_30;
  uint32_t local_2c;
  uint32_t local_28;
  uint32_t local_24;
  uint32_t local_20;
  uint32_t local_14;
  uint32_t local_10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055905b;
  pvStack_c = ExceptionList;
  local_48 = -1;
  local_54 = -1;
  _DAT_0057dfb0 = _DAT_0057dfb0 & 0xffffff00;
  _DAT_0057dfb4 = 0;
  ExceptionList = &pvStack_c;
  pvVar6 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar6 == (void *)0x0) {
    local_50 = (uint32_t *)0x0;
  }
  else {
    local_50 = List_Construct(pvVar6,0);
  }
  local_4 = 0xffffffff;
  Map_CollectCompanyObjectsAtPoint(self,local_50,arg1,arg2);
  Map_PickObjectsAtPoint(self,local_50,arg1,arg2);
  local_4c = 0;
  if (0 < (intptr_t)local_50[5]) {
    do {
      uptr7 = (uint32_t *)IDMap_Lookup(local_50,local_4c,(int *)0x0);
      if ((char)*uptr7 == '\x01') {
        CS_Enter(*(int *)(DAT_0057c670 + 0x244));
        ptr4 = *(int **)(uptr7[1] + 200);
        if (ptr4 != (int *)0x0) {
          Sprite_GetPointPair((void *)ptr4[0x16],*ptr4,&local_30,&local_34);
          value11 = Map_ComputeBlitRect(*(void **)((intptr_t)self + 0xfa8),local_30 + 0xa0,local_34 + 0xd0
                                       ,(int *)0x1,0);
          if (local_48 < **(int **)(value11 + 8)) {
            local_24 = *uptr7;
            local_20 = uptr7[1];
            local_48 = **(int **)(value11 + 8);
          }
        }
        CS_Leave(*(int *)(DAT_0057c670 + 0x244));
      }
      else if ((char)*uptr7 == '\x02') {
        CS_Enter(*(int *)(DAT_0057c670 + 0x248));
        uvalue2 = uptr7[1];
        local_14 = *(uint32_t *)(uvalue2 + 0x18);
        local_10 = *(uint32_t *)(uvalue2 + 0x1c);
        value11 = ((arg1 << ((uint8_t)DAT_00580a50 & 0x1f)) +
                 *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x24)) - *(int *)(uvalue2 + 0x10);
        value12 = ((arg2 << ((uint8_t)DAT_00580a50 & 0x1f)) +
                 *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x28)) - *(int *)(uvalue2 + 0x14);
        pvVar6 = (void *)SparseMap_Lookup48(DAT_0057c5cc,*(int *)(uvalue2 + 0x20));
        if (pvVar6 != (void *)0x0) {
          if (*(char *)((intptr_t)pvVar6 + 0x39) == '\0') {
            Sprite_RealizeLazy(pvVar6);
          }
          flag5 = Sprite_BlitClipped(pvVar6,*(uint16_t **)((intptr_t)pvVar6 + 0x2c),value11,value12,
                                     (uint32_t *)0x0);
          if ((CONCAT31(extraout_var,flag5) != 0) && (local_54 < *(int *)(uvalue2 + 0x24))) {
            local_2c = *uptr7;
            local_28 = uptr7[1];
            local_54 = *(int *)(uvalue2 + 0x24);
          }
        }
        value10 = 0;
        local_40 = 0;
        value1 = *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x4c) + *(int *)(uvalue2 + 0x24) * 0xc;
        value8 = *(int *)(value1 + 8);
        if (0 < *(int *)(value8 + 0x14)) {
          do {
            cptr3 = *(char **)(*(int *)(value8 + 0x18) + 8 + value10);
            if (*cptr3 != '\x02') {
              flag5 = RecordList_BlitRecordSprite
                                (*(void **)(cptr3 + 0x48),*(int *)(*(int *)(value8 + 0x18) + value10)
                                 ,value11,value12);
              if (CONCAT31(extraout_var_00,flag5) != 0) {
                local_54 = *(int *)(uvalue2 + 0x24);
                local_2c = *uptr7;
                local_28 = uptr7[1];
              }
            }
            local_40 = local_40 + 1;
            value10 = value10 + 0xc;
            value8 = *(int *)(value1 + 8);
          } while (local_40 < *(int *)(value8 + 0x14));
        }
        CS_Leave(*(int *)(DAT_0057c670 + 0x248));
      }
      local_4c = local_4c + 1;
    } while (local_4c < (intptr_t)local_50[5]);
  }
  value11 = 0;
  if (0 < (intptr_t)local_50[5]) {
    do {
      pvVar9 = (LPVOID)IDMap_Lookup(local_50,value11,(int *)0x0);
      Mem_Free(pvVar9);
      value11 = value11 + 1;
    } while (value11 < (intptr_t)local_50[5]);
  }
  if (local_50 != (uint32_t *)0x0) {
    (**(code **)*local_50)(1);
  }
  if (local_48 == -1) {
    if (local_54 != -1) {
      _DAT_0057dfb0 = local_2c;
      _DAT_0057dfb4 = local_28;
    }
  }
  else {
    _DAT_0057dfb0 = local_24;
    _DAT_0057dfb4 = local_20;
  }
  ExceptionList = pvStack_c;
  return &DAT_0057dfb0;
}
