// Person_UpdateSocialEncounter: ported from Pizza Connection 2 at 0x50df30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50df30
#include "pc2_port.h"

void __thiscall Person_UpdateSocialEncounter(void *self,int arg1)

{
  bool flag1;
  bool flag2;
  uint8_t uvalue3;
  void *this_00;
  int value4;
  int value5;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  float fVar6;
  int value7;
  uint32_t uvalue8;
  bool flag9;
  uint32_t local_4;
  
                    /* Advances a social encounter between two people. */
  if ((*(int *)((intptr_t)self + 0x30) != 0xd) && (*(int *)((intptr_t)self + 0x110) == -1)) {
    return;
  }
  switch(*(int *)((intptr_t)self + 0x30)) {
  default:
    value7 = arg1;
    break;
  case 0x1d:
  case 0x1e:
  case 0xd:
  case 0x17:
    value7 = *(int *)((intptr_t)self + 0x8c);
  }
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value7,(int *)0x0);
  if ((((this_00 == (void *)0x0) || (value4 = State_Is2DOr2E((intptr_t)this_00), value4 != 0)) ||
      (*(int *)((intptr_t)this_00 + 0x74) == 0)) ||
     ((*(int *)((intptr_t)this_00 + 0x30) != 0xd && (*(int *)((intptr_t)this_00 + 0x110) == -1)))) {
LAB_0050e1c8:
    Object_SetState(self,0x2f);
    return;
  }
  value5 = Object_IsWithinServiceRange(self,arg1,value7);
  flag9 = *(short *)(*(int *)((intptr_t)self + 200) + 0x28) != -1;
  value4 = *(int *)((intptr_t)self + 0x108);
  uvalue3 = Object_IsVisibleThisFrame((intptr_t)self);
  if ((CONCAT31(extraout_var,uvalue3) == 0) || (flag9)) {
    flag2 = false;
  }
  else {
    flag2 = true;
  }
  flag1 = flag2;
  if ((*(int *)((intptr_t)self + 0x108) == 4) || (flag1 = flag9, *(int *)((intptr_t)self + 0x108) == 5)) {
    if (flag1) {
      return;
    }
  }
  else {
    if (value4 != 3) {
      if (value5 == 0) {
        value7 = Person_FindFreeNeighborCell(self,arg1,value7,&local_4);
        *(uint32_t *)((intptr_t)self + 0x88) = local_4;
        Person_AdvanceRoute(self,value7);
        return;
      }
      if (flag9) {
        Person_TruncatePathToCurrentStep((intptr_t)self);
        return;
      }
      if (flag2) {
        UI_DetachChildRecord((intptr_t)self);
      }
      Object_BeginServiceDecision(self,(float)(intptr_t)(this_00));
      return;
    }
    if (flag2) {
      return;
    }
    flag9 = AI_TestActionChance(self,(intptr_t)this_00,0);
    if (CONCAT31(extraout_var_00,flag9) != 0) {
      *(uint32_t *)((intptr_t)this_00 + 0x108) = 4;
      fVar6 = Object_ComputeInteractionCell(this_00,(float)(intptr_t)(self));
      UI_DetachChildRecord((intptr_t)this_00);
      UI_SetChildRecordVariant(this_00,(intptr_t)fVar6);
      UI_UpdateValueBar(this_00,self,0);
      if (0 < *(int *)((intptr_t)this_00 + 0xa8)) {
        if (*(int *)((intptr_t)this_00 + 0x38) == 7) {
          Object_SetState(this_00,0x2c);
        }
        *(uint32_t *)((intptr_t)self + 0x108) = 0xffffffff;
        if (*(int *)((intptr_t)self + 0x30) == 0x1e) {
          return;
        }
        AI_WanderToRandomRoadTile(self);
        return;
      }
      value7 = State_Is2DOr2E((intptr_t)this_00);
      if (value7 == 0) {
        uvalue8 = UI_HitTestChildPoint(self,(float)(intptr_t)(this_00));
        *(uint32_t *)((intptr_t)self + 0x88) = uvalue8;
        Object_SetState(self,0x2f);
        Character_OnArriveAtDestination(this_00,(float)(intptr_t)(self),0);
        return;
      }
      goto LAB_0050e1c8;
    }
    if (*(int *)((intptr_t)self + 0x30) != 0x1e) {
      uvalue8 = Random_RangeFast(1,100);
      if ((intptr_t)uvalue8 < 0x32) {
        Object_BeginServiceDecision(self,(float)(intptr_t)(this_00));
        return;
      }
      *(uint32_t *)((intptr_t)self + 0x108) = 0xffffffff;
      AI_WanderToRandomRoadTile(self);
      return;
    }
  }
  *(uint32_t *)((intptr_t)self + 0x108) = 0xffffffff;
  return;
}
