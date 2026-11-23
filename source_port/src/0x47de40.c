// Game_PickTopmostObjectAtPoint: ported from Pizza Connection 2 at 0x47de40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47de40
#include "pc2_port.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * __thiscall Game_PickTopmostObjectAtPoint(void *self,int arg1,int arg2)

{
  int *ptr1;
  bool flag2;
  uint32_t *uptr3;
  void *this_00;
  uint32_t extraout_var;
  LPVOID pvVar4;
  int value5;
  int value6;
  int local_38;
  uint32_t *local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint32_t local_24;
  uint32_t *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557fcb;
  local_c = ExceptionList;
  local_38 = -1;
  _DAT_0057c618 = _DAT_0057c618 & 0xffffff00;
  _DAT_0057c61c = 0;
  ExceptionList = &local_c;
  local_20 = operator_new(0x1c);
  local_4 = 0;
  if (local_20 == (uint32_t *)0x0) {
    local_34 = (uint32_t *)0x0;
  }
  else {
    local_34 = List_Construct(local_20,0);
  }
  local_4 = 0xffffffff;
  Game_CollectObjectsAtPoint(self,local_34,arg1,arg2);
  Game_CollectBuildingHitsAtPoint(self,local_34,arg1,arg2);
  DebugConsole_Printf(DAT_0057c1e0,0x400040,(uint8_t *)s_found__d_00567c5c,local_34[5]);
  local_30 = 0;
  if (0 < (intptr_t)local_34[5]) {
    do {
      uptr3 = (uint32_t *)IDMap_Lookup(local_34,local_30,(int *)0x0);
      local_20 = uptr3;
      if ((char)*uptr3 == '\x01') {
        CS_Enter(*(int *)(DAT_0057c670 + 0x244));
        ptr1 = *(int **)(uptr3[1] + 200);
        if (ptr1 != (int *)0x0) {
          Sprite_GetPointPair((void *)ptr1[0x16],*ptr1,&local_18,&local_1c);
          value5 = Map_ComputeBlitRect(*(void **)((intptr_t)self + 0x14e0),local_18 + 0xa0,local_1c + 0xd0
                                      ,(int *)0x1,0);
          if (local_38 < **(int **)(value5 + 8)) {
            _DAT_0057c618 = *uptr3;
            _DAT_0057c61c = uptr3[1];
            local_38 = **(int **)(value5 + 8);
          }
        }
        CS_Leave(*(int *)(DAT_0057c670 + 0x244));
      }
      else if (((((char)*uptr3 == '\x03') && (local_24 = uptr3[1], local_24 != 0)) &&
               (ptr1 = (int *)(*(int *)(*(int *)((intptr_t)self + 0x14e0) + 0x4c) +
                                *(int *)(local_24 + 0x20) * 0xc), ptr1 != (int *)0x0)) &&
              (this_00 = (void *)SparseMap_Lookup48(DAT_0057c5cc,*(int *)(ptr1[2] + 0x10)),
              this_00 != (void *)0x0)) {
        UI_AlignSpriteToRect(*(void **)((intptr_t)self + 0x14e0),ptr1,this_00,&local_2c,&local_28);
        Sprite_GetHotspot(this_00,&local_10,&local_14);
        value6 = arg1 - local_2c;
        value5 = arg2 - local_28;
        if (*(char *)((intptr_t)this_00 + 0x39) == '\0') {
          Sprite_RealizeLazy(this_00);
        }
        flag2 = Sprite_BlitClipped(this_00,*(uint16_t **)((intptr_t)this_00 + 0x2c),value6,value5,(uint32_t *)0x0
                                  );
        if ((CONCAT31(extraout_var,flag2) != 0) && (local_38 < *(int *)(local_24 + 0x20))) {
          _DAT_0057c618 = *local_20;
          _DAT_0057c61c = local_20[1];
          local_38 = *(int *)(local_24 + 0x20);
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < (intptr_t)local_34[5]);
  }
  value5 = 0;
  if (0 < (intptr_t)local_34[5]) {
    do {
      pvVar4 = (LPVOID)IDMap_Lookup(local_34,value5,(int *)0x0);
      Mem_Free(pvVar4);
      value5 = value5 + 1;
    } while (value5 < (intptr_t)local_34[5]);
  }
  if (local_34 != (uint32_t *)0x0) {
    (**(code **)*local_34)(1);
  }
  ExceptionList = local_c;
  return &DAT_0057c618;
}
