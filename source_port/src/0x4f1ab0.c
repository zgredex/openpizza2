// Object_TryStepToTile: ported from Pizza Connection 2 at 0x4f1ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1ab0
#include "pc2_port.h"

uint32_t __thiscall
Object_TryStepToTile(void *self,int arg1,void *arg2,int arg3,int arg4)

{
  int value1;
  uint32_t uvalue2;
  void *this_00;
  
  uvalue2 = 1;
  if (*(short *)((intptr_t)arg2 + 0x28) == -1) {
    if (arg3 == arg4) {
      return 1;
    }
    value1 = Building_HasAdjacentTile(self,arg1,arg3,arg4);
    if (value1 != 0) {
      Object_SetShort28(arg2,0);
      this_00 = (void *)((intptr_t)arg2 + 0x14);
      Object_ClearField4((intptr_t)this_00);
      Array_Grow(this_00,arg3);
      Array_Grow(this_00,arg4);
      return 1;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0xc0));
    uvalue2 = AI_ComputeWeightedPath();
    LeaveCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0xc0));
  }
  return uvalue2;
}
