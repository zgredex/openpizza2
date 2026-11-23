// Branch_CompleteConstruction: ported from Pizza Connection 2 at 0x486f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486f30
#include "pc2_port.h"

void __thiscall Branch_CompleteConstruction(void *self,uint32_t *arg1)

{
  int value1;
  void *this_00;
  int value2;
  void *this_01;
  void *pvVar3;
  void *this_02;
  int value4;
  uint32_t uvalue5;
  
                    /* Completes branch construction and activates it. */
  value1 = arg1[0xb];
  pvVar3 = (void *)Game_GetPlayerBySlot(self,arg1[0xc]);
  this_02 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),arg1[0xd],(int *)0x0);
  this_00 = (void *)arg1[0x5bc];
  value2 = arg1[0xe];
  value4 = *(int *)((intptr_t)this_00 + 0x48);
  if ((-1 < value4) && (value4 < 4)) {
    value4 = *(int *)(&DAT_00568188 + value4 * 4);
  }
  this_01 = *(void **)((intptr_t)self + 0x25c);
  Game_AcquireStateLock(self,1);
  Branch_ClearInteriorObjects(arg1,(uint32_t)(value1 == 7));
  Branch_ApplyStatsToOwner(arg1);
  Player_RemoveBranch(pvVar3,(intptr_t)arg1);
  Branch_ClearConstructionSites(arg1);
  if (*(uint32_t **)((intptr_t)self + 0x9c) != arg1) goto LAB_00487059;
  if (*(int *)((intptr_t)self + 0x290) == 4) {
    Game_SetLockedField2FC(self,0);
    if (0 < *(int *)((intptr_t)pvVar3 + 0x15c)) {
      uvalue5 = IDMap_Lookup((void *)((intptr_t)pvVar3 + 0x148),0,(int *)0x0);
      *(uint32_t *)((intptr_t)self + 0x9c) = uvalue5;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
      Game_EnterBranchInterior(self,*(int *)((intptr_t)self + 0x9c));
      if (this_01 != (void *)0x0) {
        UI_QueueControlCommand(this_01,-0x1869e,0x23,0);
      }
      goto LAB_00487059;
    }
    Game_SetViewMode(self,1,0);
LAB_00487044:
    *(uint32_t *)((intptr_t)self + 0x9c) = 0;
  }
  else {
    if (*(int *)((intptr_t)pvVar3 + 0x15c) < 1) goto LAB_00487044;
    uvalue5 = IDMap_Lookup((void *)((intptr_t)pvVar3 + 0x148),0,(int *)0x0);
    *(uint32_t *)((intptr_t)self + 0x9c) = uvalue5;
  }
  Sound_SelectCurrentTrack(DAT_0057ba0c);
LAB_00487059:
  if (((*(int *)((intptr_t)self + 0x2d8) == 0x1a) || (*(int *)((intptr_t)self + 0x2d8) == 0x15)) &&
     (*(int *)((intptr_t)self + 0x290) < 4)) {
    Game_DestroyRootWindow((intptr_t)self);
    *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x2b8) =
         *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298);
    *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298) = 1;
    pvVar3 = SubMenu_BuildSelectedPage(self,(int *)0x1);
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar3);
  }
  CS_Enter(*(int *)((intptr_t)self + 0x240));
  if (value1 == 7) {
    *(uint32_t *)((intptr_t)this_00 + 4) = 0x23;
    *(uint32_t *)((intptr_t)this_00 + 0x50) = 0;
    *(uint32_t *)((intptr_t)this_00 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)this_00 + 0xc) = 0x12378d6;
  }
  else {
    MapObject_SetTypeAndSprite(this_00,value2 + 0x14,value4 + 0x84c + value2 * 4);
  }
  *(uint32_t *)((intptr_t)this_00 + 0x74) = 0;
  Game_PlaceObjectInPlayerCity(this_02,this_00,-1);
  *(uint32_t *)((intptr_t)this_00 + 0x2c) = 0xffffffff;
  if (value1 != 7) {
    *(uint32_t *)((intptr_t)this_00 + 0x4c) = 1;
  }
  CS_Leave(*(int *)((intptr_t)self + 0x240));
  Map_DrawMinimap(self);
  Window_UnlockState((intptr_t)self);
  if (arg1 == (uint32_t *)0x0) {
    *(uint32_t *)(*(int *)((intptr_t)this_02 + 0xfa8) + 0xf4) = 1;
    return;
  }
  (**(code **)*arg1)(1);
  *(uint32_t *)(*(int *)((intptr_t)this_02 + 0xfa8) + 0xf4) = 1;
  return;
}
