// Branch_UpgradeSize: ported from Pizza Connection 2 at 0x47f780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f780
#include "pc2_port.h"


void __fastcall Branch_UpgradeSize(void *arg1)

{
  int *ptr1;
  void *pvVar2;
  char *cptr3;
  char *self;
  int value4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Upgrades a branch to its next size. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005580a6;
  local_c = ExceptionList;
  if (*(int *)((intptr_t)arg1 + 0x38) == 2) {
    return;
  }
  ExceptionList = &local_c;
  Branch_ClearInteriorObjects(arg1,0);
  Branch_ClearConstructionSites(arg1);
  self = *(char **)((intptr_t)arg1 + 0x1514);
  value4 = 0;
  if (0 < (intptr_t)self) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value4,(int *)0x0);
      pvVar2 = (void *)Game_GetRecordByField814(*ptr1);
      if ((*(char *)(*ptr1 + 0x824) == '\x03') && (*(int *)((intptr_t)pvVar2 + 0xa4) == 4)) {
        Object_SetFieldA4Locked(pvVar2,0xffffffff);
        Object_SetDestinationAndTarget(pvVar2,3,*(int *)((intptr_t)pvVar2 + 0xcc));
        Object_SetChildField2C(pvVar2,0);
      }
      value4 = value4 + 1;
    } while (value4 < (intptr_t)self);
  }
  *(uint8_t *)((intptr_t)arg1 + 0x16f5) = 1;
  if (*(int *)((intptr_t)DAT_0057c670 + 0x2fc) == *(int *)((intptr_t)arg1 + 0x14e0)) {
    Game_SetLockedField2FC(DAT_0057c670,0);
    if (*(int *)((intptr_t)arg1 + 0x38) == 0) {
      cptr3 = s_BAUHINTERGRUND_MITTEL_tga_00567cdc;
    }
    else if (*(int *)((intptr_t)arg1 + 0x38) == 1) {
      cptr3 = s_BAUHINTERGRUND_GROSS_tga_00567cf8;
    }
    else {
      cptr3 = self;
    }
    Game_LoadBackgroundImage(DAT_0057c670,cptr3);
  }
  Array_ClearStride34((intptr_t)arg1);
  if (*(int *)((intptr_t)arg1 + 0x38) == 0) {
    pvVar2 = operator_new(0x10178);
    local_4 = 0;
    if (pvVar2 != (void *)0x0) {
      self = (char *)IsoMap_Construct(pvVar2,(intptr_t)DAT_0057c5cc);
      local_4 = 0xffffffff;
      goto LAB_0047f909;
    }
  }
  else {
    if (*(int *)((intptr_t)arg1 + 0x38) != 1) goto LAB_0047f909;
    pvVar2 = operator_new(0x10178);
    local_4 = 1;
    if (pvVar2 != (void *)0x0) {
      self = (char *)IsoMap_Construct(pvVar2,(intptr_t)DAT_0057c5cc);
      local_4 = 0xffffffff;
      goto LAB_0047f909;
    }
  }
  local_4 = 0xffffffff;
  self = (char *)0x0;
LAB_0047f909:
  value4 = Object_GetBufferCount(self,(uint32_t *)0x1);
  if (value4 == 0) {
    Grid_RebuildStreetNodes(self,(intptr_t)arg1);
  }
  Game_RegisterWorldObject(DAT_0057c5cc,self,-1);
  Game_AcquireStateLock(DAT_0057c670,0);
  *(int *)((intptr_t)arg1 + 0x38) = *(int *)((intptr_t)arg1 + 0x38) + 1;
  IDMap_RemoveByKey((void *)((intptr_t)DAT_0057c5cc + 0x2c3f8),*(int *)((intptr_t)arg1 + 0x14e0));
  if (*(uint32_t **)((intptr_t)arg1 + 0x14e0) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)((intptr_t)arg1 + 0x14e0))(1);
  }
  *(char **)((intptr_t)arg1 + 0x14e0) = self;
  if (((*(int *)((intptr_t)DAT_0057c670 + 0x290) == 4) && (*(int *)((intptr_t)DAT_0057c670 + 0x2fc) == 0)) &&
     (*(void **)((intptr_t)DAT_0057c670 + 0x9c) == arg1)) {
    Game_SetLockedField2FC(DAT_0057c670,self);
  }
  Game_GetSizeName(arg1,4);
  Branch_ApplyBuildingStyleVariant(arg1,4);
  Game_SetHQLevel(*(void **)(*(int *)((intptr_t)arg1 + 0x16f0) + 0x74),
                  *(uint32_t *)((intptr_t)arg1 + 0x38));
  Window_UnlockState((intptr_t)DAT_0057c670);
  Map_CollectType351ToList((intptr_t)arg1);
  pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x34),
                                (int *)0x0);
  MapObject_SpawnByKind
            (pvVar2,*(void **)((intptr_t)arg1 + 0x16f0),1,*(int *)((intptr_t)arg1 + 0x30),
             (void *)0xffffffff,-1);
  Game_ClearObjectFlag20((intptr_t)arg1);
  Game_ToggleObjectFlag2(arg1);
  Game_UpdateObjectList2((intptr_t)arg1);
  Game_CheckObjectUpgrade(arg1);
  Stats_ResetAverages(arg1);
  *(uint32_t *)(*(int *)((intptr_t)arg1 + 0x14e0) + 0xf4) = 1;
  ExceptionList = local_c;
  return;
}
