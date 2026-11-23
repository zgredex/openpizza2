// MissionGoal_HandleEvent: ported from Pizza Connection 2 at 0x502f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502f10
#include "pc2_port.h"

void __thiscall MissionGoal_HandleEvent(void *self,int arg1,int arg2,int arg3)

{
  void *this_00;
  uint32_t uvalue1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  
                    /* Handles events for a player's active mission goal and completes it when
                       matched. */
  if ((arg1 < 0) || (arg1 == *(int *)((intptr_t)self + 0x48))) {
    this_00 = (void *)(DAT_0057c670 + 0x304);
    if (arg3 == -1) {
      if ((*(char *)((intptr_t)self + 0x60) != '\0') &&
         (value4 = *(int *)((intptr_t)self + 0x48), *(int *)((intptr_t)self + 8) == value4)) {
        if ((value4 == 0x14) || (value4 == 0x17)) {
          value4 = *(int *)((intptr_t)self + 0x84) - arg2;
          *(int *)((intptr_t)self + 0x84) = value4;
          if (0 < value4) {
            return;
          }
        }
        else {
          value4 = *(int *)((intptr_t)self + 0x7c);
          if (arg2 != -1) {
            value5 = 0;
            if (0 < value4) {
              do {
                value2 = IDMap_Lookup((void *)((intptr_t)self + 0x68),value5,(int *)0x0);
                if (value2 == arg2) break;
                value5 = value5 + 1;
              } while (value5 < value4);
            }
            if (value5 == value4) {
              return;
            }
          }
          uvalue3 = Game_HasBuildingForPlayer((intptr_t)self);
          if ((char)uvalue3 == '\0') {
            return;
          }
          value5 = *(int *)((intptr_t)self + 0x84);
          if (0 < value5) {
            if (*(int *)((intptr_t)self + 0x48) == 0x23) {
              if (value5 < value4) {
                Sound_GetChannelObject(this_00,*(int *)((intptr_t)self + 100),1);
                uvalue1 = Random_RangeFast(0x13,0x1d);
                *(uint32_t *)((intptr_t)self + 0x5c) = uvalue1;
                *(uint8_t *)((intptr_t)self + 4) = 0;
                if ((*(int *)(DAT_0057c670 + 0x268) != 0) &&
                   (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
                  Game_CloseSelectionDialog(DAT_0057c670);
                }
                MissionGoal_ApplyFailureEffects((intptr_t)self);
                UI_Briefing_AddMessage
                          (this_00,0x24,0,-1,-1,0,DAT_00581c14,(uint8_t *)s__s__s_005729bc,DAT_00582968
                          );
                BuildingProject_ResetState((intptr_t)self);
              }
            }
            else if (value4 < value5) {
              return;
            }
          }
        }
        MissionGoal_ApplyCompletionEffects((intptr_t)self);
        Sound_GetChannelObject(this_00,*(int *)((intptr_t)self + 100),1);
        uvalue1 = Random_RangeFast(0x13,0x1d);
        *(uint32_t *)((intptr_t)self + 0x5c) = uvalue1;
        UI_Briefing_AddMessage
                  (this_00,0x23,0,-1,-1,0,DAT_00582c08,(uint8_t *)s__s__s_005729bc,DAT_00581218);
        BuildingProject_ResetState((intptr_t)self);
        if ((*(int *)(DAT_0057c670 + 0x268) != 0) && (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
          Game_CloseSelectionDialog(DAT_0057c670);
        }
      }
    }
    else if (*(char *)((intptr_t)self + 0x60) != '\0') {
      MissionGoal_ApplyCompletionEffects((intptr_t)self);
      Sound_GetChannelObject(this_00,*(int *)((intptr_t)self + 100),1);
      uvalue1 = Random_RangeFast(0x13,0x1d);
      *(uint32_t *)((intptr_t)self + 0x5c) = uvalue1;
      UI_Briefing_AddMessage
                (this_00,0x23,0,-1,-1,0,DAT_00582c08,(uint8_t *)s__s__s_005729bc,DAT_00581218);
      BuildingProject_ResetState((intptr_t)self);
      if ((*(int *)(DAT_0057c670 + 0x268) != 0) && (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
        Game_CloseSelectionDialog(DAT_0057c670);
        return;
      }
    }
  }
  return;
}
