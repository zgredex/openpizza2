// Player_MissionState_Tick: ported from Pizza Connection 2 at 0x50efe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50efe0
#include "pc2_port.h"


void __thiscall Player_MissionState_Tick(void *self,int arg1)

{
  void *this_00;
  uint32_t uvalue1;
  uint32_t uvalue2;
  void *pvVar3;
  int value4;
  int value5;
  uint32_t unaff_EBX;
  uint32_t unaff_EDI;
  bool flag6;
  int64_t lvalue7;
  uint8_t local_200 [512];
  
                    /* Ticks a player's mission goals, timers, and briefings. */
  this_00 = (void *)((intptr_t)DAT_0057c670 + 0x304);
  if (*(void **)((intptr_t)self + 0xac) != (void *)0x0) {
    Mission_TickGoalDeadline(*(void **)((intptr_t)self + 0xac),arg1);
  }
  if (*(void **)((intptr_t)self + 0xa8) != (void *)0x0) {
    MissionGoal_Evaluate(*(void **)((intptr_t)self + 0xa8),arg1);
    pvVar3 = *(void **)((intptr_t)self + 0xa8);
    if (*(char *)((intptr_t)pvVar3 + 4) == '\0') {
      value5 = *(int *)((intptr_t)self + 0xac);
      if (((*(char *)(value5 + 0xcc) == '\0') && (((uint16_t)((DAT_0057bb3c) >> 8)) == '\x01')) &&
         ((*(int *)(value5 + 0xd0) != 0 || (9 < *(int *)(value5 + 0xd4))))) {
        if (*(int *)((intptr_t)pvVar3 + 0x5c) == 0) {
          AI_InitActionPlan(pvVar3,0xffffffff,0xffffffff,-1,-1,-1,-1,-1);
          uvalue1 = UI_Briefing_AddPinnedMessage
                            (this_00,0x21,1,-1,-1,0,DAT_00580d60,DAT_00582e4c,unaff_EDI);
          *(uint32_t *)(*(int *)((intptr_t)self + 0xa8) + 100) = uvalue1;
          *(uint8_t *)(*(int *)((intptr_t)self + 0xa8) + 4) = 1;
        }
        else {
          value5 = *(int *)((intptr_t)pvVar3 + 0x5c) + -1;
          *(int *)((intptr_t)pvVar3 + 0x5c) = value5;
          if (value5 < 0) {
            *(uint32_t *)((intptr_t)pvVar3 + 0x5c) = 0;
          }
        }
      }
    }
    else {
      value5 = *(int *)((intptr_t)pvVar3 + 0x4c) + -1;
      *(int *)((intptr_t)pvVar3 + 0x4c) = value5;
      if (value5 == 0) {
        if (*(int *)(*(int *)((intptr_t)self + 0xa8) + 0x48) == 0x23) {
          UI_AppendCommandIfActive(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x23,-1);
          MissionGoal_HandleEvent(*(void **)((intptr_t)self + 0xa8),0x23,-1,-1);
        }
        else {
          Sound_GetChannelObject(this_00,*(int *)(*(int *)((intptr_t)self + 0xa8) + 100),1);
          *(uint8_t *)(*(int *)((intptr_t)self + 0xa8) + 4) = 0;
          if ((*(int *)((intptr_t)DAT_0057c670 + 0x268) != 0) &&
             (*(int *)((intptr_t)DAT_0057c670 + 0x278) == 0x11d7)) {
            Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
          }
          if (*(char *)(*(int *)((intptr_t)self + 0xa8) + 0x60) != '\0') {
            MissionGoal_ApplyFailureEffects(*(int *)((intptr_t)self + 0xa8));
            UI_Briefing_AddMessage
                      (this_00,0x24,0,-1,-1,0,DAT_00581c14,(uint8_t *)s__s__s_005729bc,DAT_00582968);
          }
          BuildingProject_ResetState(*(int *)((intptr_t)self + 0xa8));
          uvalue2 = Random_RangeFast(0x13,0x1d);
          *(uint32_t *)(*(int *)((intptr_t)self + 0xa8) + 0x5c) = uvalue2;
        }
      }
    }
  }
  pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 8));
  flag6 = pvVar3 == *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  if ((*(int *)((intptr_t)self + 0x6c) < 4) &&
     (value5 = *(int *)(&DAT_00573054 + *(int *)((intptr_t)self + 0x6c) * 4),
     value4 = Player_CountObjectsByType(pvVar3,0xffffffff), value5 <= value4)) {
    value5 = *(int *)((intptr_t)self + 0x6c) + 1;
    *(int *)((intptr_t)self + 0x54) = *(int *)((intptr_t)self + 0x54) + 1;
    *(int *)((intptr_t)self + 0x6c) = value5;
    String_Format(local_200,(uint8_t *)s__s__s_005729bc,*(uint32_t *)(&DAT_00583044 + value5 * 4));
    if (flag6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  if ((*(int *)((intptr_t)self + 0x70) < 4) &&
     (value5 = *(int *)(&DAT_00573064 + *(int *)((intptr_t)self + 0x70) * 4),
     value4 = Game_GetPlayerTotalValue((intptr_t)self), value5 <= value4)) {
    value5 = *(int *)((intptr_t)self + 0x70) + 1;
    *(int *)((intptr_t)self + 0x58) = *(int *)((intptr_t)self + 0x58) + 1;
    *(int *)((intptr_t)self + 0x70) = value5;
    String_Format(local_200,(uint8_t *)s__s__s_005729bc,*(uint32_t *)(&DAT_00583034 + value5 * 4));
    if (flag6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  value5 = *(int *)((intptr_t)self + 0x74);
  if ((value5 < 4) && (*(int *)(&DAT_00573074 + value5 * 4) <= *(int *)((intptr_t)self + 0xa0))) {
    *(int *)((intptr_t)self + 0x5c) = *(int *)((intptr_t)self + 0x5c) + 1;
    *(int *)((intptr_t)self + 0x74) = value5 + 1;
    String_Format(local_200,(uint8_t *)s__s__s_005729bc,
                  *(uint32_t *)(&DAT_00583004 + (value5 + 1) * 4));
    if (flag6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  value5 = *(int *)((intptr_t)self + 0x78);
  if ((value5 < 4) && (*(int *)(&DAT_00573084 + value5 * 4) <= *(int *)((intptr_t)pvVar3 + 0x15c))) {
    *(int *)((intptr_t)self + 0x60) = *(int *)((intptr_t)self + 0x60) + 1;
    *(int *)((intptr_t)self + 0x78) = value5 + 1;
    String_Format(local_200,(uint8_t *)s__s__s_005729bc,
                  *(uint32_t *)(&DAT_00582ff4 + (value5 + 1) * 4));
    if (flag6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  if (*(int *)((intptr_t)self + 0x7c) < 4) {
    value5 = *(int *)(&DAT_00573094 + *(int *)((intptr_t)self + 0x7c) * 4);
    Stats_SumRecordFloatsByType
              ((intptr_t)pvVar3,-1,(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
    lvalue7 = __ftol();
    if (value5 <= (intptr_t)lvalue7) {
      value5 = *(int *)((intptr_t)self + 0x7c) + 1;
      *(int *)((intptr_t)self + 100) = *(int *)((intptr_t)self + 100) + 1;
      *(int *)((intptr_t)self + 0x7c) = value5;
      String_Format(local_200,(uint8_t *)s__s__s_005729bc,*(uint32_t *)(&DAT_00583024 + value5 * 4));
      if (flag6) {
        UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
      }
    }
  }
  value5 = *(int *)((intptr_t)self + 0x80);
  if ((value5 < 4) && (*(int *)(&DAT_005730a4 + value5 * 4) <= *(int *)((intptr_t)self + 0x38))) {
    *(int *)((intptr_t)self + 0x68) = *(int *)((intptr_t)self + 0x68) + 1;
    *(int *)((intptr_t)self + 0x80) = value5 + 1;
    String_Format(local_200,(uint8_t *)s__s__s_005729bc,
                  *(uint32_t *)(&DAT_00583014 + (value5 + 1) * 4));
    if (flag6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EDI);
    }
  }
  return;
}
