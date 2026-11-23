// Company_RemoveAttachedBuildingObjects: ported from Pizza Connection 2 at 0x47f670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f670
#include "pc2_port.h"

int __fastcall Company_RemoveAttachedBuildingObjects(void *arg1)

{
  void *self;
  int value1;
  void *pvVar2;
  void *this_00;
  int value3;
  
                    /* Removes a company building's attached objects. */
  value3 = 0;
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  self = *(void **)((intptr_t)arg1 + 0x16f0);
  if (self == (void *)0x0) {
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
    return 0;
  }
  value1 = *(int *)((intptr_t)self + 0x8c);
  while (value1 = value1 + -1, -1 < value1) {
    pvVar2 = (void *)Game_MapRecordToGlobal(self,value1);
    if ((0x2a < *(int *)((intptr_t)pvVar2 + 0x30)) && (*(int *)((intptr_t)pvVar2 + 0x30) < 0x2d)) {
      this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*(int *)((intptr_t)pvVar2 + 0x10c),
                                     (int *)0x0);
      if ((this_00 != (void *)0x0) &&
         ((*(int *)((intptr_t)this_00 + 0x74) != 0 &&
          (*(int *)((intptr_t)this_00 + 0xf4) == *(int *)((intptr_t)arg1 + 0x16f0))))) {
        value3 = Person_CanContinuePath((intptr_t)this_00);
        if (value3 == 0) {
          UI_DetachChildRecord((intptr_t)this_00);
        }
        else {
          Person_TruncatePathToCurrentStep((intptr_t)this_00);
        }
        Object_SetState(this_00,6);
        Object_SetFieldA4Locked(this_00,0xffffffff);
      }
      Branch_RemoveBuildingObject(arg1,pvVar2);
      value3 = 1;
    }
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  if (value3 != 0) {
    *(uint32_t *)((intptr_t)arg1 + 0x1718) = 0;
  }
  return value3;
}
