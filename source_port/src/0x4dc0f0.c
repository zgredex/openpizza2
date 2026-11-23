// Company_PlaceScenarioBranches: ported from Pizza Connection 2 at 0x4dc0f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc0f0
#include "pc2_port.h"


void __thiscall Company_PlaceScenarioBranches(void *self,int arg1)

{
  void *this_00;
  int value1;
  int value2;
  uint32_t *uptr3;
  
                    /* Creates the scenario-assigned branches for a company. */
  this_00 = *(void **)(DAT_0057c670 + 0x90);
  value1 = *(int *)(arg1 + 0x4c);
  if ((0 < DAT_0057bb30) && ((char)DAT_0057bb34 != '\0')) {
    Company_EnsureRequiredBranch(arg1,self,DAT_0057bb30);
  }
  if (DAT_0057bb20 == '\0') {
    value2 = 0;
    if (0 < *(int *)((intptr_t)self + 0x364)) {
      uptr3 = (uint32_t *)((intptr_t)self + 0x370);
      do {
        if (uptr3[-2] == value1) {
          Company_OpenStartingBranch(this_00,value1,uptr3[-1],uptr3[1],(void *)*uptr3);
        }
        value2 = value2 + 1;
        uptr3 = uptr3 + 4;
      } while (value2 < *(int *)((intptr_t)self + 0x364));
    }
  }
  else if (((uint8_t)((DAT_0057bb3c) >> 8)) != '\0') {
    Company_OpenStartingBranch(this_00,value1,0,0,(void *)0xffffffff);
    return;
  }
  return;
}
