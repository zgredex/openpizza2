// BuildingProject_AdvanceStep: ported from Pizza Connection 2 at 0x503180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x503180
#include "pc2_port.h"

void __thiscall BuildingProject_AdvanceStep(void *self,int arg1,int arg2)

{
  void *this_00;
  uint32_t uvalue1;
  
                    /* Advances one step of an active building project. */
  if (((*(char *)((intptr_t)self + 0x60) != '\0') && (arg1 == *(int *)((intptr_t)self + 0x48))) &&
     (arg2 < *(int *)((intptr_t)self + 0x7c))) {
    this_00 = (void *)(DAT_0057c670 + 0x304);
    Sound_GetChannelObject(this_00,*(int *)((intptr_t)self + 100),1);
    uvalue1 = Random_RangeFast(0x13,0x1d);
    *(uint32_t *)((intptr_t)self + 0x5c) = uvalue1;
    *(uint8_t *)((intptr_t)self + 4) = 0;
    if ((*(int *)(DAT_0057c670 + 0x268) != 0) && (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
      Game_CloseSelectionDialog(DAT_0057c670);
    }
    if (*(char *)((intptr_t)self + 0x60) != '\0') {
      MissionGoal_ApplyFailureEffects((intptr_t)self);
      UI_Briefing_AddMessage
                (this_00,0x24,0,-1,-1,0,DAT_00581c14,(uint8_t *)s__s__s_005729bc,DAT_00582968);
      BuildingProject_ResetState((intptr_t)self);
    }
  }
  return;
}
