// AI_CheckBranchGuards: ported from Pizza Connection 2 at 0x4fe040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fe040
#include "pc2_port.h"

uint32_t __thiscall AI_CheckBranchGuards(void *self,int arg1)

{
  void *this_00;
  int value1;
  int value2;
  void *pvVar3;
  int value4;
  int value5;
  uint32_t uvalue6;
  int value7;
  int64_t lvalue8;
  int local_78;
  int local_6c;
  int *local_68;
  int local_60;
  int *local_5c;
  int local_50 [20];
  
                    /* Balances guards across a player's branches. */
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  value1 = Game_GetPlayerFieldC20((intptr_t)this_00);
  if (1 < value1) {
    value1 = *(int *)((intptr_t)this_00 + 100);
    if ((value1 < 3) && (value2 = Game_GetPlayerFieldC20((intptr_t)this_00), 0 < (value2 - value1) + -1)) {
      Game_UpgradeProductionLevel((intptr_t)this_00);
    }
    value1 = 0;
    local_6c = 0;
    value2 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
    value7 = 0;
    if (0 < value2) {
      do {
        pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value7);
        if ((pvVar3 != this_00) && (value4 = Game_GetPlayerFieldC20((intptr_t)this_00), value1 <= value4)) {
          value1 = Game_GetPlayerFieldC20((intptr_t)this_00);
          local_6c = value1;
        }
        value7 = value7 + 1;
      } while (value7 < value2);
      if (1 < value1) {
        value2 = 0;
        local_68 = (int *)0x0;
        local_60 = (intptr_t)*(short *)((intptr_t)self + arg1 * 0x168 + 0x130) / 0x28 + 1;
        if ((value1 == 5) && (local_60 < 2)) {
          local_60 = 2;
        }
        value7 = *(int *)((intptr_t)this_00 + 0x15c);
        local_78 = 0;
        if (0 < value7) {
          local_5c = local_50;
          do {
            value1 = IDMap_Lookup((void *)((intptr_t)this_00 + 0x148),local_78,(int *)0x0);
            value4 = 0;
            value2 = 0;
            uvalue6 = (uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10);
            do {
              uvalue6 = uvalue6 - 1;
              if ((intptr_t)uvalue6 < 0) break;
              Stats_SumFilteredFloats(value1,-1,-1,uvalue6);
              value4 = value4 + 1;
              value2 = value2 + 1;
            } while (value2 < 4);
            if (value4 < 1) {
              value1 = 1;
            }
            else {
              lvalue8 = __ftol();
              value1 = (intptr_t)lvalue8 + 1;
              if (local_60 < value1) {
                value1 = local_60;
              }
            }
            value2 = (intptr_t)local_68 + value1;
            *local_5c = value1;
            local_5c = local_5c + 1;
            local_78 = local_78 + 1;
            local_68 = (int *)value2;
          } while (local_78 < value7);
          value1 = local_6c;
        }
        value7 = 0;
        if (value1 == 5) {
          value7 = 2;
        }
        else if (value1 == 6) {
          value7 = 4;
        }
        value1 = Game_CountActiveObjectsByType(this_00,0x17);
        while ((value1 < value2 + value7 && (value4 = Company_HireFreeGuard(this_00), value4 != 0))) {
          value1 = value1 + 1;
        }
        value1 = *(int *)((intptr_t)this_00 + 0x15c);
        local_78 = 0;
        if (0 < value1) {
          local_68 = local_50;
          do {
            value4 = IDMap_Lookup((void *)((intptr_t)this_00 + 0x148),local_78,(int *)0x0);
            value2 = *local_68;
            value5 = Game_CountObjectsForOwner(this_00,value4,0x17);
            value7 = value5 - value2;
            if (value2 < value5) {
              do {
                value7 = Company_AssignStaffToBranch(this_00,value4);
                if (value7 == 0) break;
                value5 = value5 + -1;
              } while (value2 < value5);
              value7 = value5 - value2;
            }
            if (SBORROW4(value5,value2) != value7 < 0) {
              do {
                value7 = Company_DispatchWorkerToBranch((intptr_t)this_00,value4);
                if (value7 == 0) break;
                value5 = value5 + 1;
              } while (value5 < value2);
            }
            local_78 = local_78 + 1;
            local_68 = local_68 + 1;
          } while (local_78 < value1);
        }
        if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
          UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18610,0x23,0);
        }
      }
    }
  }
  return 1;
}
