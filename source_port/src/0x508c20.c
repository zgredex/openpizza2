// Object_RebindRenderList: ported from Pizza Connection 2 at 0x508c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508c20
#include "pc2_port.h"

void __thiscall Object_RebindRenderList(void *self,int arg1,uint32_t arg2)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  CS_Enter(*(int *)(DAT_0057c670 + 0x244));
  UI_DestroyChildObject((intptr_t)self);
  if (*(int *)((intptr_t)self + 0x78) != 0) {
    Object_ApplyPendingType(self,*(int *)((intptr_t)self + 0x78));
  }
  if (arg1 == 0) {
    *(uint32_t *)((intptr_t)self + 0xc4) = arg2;
    if (*(int *)((intptr_t)self + 0x30) == 0x10) {
      value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)((intptr_t)self + 0x50),(int *)0x0);
      uvalue3 = (uint32_t)*(uint8_t *)(value1 + 0x824);
    }
    else {
      uvalue3 = 0xffffffff;
    }
    MapObject_InitRenderRecord(self,0,-1,uvalue3);
    value1 = Array_GetRecord28(*(void **)((intptr_t)self + 0xc4),1,
                              *(int *)(*(int *)((intptr_t)self + 0xf4) + 0x54));
    uvalue2 = 0;
  }
  else {
    if (arg1 != 1) goto LAB_00508cfc;
    *(uint32_t *)((intptr_t)self + 0xc4) = arg2;
    MapObject_InitRenderRecord(self,1,-1,-1);
    value1 = Grid_GetRandomRecord28(*(int *)((intptr_t)self + 0xc4));
    uvalue2 = 1;
  }
  UI_SetChildTracking(self,uvalue2,value1);
LAB_00508cfc:
  if (*(int *)((intptr_t)self + 0x78) != 0) {
    Object_ApplyDeferredType(self,*(int *)((intptr_t)self + 0x78));
    *(uint32_t *)((intptr_t)self + 0x78) = 0;
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x244));
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
