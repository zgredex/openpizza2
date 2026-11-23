// Object_RebuildVisualAtDestination: ported from Pizza Connection 2 at 0x508d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508d90
#include "pc2_port.h"

void __thiscall Object_RebuildVisualAtDestination(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  
                    /* Rebuilds an object's visual after a deferred type change. */
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  CS_Enter(*(int *)(DAT_0057c670 + 0x244));
  if (*(int *)((intptr_t)self + 200) == 0) {
    value2 = 0;
  }
  else {
    value2 = *(int *)(*(int *)((intptr_t)self + 200) + 0x20);
  }
  UI_SetChildState(self,0xffff);
  Object_ApplyPendingType(self,arg2);
  UI_DestroyChildObject((intptr_t)self);
  if (*(int *)((intptr_t)self + 0x30) == 0x10) {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)((intptr_t)self + 0x50),(int *)0x0);
  }
  else {
    value1 = arg2;
  }
  if (arg1 == 0) {
    if (*(int *)((intptr_t)self + 0x30) == 0x10) {
      uvalue4 = (uint32_t)*(uint8_t *)(value1 + 0x824);
    }
    else {
      uvalue4 = 0xffffffff;
    }
    MapObject_InitRenderRecord(self,0,-1,uvalue4);
    uvalue3 = 0;
  }
  else {
    if (arg1 != 1) goto LAB_00508e68;
    if (*(int *)((intptr_t)self + 0x30) == 0x10) {
      MapObject_InitRenderRecord(self,1,-1,(uint32_t)*(uint8_t *)(value1 + 0x824));
      uvalue3 = 1;
    }
    else {
      MapObject_InitRenderRecord(self,1,-1,-1);
      uvalue3 = 1;
    }
  }
  UI_SetChildTracking(self,uvalue3,value2);
LAB_00508e68:
  Object_ApplyDeferredType(self,arg2);
  Object_SetDestinationAndTarget(self,3,*(int *)((intptr_t)self + 0xcc));
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  CS_Leave(*(int *)(DAT_0057c670 + 0x244));
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
