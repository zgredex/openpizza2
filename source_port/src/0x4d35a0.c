// Car_DriveToPoint: ported from Pizza Connection 2 at 0x4d35a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d35a0
#include "pc2_port.h"

void __thiscall Car_DriveToPoint(void *self,int arg1,int arg2)

{
  DWORD DVar1;
  
                    /* Steps a car toward a point and advances its animation. */
  Object_TryStepToTile(*(void **)((intptr_t)self + 4),0,*(void **)((intptr_t)self + 8),arg1,arg2);
  DVar1 = timeGetTime();
  Object_UpdateWalkStep(*(void **)((intptr_t)self + 4),*(uint32_t **)((intptr_t)self + 8),DVar1);
  return;
}
